# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Disable VCS-based implicit rules.
% : %,v


# Disable VCS-based implicit rules.
% : RCS/%


# Disable VCS-based implicit rules.
% : RCS/%,v


# Disable VCS-based implicit rules.
% : SCCS/s.%


# Disable VCS-based implicit rules.
% : s.%


.SUFFIXES: .hpux_make_needs_suffix_list


# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/kbgazzaz/Desktop/kg1828_q1to10

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kbgazzaz/Desktop/kg1828_q1to10/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/kg1828_q1to10.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/kg1828_q1to10.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/kg1828_q1to10.dir/flags.make

CMakeFiles/kg1828_q1to10.dir/main.cpp.o: CMakeFiles/kg1828_q1to10.dir/flags.make
CMakeFiles/kg1828_q1to10.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kbgazzaz/Desktop/kg1828_q1to10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/kg1828_q1to10.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/kg1828_q1to10.dir/main.cpp.o -c /Users/kbgazzaz/Desktop/kg1828_q1to10/main.cpp

CMakeFiles/kg1828_q1to10.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/kg1828_q1to10.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kbgazzaz/Desktop/kg1828_q1to10/main.cpp > CMakeFiles/kg1828_q1to10.dir/main.cpp.i

CMakeFiles/kg1828_q1to10.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/kg1828_q1to10.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kbgazzaz/Desktop/kg1828_q1to10/main.cpp -o CMakeFiles/kg1828_q1to10.dir/main.cpp.s

# Object files for target kg1828_q1to10
kg1828_q1to10_OBJECTS = \
"CMakeFiles/kg1828_q1to10.dir/main.cpp.o"

# External object files for target kg1828_q1to10
kg1828_q1to10_EXTERNAL_OBJECTS =

kg1828_q1to10: CMakeFiles/kg1828_q1to10.dir/main.cpp.o
kg1828_q1to10: CMakeFiles/kg1828_q1to10.dir/build.make
kg1828_q1to10: CMakeFiles/kg1828_q1to10.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kbgazzaz/Desktop/kg1828_q1to10/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable kg1828_q1to10"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/kg1828_q1to10.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/kg1828_q1to10.dir/build: kg1828_q1to10

.PHONY : CMakeFiles/kg1828_q1to10.dir/build

CMakeFiles/kg1828_q1to10.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/kg1828_q1to10.dir/cmake_clean.cmake
.PHONY : CMakeFiles/kg1828_q1to10.dir/clean

CMakeFiles/kg1828_q1to10.dir/depend:
	cd /Users/kbgazzaz/Desktop/kg1828_q1to10/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kbgazzaz/Desktop/kg1828_q1to10 /Users/kbgazzaz/Desktop/kg1828_q1to10 /Users/kbgazzaz/Desktop/kg1828_q1to10/cmake-build-debug /Users/kbgazzaz/Desktop/kg1828_q1to10/cmake-build-debug /Users/kbgazzaz/Desktop/kg1828_q1to10/cmake-build-debug/CMakeFiles/kg1828_q1to10.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/kg1828_q1to10.dir/depend

