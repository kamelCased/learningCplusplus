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
CMAKE_SOURCE_DIR = /Users/kbgazzaz/Desktop/rhombus

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/kbgazzaz/Desktop/rhombus/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/rhombus.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/rhombus.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/rhombus.dir/flags.make

CMakeFiles/rhombus.dir/main.cpp.o: CMakeFiles/rhombus.dir/flags.make
CMakeFiles/rhombus.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/kbgazzaz/Desktop/rhombus/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/rhombus.dir/main.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/rhombus.dir/main.cpp.o -c /Users/kbgazzaz/Desktop/rhombus/main.cpp

CMakeFiles/rhombus.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/rhombus.dir/main.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/kbgazzaz/Desktop/rhombus/main.cpp > CMakeFiles/rhombus.dir/main.cpp.i

CMakeFiles/rhombus.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/rhombus.dir/main.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/kbgazzaz/Desktop/rhombus/main.cpp -o CMakeFiles/rhombus.dir/main.cpp.s

# Object files for target rhombus
rhombus_OBJECTS = \
"CMakeFiles/rhombus.dir/main.cpp.o"

# External object files for target rhombus
rhombus_EXTERNAL_OBJECTS =

rhombus: CMakeFiles/rhombus.dir/main.cpp.o
rhombus: CMakeFiles/rhombus.dir/build.make
rhombus: CMakeFiles/rhombus.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/kbgazzaz/Desktop/rhombus/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable rhombus"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/rhombus.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/rhombus.dir/build: rhombus

.PHONY : CMakeFiles/rhombus.dir/build

CMakeFiles/rhombus.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/rhombus.dir/cmake_clean.cmake
.PHONY : CMakeFiles/rhombus.dir/clean

CMakeFiles/rhombus.dir/depend:
	cd /Users/kbgazzaz/Desktop/rhombus/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/kbgazzaz/Desktop/rhombus /Users/kbgazzaz/Desktop/rhombus /Users/kbgazzaz/Desktop/rhombus/cmake-build-debug /Users/kbgazzaz/Desktop/rhombus/cmake-build-debug /Users/kbgazzaz/Desktop/rhombus/cmake-build-debug/CMakeFiles/rhombus.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/rhombus.dir/depend

