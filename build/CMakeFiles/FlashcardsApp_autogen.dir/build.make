# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/mauricio/miniconda3/lib/python3.8/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/mauricio/miniconda3/lib/python3.8/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/c/dev/flash/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/dev/flash/src/build

# Utility rule file for FlashcardsApp_autogen.

# Include any custom commands dependencies for this target.
include CMakeFiles/FlashcardsApp_autogen.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/FlashcardsApp_autogen.dir/progress.make

CMakeFiles/FlashcardsApp_autogen:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/mnt/c/dev/flash/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Automatic MOC and UIC for target FlashcardsApp"
	/home/mauricio/miniconda3/lib/python3.8/site-packages/cmake/data/bin/cmake -E cmake_autogen /mnt/c/dev/flash/src/build/CMakeFiles/FlashcardsApp_autogen.dir/AutogenInfo.json ""

FlashcardsApp_autogen: CMakeFiles/FlashcardsApp_autogen
FlashcardsApp_autogen: CMakeFiles/FlashcardsApp_autogen.dir/build.make
.PHONY : FlashcardsApp_autogen

# Rule to build all files generated by this target.
CMakeFiles/FlashcardsApp_autogen.dir/build: FlashcardsApp_autogen
.PHONY : CMakeFiles/FlashcardsApp_autogen.dir/build

CMakeFiles/FlashcardsApp_autogen.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FlashcardsApp_autogen.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FlashcardsApp_autogen.dir/clean

CMakeFiles/FlashcardsApp_autogen.dir/depend:
	cd /mnt/c/dev/flash/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/c/dev/flash/src /mnt/c/dev/flash/src /mnt/c/dev/flash/src/build /mnt/c/dev/flash/src/build /mnt/c/dev/flash/src/build/CMakeFiles/FlashcardsApp_autogen.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FlashcardsApp_autogen.dir/depend

