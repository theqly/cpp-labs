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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\a.gaan\Desktop\cpp-labs\cpp-labs\lab0\lab0b

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\a.gaan\Desktop\cpp-labs\cpp-labs\lab0\lab0b\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/test1.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/test1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test1.dir/flags.make

CMakeFiles/test1.dir/test/test.cpp.obj: CMakeFiles/test1.dir/flags.make
CMakeFiles/test1.dir/test/test.cpp.obj: CMakeFiles/test1.dir/includes_CXX.rsp
CMakeFiles/test1.dir/test/test.cpp.obj: ../test/test.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\a.gaan\Desktop\cpp-labs\cpp-labs\lab0\lab0b\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test1.dir/test/test.cpp.obj"
	C:\tools\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\test1.dir\test\test.cpp.obj -c C:\Users\a.gaan\Desktop\cpp-labs\cpp-labs\lab0\lab0b\test\test.cpp

CMakeFiles/test1.dir/test/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/test1.dir/test/test.cpp.i"
	C:\tools\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\a.gaan\Desktop\cpp-labs\cpp-labs\lab0\lab0b\test\test.cpp > CMakeFiles\test1.dir\test\test.cpp.i

CMakeFiles/test1.dir/test/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/test1.dir/test/test.cpp.s"
	C:\tools\mingw64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\a.gaan\Desktop\cpp-labs\cpp-labs\lab0\lab0b\test\test.cpp -o CMakeFiles\test1.dir\test\test.cpp.s

# Object files for target test1
test1_OBJECTS = \
"CMakeFiles/test1.dir/test/test.cpp.obj"

# External object files for target test1
test1_EXTERNAL_OBJECTS =

test1.exe: CMakeFiles/test1.dir/test/test.cpp.obj
test1.exe: CMakeFiles/test1.dir/build.make
test1.exe: lib/libgtest_main.a
test1.exe: lib/libgtest.a
test1.exe: CMakeFiles/test1.dir/linklibs.rsp
test1.exe: CMakeFiles/test1.dir/objects1.rsp
test1.exe: CMakeFiles/test1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\a.gaan\Desktop\cpp-labs\cpp-labs\lab0\lab0b\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test1.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test1.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test1.dir/build: test1.exe
.PHONY : CMakeFiles/test1.dir/build

CMakeFiles/test1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test1.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test1.dir/clean

CMakeFiles/test1.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\a.gaan\Desktop\cpp-labs\cpp-labs\lab0\lab0b C:\Users\a.gaan\Desktop\cpp-labs\cpp-labs\lab0\lab0b C:\Users\a.gaan\Desktop\cpp-labs\cpp-labs\lab0\lab0b\cmake-build-debug C:\Users\a.gaan\Desktop\cpp-labs\cpp-labs\lab0\lab0b\cmake-build-debug C:\Users\a.gaan\Desktop\cpp-labs\cpp-labs\lab0\lab0b\cmake-build-debug\CMakeFiles\test1.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test1.dir/depend

