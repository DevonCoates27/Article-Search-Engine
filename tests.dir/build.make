# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.21

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/tests.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tests.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tests.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tests.dir/flags.make

CMakeFiles/tests.dir/test.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/test.cpp.o: ../test.cpp
CMakeFiles/tests.dir/test.cpp.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tests.dir/test.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/test.cpp.o -MF CMakeFiles/tests.dir/test.cpp.o.d -o CMakeFiles/tests.dir/test.cpp.o -c /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/test.cpp

CMakeFiles/tests.dir/test.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/test.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/test.cpp > CMakeFiles/tests.dir/test.cpp.i

CMakeFiles/tests.dir/test.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/test.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/test.cpp -o CMakeFiles/tests.dir/test.cpp.s

CMakeFiles/tests.dir/DocumentParser.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/DocumentParser.cpp.o: ../DocumentParser.cpp
CMakeFiles/tests.dir/DocumentParser.cpp.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tests.dir/DocumentParser.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/DocumentParser.cpp.o -MF CMakeFiles/tests.dir/DocumentParser.cpp.o.d -o CMakeFiles/tests.dir/DocumentParser.cpp.o -c /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/DocumentParser.cpp

CMakeFiles/tests.dir/DocumentParser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/DocumentParser.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/DocumentParser.cpp > CMakeFiles/tests.dir/DocumentParser.cpp.i

CMakeFiles/tests.dir/DocumentParser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/DocumentParser.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/DocumentParser.cpp -o CMakeFiles/tests.dir/DocumentParser.cpp.s

CMakeFiles/tests.dir/Word.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/Word.cpp.o: ../Word.cpp
CMakeFiles/tests.dir/Word.cpp.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tests.dir/Word.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/Word.cpp.o -MF CMakeFiles/tests.dir/Word.cpp.o.d -o CMakeFiles/tests.dir/Word.cpp.o -c /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/Word.cpp

CMakeFiles/tests.dir/Word.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/Word.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/Word.cpp > CMakeFiles/tests.dir/Word.cpp.i

CMakeFiles/tests.dir/Word.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/Word.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/Word.cpp -o CMakeFiles/tests.dir/Word.cpp.s

CMakeFiles/tests.dir/IndexHandler.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/IndexHandler.cpp.o: ../IndexHandler.cpp
CMakeFiles/tests.dir/IndexHandler.cpp.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tests.dir/IndexHandler.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/IndexHandler.cpp.o -MF CMakeFiles/tests.dir/IndexHandler.cpp.o.d -o CMakeFiles/tests.dir/IndexHandler.cpp.o -c /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/IndexHandler.cpp

CMakeFiles/tests.dir/IndexHandler.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/IndexHandler.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/IndexHandler.cpp > CMakeFiles/tests.dir/IndexHandler.cpp.i

CMakeFiles/tests.dir/IndexHandler.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/IndexHandler.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/IndexHandler.cpp -o CMakeFiles/tests.dir/IndexHandler.cpp.s

CMakeFiles/tests.dir/documentID.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/documentID.cpp.o: ../documentID.cpp
CMakeFiles/tests.dir/documentID.cpp.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/tests.dir/documentID.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/documentID.cpp.o -MF CMakeFiles/tests.dir/documentID.cpp.o.d -o CMakeFiles/tests.dir/documentID.cpp.o -c /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/documentID.cpp

CMakeFiles/tests.dir/documentID.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/documentID.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/documentID.cpp > CMakeFiles/tests.dir/documentID.cpp.i

CMakeFiles/tests.dir/documentID.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/documentID.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/documentID.cpp -o CMakeFiles/tests.dir/documentID.cpp.s

CMakeFiles/tests.dir/AVLMap.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/AVLMap.cpp.o: ../AVLMap.cpp
CMakeFiles/tests.dir/AVLMap.cpp.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/tests.dir/AVLMap.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/AVLMap.cpp.o -MF CMakeFiles/tests.dir/AVLMap.cpp.o.d -o CMakeFiles/tests.dir/AVLMap.cpp.o -c /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/AVLMap.cpp

CMakeFiles/tests.dir/AVLMap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/AVLMap.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/AVLMap.cpp > CMakeFiles/tests.dir/AVLMap.cpp.i

CMakeFiles/tests.dir/AVLMap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/AVLMap.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/AVLMap.cpp -o CMakeFiles/tests.dir/AVLMap.cpp.s

CMakeFiles/tests.dir/porter2_stemmer-master/porter2_stemmer.cpp.o: CMakeFiles/tests.dir/flags.make
CMakeFiles/tests.dir/porter2_stemmer-master/porter2_stemmer.cpp.o: ../porter2_stemmer-master/porter2_stemmer.cpp
CMakeFiles/tests.dir/porter2_stemmer-master/porter2_stemmer.cpp.o: CMakeFiles/tests.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/tests.dir/porter2_stemmer-master/porter2_stemmer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tests.dir/porter2_stemmer-master/porter2_stemmer.cpp.o -MF CMakeFiles/tests.dir/porter2_stemmer-master/porter2_stemmer.cpp.o.d -o CMakeFiles/tests.dir/porter2_stemmer-master/porter2_stemmer.cpp.o -c /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/porter2_stemmer-master/porter2_stemmer.cpp

CMakeFiles/tests.dir/porter2_stemmer-master/porter2_stemmer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/tests.dir/porter2_stemmer-master/porter2_stemmer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/porter2_stemmer-master/porter2_stemmer.cpp > CMakeFiles/tests.dir/porter2_stemmer-master/porter2_stemmer.cpp.i

CMakeFiles/tests.dir/porter2_stemmer-master/porter2_stemmer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/tests.dir/porter2_stemmer-master/porter2_stemmer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/porter2_stemmer-master/porter2_stemmer.cpp -o CMakeFiles/tests.dir/porter2_stemmer-master/porter2_stemmer.cpp.s

# Object files for target tests
tests_OBJECTS = \
"CMakeFiles/tests.dir/test.cpp.o" \
"CMakeFiles/tests.dir/DocumentParser.cpp.o" \
"CMakeFiles/tests.dir/Word.cpp.o" \
"CMakeFiles/tests.dir/IndexHandler.cpp.o" \
"CMakeFiles/tests.dir/documentID.cpp.o" \
"CMakeFiles/tests.dir/AVLMap.cpp.o" \
"CMakeFiles/tests.dir/porter2_stemmer-master/porter2_stemmer.cpp.o"

# External object files for target tests
tests_EXTERNAL_OBJECTS =

tests: CMakeFiles/tests.dir/test.cpp.o
tests: CMakeFiles/tests.dir/DocumentParser.cpp.o
tests: CMakeFiles/tests.dir/Word.cpp.o
tests: CMakeFiles/tests.dir/IndexHandler.cpp.o
tests: CMakeFiles/tests.dir/documentID.cpp.o
tests: CMakeFiles/tests.dir/AVLMap.cpp.o
tests: CMakeFiles/tests.dir/porter2_stemmer-master/porter2_stemmer.cpp.o
tests: CMakeFiles/tests.dir/build.make
tests: CMakeFiles/tests.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable tests"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tests.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tests.dir/build: tests
.PHONY : CMakeFiles/tests.dir/build

CMakeFiles/tests.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tests.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tests.dir/clean

CMakeFiles/tests.dir/depend:
	cd /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/cmake-build-debug /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/cmake-build-debug /Users/devoncoates/Documents/GitHub/assignment-4-search-engine-ryan-devon/cmake-build-debug/CMakeFiles/tests.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/tests.dir/depend
