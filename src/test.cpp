#include <iostream>
#include <fstream>
#include <string>
#include <assert.h>
#include <ctime>
#include <thread>
#include <future>
#include <map>
#include <vector>
#include <algorithm>
#include <memory>
#include <mutex>
#include <chrono>
#include "mm.h"
#include "my_alloc.h"
#include "thread_safe_mm.h"

const int NUM_TRACEFILES = 9;

std::string tracefiles[] = {
    "amptjp-bal.rep",\
    "cccp-bal.rep",\
    "cp-decl-bal.rep",\
    "expr-bal.rep",\
    "coalescing-bal.rep",\
    "random-bal.rep",\
    "random2-bal.rep",\
    "binary-bal.rep",\
    "binary2-bal.rep"
};
std::string tracedir = "../traces/";

struct traceop_t {
    enum {ALLOC, FREE} type;          /* type of request */
    int index;                        /* index for deallocate to use later */
    int size;                         /* byte size of allocate request */
};

/* Holds the information for one trace file*/
struct trace_t {
    int sugg_heapsize;   /* suggested heap size (unused here, will be used for farther testing) */
    int num_ids;         /* number of alloc ids */
    int num_ops;         /* number of distinct requests */
    int weight;          /* weight for this trace (unused here, will be used for farther testing) */
    traceop_t *ops;      /* array of requests */
    void **blocks;       /* array of ptrs returned by alloc... */
    size_t *block_sizes; /* ... and a corresponding array of payload sizes */
};

/* variables for testing allocator speed */
MemoryManager mm;
trace_t * read_trace(std::string & tracedir, std::string & filename);
void eval_mm_speed(trace_t *trace);
void eval_new_speed(trace_t *trace);
void free_trace(trace_t *trace);

typedef void (*test_func)(trace_t *trace);
void eval_package_speed(test_func);

/* variable for testing custom allocator for stl */
void test_stl_custom_alloc();

/* variables for testing threadsafe allocator */
std::mutex mtx;
std::condition_variable cvar;
bool start = false;
std::vector<void*> v;
void test_thread_safe_alloc_free();

/* wrapper for testing multiple threads on heap */
class thread_safe_mm_wrapper {
    static ThreadSafeMM tm;
    void * ptr;
public:
    thread_safe_mm_wrapper(size_t n) {
        ptr = tm.allocate(n);
        std::cout << "-------------------------------------------------------------------------";
        tm.checkHeap();
        std::this_thread::sleep_for(std::chrono::milliseconds(rand() % 1000)); // to avoid alloc, dealloc operations
    }                                                                          // run sequentially
    ~thread_safe_mm_wrapper() {
        tm.deallocate(ptr);
        std::cout << "-------------------------------------------------------------------------";
        tm.checkHeap();
    }
};
ThreadSafeMM thread_safe_mm_wrapper::tm;

/**********************************************************
 * Main function
 * ********************************************************/
int main()
{
/* Testing mm package running time */
    std::cout << "<< Run speed test >>\n";
    std::cout << "<------------------------------------------------>\n";
    std::thread evalThread([] {
        std::cout << "new package evaluation\n";
        eval_package_speed(eval_new_speed);
        std::cout << "\nmm package evaluation\n";
        eval_package_speed(eval_mm_speed);
    });
    evalThread.join();
    std::cout << "\nComplete.\n\n";

/* Test STL custom allocator using map */
    std::cout << "<< Run STL custom allocator test with map >>\n";
    std::cout << "<------------------------------------------------>\n";
    std::thread testAlloc(test_stl_custom_alloc);
    testAlloc.join();
    std::cout << "Complete.\n";

/* Running ten threads simulataneously on heap */
    std::cout << "\n<< Run ten threads simulataneously on heap >>\n";
    std::cout << "<------------------------------------------------>\n";
    int threadNum = 10;
    std::cout << "Listing of " << threadNum << " threads allocate, deallocate operations\n";
    std::cout << "Warning! In some cases listing can overlap\n";
    std::vector<std::thread> tvec;
    for(int i = 0; i < threadNum; i++) {
        std::thread th(test_thread_safe_alloc_free);
        tvec.push_back(move(th));
    }

    for (std::thread & th : tvec) {
        if (th.joinable())
            th.join();
    }
    std::cout << "Complete.\n";
    return 0;
}

/******************************************************************/

/* Test thread safe ThreadSafeMM allocator
 */
void test_thread_safe_alloc_free() {
    size_t maxBytes = 100000;
    thread_safe_mm_wrapper ob(rand() % maxBytes);
}

void test_stl_custom_alloc() {
    std::ifstream fIn;
    std::string mapInput = "../mapInput.txt";
    fIn.open(mapInput);
    if (!fIn.is_open()) {
        std::cout << "Couldn't open " << mapInput << " file.\n";
        exit(1);
    }
    std::map<std::string, int, std::less<std::string>, MyAlloc<std::pair<std::string, int>>> tree;
    std::string key;
    int value;
    while (fIn >> key >> value) {
        fIn.get();
        tree[key] = value;
    }
    for (auto & p : tree) {
        std::cout << p.first << ": " << p.second << std::endl;
    }
}

/*
 * eval_packages_speed() - Run tests on
 * mm package and new package as well
 * and is used as an input to gprof profiler to
 * measure the running time.
 */
void eval_package_speed(test_func) {
    trace_t * trace = new trace_t;
    auto start = clock();
    for (int i = 0; i < NUM_TRACEFILES; i++) {
        trace = read_trace(tracedir, tracefiles[i]);
        test_func(trace);
    }
    auto end = clock();
    free_trace(trace);
    std::cout << "Running time = " << double(end - start) / CLOCKS_PER_SEC << " sec\n";
}

/*
 * eval_mm_speed - measure the running time of the
 * mm package on the set of traces. 
 */
void eval_mm_speed(trace_t * trace)
{
    int index, size;
    void *p, *block;

    /* Reset the heap and initialize the mm package */
    mm.reset();
    mm.initialize();
    /* Interpret each trace request */
    for (int i = 0;  i < trace->num_ops;  i++) {
        switch (trace->ops[i].type) {
            case traceop_t::ALLOC:
                index = trace->ops[i].index;
                size = trace->ops[i].size;
                p = mm.allocate(size);
                trace->blocks[index] = p;
                break;

            case traceop_t::FREE:
                index = trace->ops[i].index;
                block = trace->blocks[index];
                mm.deallocate(block);
                break;
            }
    }
}

/*
 * eval_new_speed - measure the running time of the
 * new package on the set of traces.
 */
void eval_new_speed(trace_t * trace) {

    int index, size;
    void *p, *block;

    for (int i = 0;  i < trace->num_ops;  i++) {
        switch (trace->ops[i].type) {
            case traceop_t::ALLOC:
                index = trace->ops[i].index;
                size = trace->ops[i].size;
                p = ::operator new[](size);
                trace->blocks[index] = p;
                break;

            case traceop_t::FREE:
                index = trace->ops[i].index;
                block = trace->blocks[index];
                ::operator delete[](block);
            break;
        }
    }
}

/*
 * read_trace - read a trace file and store it in memory
 */
trace_t * read_trace(std::string & tracedir, std::string & filename) {
    std::ifstream tracefile;
    trace_t *trace = new trace_t;
    std::string path;

    /* Read the trace file header */
    path = tracedir;
    path.append(filename);
    tracefile.open(path);
    if (!tracefile.is_open()) {
        std::cout << "Could not open " << path << " in read_trace\n";
        exit(1);
    }

    tracefile >> trace->sugg_heapsize;
    tracefile >> trace->num_ids;
    tracefile >> trace->num_ops;
    tracefile >> trace->weight;
    tracefile.get();
    /* Store each request line in the trace in this array */
    trace->ops = new traceop_t[trace->num_ops];
    trace->blocks = new void*[trace->num_ids];
    trace->block_sizes = new size_t[trace->num_ids];

    /* read every request line in the trace file */
    int size;
    int max_index = 0;
    int index = 0;
    int op_index = 0;
    char type;
    while (tracefile >> type) {
        switch(type) {
            case 'a':
                (tracefile >> index >> size).get();
                trace->ops[op_index].type = traceop_t::ALLOC;
                trace->ops[op_index].index = index;
                trace->ops[op_index].size = size;
                max_index = (index > max_index) ? index : max_index;
                break;
            case 'f':
                (tracefile >> index).get();
                trace->ops[op_index].type = traceop_t::FREE;
                trace->ops[op_index].index = index;
                break;
            default:
                std::cerr << "Wrong character " << type << " in tracefile " << path << std::endl;
                exit(1);
        }
        op_index++;
    }
    tracefile.close();

    assert(max_index == trace->num_ids - 1);
    assert(trace->num_ops == op_index);

    return trace;
}

/* Deallocate trace structure */
void free_trace(trace_t *trace) {
    delete[] trace->ops;
    delete[] trace->blocks;
    delete[] trace->block_sizes;
    delete[] trace;
}
