# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


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
CMAKE_SOURCE_DIR = /home/alfonsubuntu/桌面/programming/Algorithm_Spring_2017/HW1/algo_hw1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/alfonsubuntu/桌面/programming/Algorithm_Spring_2017/HW1/algo_hw1

# Include any dependencies generated for this target.
include CMakeFiles/algo_hw1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/algo_hw1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/algo_hw1.dir/flags.make

CMakeFiles/algo_hw1.dir/main.cpp.o: CMakeFiles/algo_hw1.dir/flags.make
CMakeFiles/algo_hw1.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/alfonsubuntu/桌面/programming/Algorithm_Spring_2017/HW1/algo_hw1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/algo_hw1.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/algo_hw1.dir/main.cpp.o -c /home/alfonsubuntu/桌面/programming/Algorithm_Spring_2017/HW1/algo_hw1/main.cpp

CMakeFiles/algo_hw1.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/algo_hw1.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/alfonsubuntu/桌面/programming/Algorithm_Spring_2017/HW1/algo_hw1/main.cpp > CMakeFiles/algo_hw1.dir/main.cpp.i

CMakeFiles/algo_hw1.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/algo_hw1.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/alfonsubuntu/桌面/programming/Algorithm_Spring_2017/HW1/algo_hw1/main.cpp -o CMakeFiles/algo_hw1.dir/main.cpp.s

CMakeFiles/algo_hw1.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/algo_hw1.dir/main.cpp.o.requires

CMakeFiles/algo_hw1.dir/main.cpp.o.provides: CMakeFiles/algo_hw1.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/algo_hw1.dir/build.make CMakeFiles/algo_hw1.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/algo_hw1.dir/main.cpp.o.provides

CMakeFiles/algo_hw1.dir/main.cpp.o.provides.build: CMakeFiles/algo_hw1.dir/main.cpp.o


# Object files for target algo_hw1
algo_hw1_OBJECTS = \
"CMakeFiles/algo_hw1.dir/main.cpp.o"

# External object files for target algo_hw1
algo_hw1_EXTERNAL_OBJECTS =

algo_hw1: CMakeFiles/algo_hw1.dir/main.cpp.o
algo_hw1: CMakeFiles/algo_hw1.dir/build.make
algo_hw1: CMakeFiles/algo_hw1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/alfonsubuntu/桌面/programming/Algorithm_Spring_2017/HW1/algo_hw1/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable algo_hw1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/algo_hw1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/algo_hw1.dir/build: algo_hw1

.PHONY : CMakeFiles/algo_hw1.dir/build

CMakeFiles/algo_hw1.dir/requires: CMakeFiles/algo_hw1.dir/main.cpp.o.requires

.PHONY : CMakeFiles/algo_hw1.dir/requires

CMakeFiles/algo_hw1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/algo_hw1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/algo_hw1.dir/clean

CMakeFiles/algo_hw1.dir/depend:
	cd /home/alfonsubuntu/桌面/programming/Algorithm_Spring_2017/HW1/algo_hw1 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/alfonsubuntu/桌面/programming/Algorithm_Spring_2017/HW1/algo_hw1 /home/alfonsubuntu/桌面/programming/Algorithm_Spring_2017/HW1/algo_hw1 /home/alfonsubuntu/桌面/programming/Algorithm_Spring_2017/HW1/algo_hw1 /home/alfonsubuntu/桌面/programming/Algorithm_Spring_2017/HW1/algo_hw1 /home/alfonsubuntu/桌面/programming/Algorithm_Spring_2017/HW1/algo_hw1/CMakeFiles/algo_hw1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/algo_hw1.dir/depend

