# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.27.7/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.27.7/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/tpn/Documents/_basic_projects/test-app

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/tpn/Documents/_basic_projects/test-app/build

# Utility rule file for apptest-app_automoc_json_extraction.

# Include any custom commands dependencies for this target.
include CMakeFiles/apptest-app_automoc_json_extraction.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/apptest-app_automoc_json_extraction.dir/progress.make

CMakeFiles/apptest-app_automoc_json_extraction: /Users/tpn/Qt/6.5.2/macos/./libexec/cmake_automoc_parser
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --blue --bold --progress-dir=/Users/tpn/Documents/_basic_projects/test-app/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Running AUTOMOC file extraction for target apptest-app"
	/Users/tpn/Qt/6.5.2/macos/libexec/cmake_automoc_parser --cmake-autogen-cache-file /Users/tpn/Documents/_basic_projects/test-app/build/CMakeFiles/apptest-app_autogen.dir/ParseCache.txt --cmake-autogen-info-file /Users/tpn/Documents/_basic_projects/test-app/build/CMakeFiles/apptest-app_autogen.dir/AutogenInfo.json --output-file-path /Users/tpn/Documents/_basic_projects/test-app/build/meta_types/apptest-app_json_file_list.txt --timestamp-file-path /Users/tpn/Documents/_basic_projects/test-app/build/meta_types/apptest-app_json_file_list.txt.timestamp --cmake-autogen-include-dir-path /Users/tpn/Documents/_basic_projects/test-app/build/apptest-app_autogen/include

apptest-app_automoc_json_extraction: CMakeFiles/apptest-app_automoc_json_extraction
apptest-app_automoc_json_extraction: CMakeFiles/apptest-app_automoc_json_extraction.dir/build.make
.PHONY : apptest-app_automoc_json_extraction

# Rule to build all files generated by this target.
CMakeFiles/apptest-app_automoc_json_extraction.dir/build: apptest-app_automoc_json_extraction
.PHONY : CMakeFiles/apptest-app_automoc_json_extraction.dir/build

CMakeFiles/apptest-app_automoc_json_extraction.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/apptest-app_automoc_json_extraction.dir/cmake_clean.cmake
.PHONY : CMakeFiles/apptest-app_automoc_json_extraction.dir/clean

CMakeFiles/apptest-app_automoc_json_extraction.dir/depend:
	cd /Users/tpn/Documents/_basic_projects/test-app/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tpn/Documents/_basic_projects/test-app /Users/tpn/Documents/_basic_projects/test-app /Users/tpn/Documents/_basic_projects/test-app/build /Users/tpn/Documents/_basic_projects/test-app/build /Users/tpn/Documents/_basic_projects/test-app/build/CMakeFiles/apptest-app_automoc_json_extraction.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/apptest-app_automoc_json_extraction.dir/depend

