# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list

# Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/den/Allocator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/den/Allocator

# Include any dependencies generated for this target.
include CMakeFiles/test2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/test2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test2.dir/flags.make

test2.cpp: src/heap.cpp
test2.cpp: src/mm.cpp
test2.cpp: src/thread_safe_mm.cpp
test2.cpp: tests/test2.h
	$(CMAKE_COMMAND) -E cmake_progress_report /home/den/Allocator/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold "Generating test2.cpp"
	/usr/bin/python /usr/bin/cxxtestgen --error-printer -o /home/den/Allocator/test2.cpp ./src/heap.cpp ./src/mm.cpp ./src/thread_safe_mm.cpp ./tests/test2.h

CMakeFiles/test2.dir/test2.cpp.o: CMakeFiles/test2.dir/flags.make
CMakeFiles/test2.dir/test2.cpp.o: test2.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/den/Allocator/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test2.dir/test2.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test2.dir/test2.cpp.o -c /home/den/Allocator/test2.cpp

CMakeFiles/test2.dir/test2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test2.dir/test2.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/den/Allocator/test2.cpp > CMakeFiles/test2.dir/test2.cpp.i

CMakeFiles/test2.dir/test2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test2.dir/test2.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/den/Allocator/test2.cpp -o CMakeFiles/test2.dir/test2.cpp.s

CMakeFiles/test2.dir/test2.cpp.o.requires:
.PHONY : CMakeFiles/test2.dir/test2.cpp.o.requires

CMakeFiles/test2.dir/test2.cpp.o.provides: CMakeFiles/test2.dir/test2.cpp.o.requires
	$(MAKE) -f CMakeFiles/test2.dir/build.make CMakeFiles/test2.dir/test2.cpp.o.provides.build
.PHONY : CMakeFiles/test2.dir/test2.cpp.o.provides

CMakeFiles/test2.dir/test2.cpp.o.provides.build: CMakeFiles/test2.dir/test2.cpp.o

CMakeFiles/test2.dir/src/heap.cpp.o: CMakeFiles/test2.dir/flags.make
CMakeFiles/test2.dir/src/heap.cpp.o: src/heap.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/den/Allocator/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test2.dir/src/heap.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test2.dir/src/heap.cpp.o -c /home/den/Allocator/src/heap.cpp

CMakeFiles/test2.dir/src/heap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test2.dir/src/heap.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/den/Allocator/src/heap.cpp > CMakeFiles/test2.dir/src/heap.cpp.i

CMakeFiles/test2.dir/src/heap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test2.dir/src/heap.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/den/Allocator/src/heap.cpp -o CMakeFiles/test2.dir/src/heap.cpp.s

CMakeFiles/test2.dir/src/heap.cpp.o.requires:
.PHONY : CMakeFiles/test2.dir/src/heap.cpp.o.requires

CMakeFiles/test2.dir/src/heap.cpp.o.provides: CMakeFiles/test2.dir/src/heap.cpp.o.requires
	$(MAKE) -f CMakeFiles/test2.dir/build.make CMakeFiles/test2.dir/src/heap.cpp.o.provides.build
.PHONY : CMakeFiles/test2.dir/src/heap.cpp.o.provides

CMakeFiles/test2.dir/src/heap.cpp.o.provides.build: CMakeFiles/test2.dir/src/heap.cpp.o

CMakeFiles/test2.dir/src/mm.cpp.o: CMakeFiles/test2.dir/flags.make
CMakeFiles/test2.dir/src/mm.cpp.o: src/mm.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/den/Allocator/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test2.dir/src/mm.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test2.dir/src/mm.cpp.o -c /home/den/Allocator/src/mm.cpp

CMakeFiles/test2.dir/src/mm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test2.dir/src/mm.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/den/Allocator/src/mm.cpp > CMakeFiles/test2.dir/src/mm.cpp.i

CMakeFiles/test2.dir/src/mm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test2.dir/src/mm.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/den/Allocator/src/mm.cpp -o CMakeFiles/test2.dir/src/mm.cpp.s

CMakeFiles/test2.dir/src/mm.cpp.o.requires:
.PHONY : CMakeFiles/test2.dir/src/mm.cpp.o.requires

CMakeFiles/test2.dir/src/mm.cpp.o.provides: CMakeFiles/test2.dir/src/mm.cpp.o.requires
	$(MAKE) -f CMakeFiles/test2.dir/build.make CMakeFiles/test2.dir/src/mm.cpp.o.provides.build
.PHONY : CMakeFiles/test2.dir/src/mm.cpp.o.provides

CMakeFiles/test2.dir/src/mm.cpp.o.provides.build: CMakeFiles/test2.dir/src/mm.cpp.o

CMakeFiles/test2.dir/src/thread_safe_mm.cpp.o: CMakeFiles/test2.dir/flags.make
CMakeFiles/test2.dir/src/thread_safe_mm.cpp.o: src/thread_safe_mm.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/den/Allocator/CMakeFiles $(CMAKE_PROGRESS_5)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/test2.dir/src/thread_safe_mm.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/test2.dir/src/thread_safe_mm.cpp.o -c /home/den/Allocator/src/thread_safe_mm.cpp

CMakeFiles/test2.dir/src/thread_safe_mm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test2.dir/src/thread_safe_mm.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/den/Allocator/src/thread_safe_mm.cpp > CMakeFiles/test2.dir/src/thread_safe_mm.cpp.i

CMakeFiles/test2.dir/src/thread_safe_mm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test2.dir/src/thread_safe_mm.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/den/Allocator/src/thread_safe_mm.cpp -o CMakeFiles/test2.dir/src/thread_safe_mm.cpp.s

CMakeFiles/test2.dir/src/thread_safe_mm.cpp.o.requires:
.PHONY : CMakeFiles/test2.dir/src/thread_safe_mm.cpp.o.requires

CMakeFiles/test2.dir/src/thread_safe_mm.cpp.o.provides: CMakeFiles/test2.dir/src/thread_safe_mm.cpp.o.requires
	$(MAKE) -f CMakeFiles/test2.dir/build.make CMakeFiles/test2.dir/src/thread_safe_mm.cpp.o.provides.build
.PHONY : CMakeFiles/test2.dir/src/thread_safe_mm.cpp.o.provides

CMakeFiles/test2.dir/src/thread_safe_mm.cpp.o.provides.build: CMakeFiles/test2.dir/src/thread_safe_mm.cpp.o

# Object files for target test2
test2_OBJECTS = \
"CMakeFiles/test2.dir/test2.cpp.o" \
"CMakeFiles/test2.dir/src/heap.cpp.o" \
"CMakeFiles/test2.dir/src/mm.cpp.o" \
"CMakeFiles/test2.dir/src/thread_safe_mm.cpp.o"

# External object files for target test2
test2_EXTERNAL_OBJECTS =

test2: CMakeFiles/test2.dir/test2.cpp.o
test2: CMakeFiles/test2.dir/src/heap.cpp.o
test2: CMakeFiles/test2.dir/src/mm.cpp.o
test2: CMakeFiles/test2.dir/src/thread_safe_mm.cpp.o
test2: CMakeFiles/test2.dir/build.make
test2: CMakeFiles/test2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable test2"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/test2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test2.dir/build: test2
.PHONY : CMakeFiles/test2.dir/build

CMakeFiles/test2.dir/requires: CMakeFiles/test2.dir/test2.cpp.o.requires
CMakeFiles/test2.dir/requires: CMakeFiles/test2.dir/src/heap.cpp.o.requires
CMakeFiles/test2.dir/requires: CMakeFiles/test2.dir/src/mm.cpp.o.requires
CMakeFiles/test2.dir/requires: CMakeFiles/test2.dir/src/thread_safe_mm.cpp.o.requires
.PHONY : CMakeFiles/test2.dir/requires

CMakeFiles/test2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test2.dir/clean

CMakeFiles/test2.dir/depend: test2.cpp
	cd /home/den/Allocator && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/den/Allocator /home/den/Allocator /home/den/Allocator /home/den/Allocator /home/den/Allocator/CMakeFiles/test2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test2.dir/depend

