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

# Utility rule file for apptest-app_qmllint.

# Include any custom commands dependencies for this target.
include CMakeFiles/apptest-app_qmllint.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/apptest-app_qmllint.dir/progress.make

CMakeFiles/apptest-app_qmllint: /Users/tpn/Qt/6.5.2/macos/bin/qmllint
CMakeFiles/apptest-app_qmllint: /Users/tpn/Documents/_basic_projects/test-app/main.qml
	cd /Users/tpn/Documents/_basic_projects/test-app && /Users/tpn/Qt/6.5.2/macos/bin/qmllint --bare -I /Users/tpn/Documents/_basic_projects/test-app/build -I /Users/tpn/Qt/6.5.2/macos/./qml --resource /Users/tpn/Documents/_basic_projects/test-app/build/.rcc/qmake_test-app.qrc --resource /Users/tpn/Documents/_basic_projects/test-app/build/.rcc/apptest-app_raw_qml_0.qrc /Users/tpn/Documents/_basic_projects/test-app/main.qml

apptest-app_qmllint: CMakeFiles/apptest-app_qmllint
apptest-app_qmllint: CMakeFiles/apptest-app_qmllint.dir/build.make
.PHONY : apptest-app_qmllint

# Rule to build all files generated by this target.
CMakeFiles/apptest-app_qmllint.dir/build: apptest-app_qmllint
.PHONY : CMakeFiles/apptest-app_qmllint.dir/build

CMakeFiles/apptest-app_qmllint.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/apptest-app_qmllint.dir/cmake_clean.cmake
.PHONY : CMakeFiles/apptest-app_qmllint.dir/clean

CMakeFiles/apptest-app_qmllint.dir/depend:
	cd /Users/tpn/Documents/_basic_projects/test-app/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/tpn/Documents/_basic_projects/test-app /Users/tpn/Documents/_basic_projects/test-app /Users/tpn/Documents/_basic_projects/test-app/build /Users/tpn/Documents/_basic_projects/test-app/build /Users/tpn/Documents/_basic_projects/test-app/build/CMakeFiles/apptest-app_qmllint.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/apptest-app_qmllint.dir/depend

