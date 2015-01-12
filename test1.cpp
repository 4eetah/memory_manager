/* Generated file, do not edit */

#ifndef CXXTEST_RUNNING
#define CXXTEST_RUNNING
#endif

#define _CXXTEST_HAVE_STD
#define _CXXTEST_HAVE_EH
#include <cxxtest/TestListener.h>
#include <cxxtest/TestTracker.h>
#include <cxxtest/TestRunner.h>
#include <cxxtest/RealDescriptions.h>
#include <cxxtest/TestMain.h>
#include <cxxtest/ErrorPrinter.h>

int main( int argc, char *argv[] ) {
 int status;
    CxxTest::ErrorPrinter tmp;
    CxxTest::RealWorldDescription::_worldName = "cxxtest";
    status = CxxTest::Main< CxxTest::ErrorPrinter >( tmp, argc, argv );
    return status;
}
bool suite_TestHeap_init = false;
#include "/home/den/Allocator/tests/test1.h"

static TestHeap suite_TestHeap;

static CxxTest::List Tests_TestHeap = { 0, 0 };
CxxTest::StaticSuiteDescription suiteDescription_TestHeap( "./tests/test1.h", 9, "TestHeap", suite_TestHeap, Tests_TestHeap );

static class TestDescription_suite_TestHeap_test_construction : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestHeap_test_construction() : CxxTest::RealTestDescription( Tests_TestHeap, suiteDescription_TestHeap, 21, "test_construction" ) {}
 void runTest() { suite_TestHeap.test_construction(); }
} testDescription_suite_TestHeap_test_construction;

static class TestDescription_suite_TestHeap_test_copy_construction : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestHeap_test_copy_construction() : CxxTest::RealTestDescription( Tests_TestHeap, suiteDescription_TestHeap, 31, "test_copy_construction" ) {}
 void runTest() { suite_TestHeap.test_copy_construction(); }
} testDescription_suite_TestHeap_test_copy_construction;

static class TestDescription_suite_TestHeap_test_move_construction : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestHeap_test_move_construction() : CxxTest::RealTestDescription( Tests_TestHeap, suiteDescription_TestHeap, 37, "test_move_construction" ) {}
 void runTest() { suite_TestHeap.test_move_construction(); }
} testDescription_suite_TestHeap_test_move_construction;

static class TestDescription_suite_TestHeap_test_mem_sbrk : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestHeap_test_mem_sbrk() : CxxTest::RealTestDescription( Tests_TestHeap, suiteDescription_TestHeap, 50, "test_mem_sbrk" ) {}
 void runTest() { suite_TestHeap.test_mem_sbrk(); }
} testDescription_suite_TestHeap_test_mem_sbrk;

static class TestDescription_suite_TestHeap_test_mem_heapsize : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestHeap_test_mem_heapsize() : CxxTest::RealTestDescription( Tests_TestHeap, suiteDescription_TestHeap, 57, "test_mem_heapsize" ) {}
 void runTest() { suite_TestHeap.test_mem_heapsize(); }
} testDescription_suite_TestHeap_test_mem_heapsize;

static class TestDescription_suite_TestHeap_test_searchFreeBlock : public CxxTest::RealTestDescription {
public:
 TestDescription_suite_TestHeap_test_searchFreeBlock() : CxxTest::RealTestDescription( Tests_TestHeap, suiteDescription_TestHeap, 66, "test_searchFreeBlock" ) {}
 void runTest() { suite_TestHeap.test_searchFreeBlock(); }
} testDescription_suite_TestHeap_test_searchFreeBlock;

#include <cxxtest/Root.cpp>
const char* CxxTest::RealWorldDescription::_worldName = "cxxtest";
