# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\LakeheadUCourse\2nd_year_fall\DataStruct_COMP2412\assignments\assign02

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\LakeheadUCourse\2nd_year_fall\DataStruct_COMP2412\assignments\assign02\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/assign02.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/assign02.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/assign02.dir/flags.make

CMakeFiles/assign02.dir/main.c.obj: CMakeFiles/assign02.dir/flags.make
CMakeFiles/assign02.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\LakeheadUCourse\2nd_year_fall\DataStruct_COMP2412\assignments\assign02\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/assign02.dir/main.c.obj"
	D:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\assign02.dir\main.c.obj -c D:\LakeheadUCourse\2nd_year_fall\DataStruct_COMP2412\assignments\assign02\main.c

CMakeFiles/assign02.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/assign02.dir/main.c.i"
	D:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E D:\LakeheadUCourse\2nd_year_fall\DataStruct_COMP2412\assignments\assign02\main.c > CMakeFiles\assign02.dir\main.c.i

CMakeFiles/assign02.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/assign02.dir/main.c.s"
	D:\mingw-w64\x86_64-8.1.0-posix-seh-rt_v6-rev0\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S D:\LakeheadUCourse\2nd_year_fall\DataStruct_COMP2412\assignments\assign02\main.c -o CMakeFiles\assign02.dir\main.c.s

# Object files for target assign02
assign02_OBJECTS = \
"CMakeFiles/assign02.dir/main.c.obj"

# External object files for target assign02
assign02_EXTERNAL_OBJECTS =

assign02.exe: CMakeFiles/assign02.dir/main.c.obj
assign02.exe: CMakeFiles/assign02.dir/build.make
assign02.exe: CMakeFiles/assign02.dir/linklibs.rsp
assign02.exe: CMakeFiles/assign02.dir/objects1.rsp
assign02.exe: CMakeFiles/assign02.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\LakeheadUCourse\2nd_year_fall\DataStruct_COMP2412\assignments\assign02\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable assign02.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\assign02.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/assign02.dir/build: assign02.exe
.PHONY : CMakeFiles/assign02.dir/build

CMakeFiles/assign02.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\assign02.dir\cmake_clean.cmake
.PHONY : CMakeFiles/assign02.dir/clean

CMakeFiles/assign02.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\LakeheadUCourse\2nd_year_fall\DataStruct_COMP2412\assignments\assign02 D:\LakeheadUCourse\2nd_year_fall\DataStruct_COMP2412\assignments\assign02 D:\LakeheadUCourse\2nd_year_fall\DataStruct_COMP2412\assignments\assign02\cmake-build-debug D:\LakeheadUCourse\2nd_year_fall\DataStruct_COMP2412\assignments\assign02\cmake-build-debug D:\LakeheadUCourse\2nd_year_fall\DataStruct_COMP2412\assignments\assign02\cmake-build-debug\CMakeFiles\assign02.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/assign02.dir/depend
