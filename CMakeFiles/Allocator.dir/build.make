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
include CMakeFiles/Allocator.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Allocator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Allocator.dir/flags.make

CMakeFiles/Allocator.dir/src/heap.cpp.o: CMakeFiles/Allocator.dir/flags.make
CMakeFiles/Allocator.dir/src/heap.cpp.o: src/heap.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/den/Allocator/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Allocator.dir/src/heap.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Allocator.dir/src/heap.cpp.o -c /home/den/Allocator/src/heap.cpp

CMakeFiles/Allocator.dir/src/heap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Allocator.dir/src/heap.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/den/Allocator/src/heap.cpp > CMakeFiles/Allocator.dir/src/heap.cpp.i

CMakeFiles/Allocator.dir/src/heap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Allocator.dir/src/heap.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/den/Allocator/src/heap.cpp -o CMakeFiles/Allocator.dir/src/heap.cpp.s

CMakeFiles/Allocator.dir/src/heap.cpp.o.requires:
.PHONY : CMakeFiles/Allocator.dir/src/heap.cpp.o.requires

CMakeFiles/Allocator.dir/src/heap.cpp.o.provides: CMakeFiles/Allocator.dir/src/heap.cpp.o.requires
	$(MAKE) -f CMakeFiles/Allocator.dir/build.make CMakeFiles/Allocator.dir/src/heap.cpp.o.provides.build
.PHONY : CMakeFiles/Allocator.dir/src/heap.cpp.o.provides

CMakeFiles/Allocator.dir/src/heap.cpp.o.provides.build: CMakeFiles/Allocator.dir/src/heap.cpp.o

CMakeFiles/Allocator.dir/src/mm.cpp.o: CMakeFiles/Allocator.dir/flags.make
CMakeFiles/Allocator.dir/src/mm.cpp.o: src/mm.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/den/Allocator/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Allocator.dir/src/mm.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Allocator.dir/src/mm.cpp.o -c /home/den/Allocator/src/mm.cpp

CMakeFiles/Allocator.dir/src/mm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Allocator.dir/src/mm.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/den/Allocator/src/mm.cpp > CMakeFiles/Allocator.dir/src/mm.cpp.i

CMakeFiles/Allocator.dir/src/mm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Allocator.dir/src/mm.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/den/Allocator/src/mm.cpp -o CMakeFiles/Allocator.dir/src/mm.cpp.s

CMakeFiles/Allocator.dir/src/mm.cpp.o.requires:
.PHONY : CMakeFiles/Allocator.dir/src/mm.cpp.o.requires

CMakeFiles/Allocator.dir/src/mm.cpp.o.provides: CMakeFiles/Allocator.dir/src/mm.cpp.o.requires
	$(MAKE) -f CMakeFiles/Allocator.dir/build.make CMakeFiles/Allocator.dir/src/mm.cpp.o.provides.build
.PHONY : CMakeFiles/Allocator.dir/src/mm.cpp.o.provides

CMakeFiles/Allocator.dir/src/mm.cpp.o.provides.build: CMakeFiles/Allocator.dir/src/mm.cpp.o

CMakeFiles/Allocator.dir/src/thread_safe_mm.cpp.o: CMakeFiles/Allocator.dir/flags.make
CMakeFiles/Allocator.dir/src/thread_safe_mm.cpp.o: src/thread_safe_mm.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/den/Allocator/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Allocator.dir/src/thread_safe_mm.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Allocator.dir/src/thread_safe_mm.cpp.o -c /home/den/Allocator/src/thread_safe_mm.cpp

CMakeFiles/Allocator.dir/src/thread_safe_mm.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Allocator.dir/src/thread_safe_mm.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/den/Allocator/src/thread_safe_mm.cpp > CMakeFiles/Allocator.dir/src/thread_safe_mm.cpp.i

CMakeFiles/Allocator.dir/src/thread_safe_mm.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Allocator.dir/src/thread_safe_mm.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/den/Allocator/src/thread_safe_mm.cpp -o CMakeFiles/Allocator.dir/src/thread_safe_mm.cpp.s

CMakeFiles/Allocator.dir/src/thread_safe_mm.cpp.o.requires:
.PHONY : CMakeFiles/Allocator.dir/src/thread_safe_mm.cpp.o.requires

CMakeFiles/Allocator.dir/src/thread_safe_mm.cpp.o.provides: CMakeFiles/Allocator.dir/src/thread_safe_mm.cpp.o.requires
	$(MAKE) -f CMakeFiles/Allocator.dir/build.make CMakeFiles/Allocator.dir/src/thread_safe_mm.cpp.o.provides.build
.PHONY : CMakeFiles/Allocator.dir/src/thread_safe_mm.cpp.o.provides

CMakeFiles/Allocator.dir/src/thread_safe_mm.cpp.o.provides.build: CMakeFiles/Allocator.dir/src/thread_safe_mm.cpp.o

CMakeFiles/Allocator.dir/src/main.cpp.o: CMakeFiles/Allocator.dir/flags.make
CMakeFiles/Allocator.dir/src/main.cpp.o: src/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/den/Allocator/CMakeFiles $(CMAKE_PROGRESS_4)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/Allocator.dir/src/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/Allocator.dir/src/main.cpp.o -c /home/den/Allocator/src/main.cpp

CMakeFiles/Allocator.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Allocator.dir/src/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/den/Allocator/src/main.cpp > CMakeFiles/Allocator.dir/src/main.cpp.i

CMakeFiles/Allocator.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Allocator.dir/src/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/den/Allocator/src/main.cpp -o CMakeFiles/Allocator.dir/src/main.cpp.s

CMakeFiles/Allocator.dir/src/main.cpp.o.requires:
.PHONY : CMakeFiles/Allocator.dir/src/main.cpp.o.requires

CMakeFiles/Allocator.dir/src/main.cpp.o.provides: CMakeFiles/Allocator.dir/src/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Allocator.dir/build.make CMakeFiles/Allocator.dir/src/main.cpp.o.provides.build
.PHONY : CMakeFiles/Allocator.dir/src/main.cpp.o.provides

CMakeFiles/Allocator.dir/src/main.cpp.o.provides.build: CMakeFiles/Allocator.dir/src/main.cpp.o

# Object files for target Allocator
Allocator_OBJECTS = \
"CMakeFiles/Allocator.dir/src/heap.cpp.o" \
"CMakeFiles/Allocator.dir/src/mm.cpp.o" \
"CMakeFiles/Allocator.dir/src/thread_safe_mm.cpp.o" \
"CMakeFiles/Allocator.dir/src/main.cpp.o"

# External object files for target Allocator
Allocator_EXTERNAL_OBJECTS =

Allocator: CMakeFiles/Allocator.dir/src/heap.cpp.o
Allocator: CMakeFiles/Allocator.dir/src/mm.cpp.o
Allocator: CMakeFiles/Allocator.dir/src/thread_safe_mm.cpp.o
Allocator: CMakeFiles/Allocator.dir/src/main.cpp.o
Allocator: CMakeFiles/Allocator.dir/build.make
Allocator: CMakeFiles/Allocator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable Allocator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Allocator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Allocator.dir/build: Allocator
.PHONY : CMakeFiles/Allocator.dir/build

CMakeFiles/Allocator.dir/requires: CMakeFiles/Allocator.dir/src/heap.cpp.o.requires
CMakeFiles/Allocator.dir/requires: CMakeFiles/Allocator.dir/src/mm.cpp.o.requires
CMakeFiles/Allocator.dir/requires: CMakeFiles/Allocator.dir/src/thread_safe_mm.cpp.o.requires
CMakeFiles/Allocator.dir/requires: CMakeFiles/Allocator.dir/src/main.cpp.o.requires
.PHONY : CMakeFiles/Allocator.dir/requires

CMakeFiles/Allocator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Allocator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Allocator.dir/clean

CMakeFiles/Allocator.dir/depend:
	cd /home/den/Allocator && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/den/Allocator /home/den/Allocator /home/den/Allocator /home/den/Allocator /home/den/Allocator/CMakeFiles/Allocator.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Allocator.dir/depend

