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
CMAKE_COMMAND = /snap/clion/138/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /snap/clion/138/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jakub/CLionProjects/Game_client

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jakub/CLionProjects/Game_client/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Game_client.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Game_client.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Game_client.dir/flags.make

CMakeFiles/Game_client.dir/main.cpp.o: CMakeFiles/Game_client.dir/flags.make
CMakeFiles/Game_client.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jakub/CLionProjects/Game_client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Game_client.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game_client.dir/main.cpp.o -c /home/jakub/CLionProjects/Game_client/main.cpp

CMakeFiles/Game_client.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game_client.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jakub/CLionProjects/Game_client/main.cpp > CMakeFiles/Game_client.dir/main.cpp.i

CMakeFiles/Game_client.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game_client.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jakub/CLionProjects/Game_client/main.cpp -o CMakeFiles/Game_client.dir/main.cpp.s

CMakeFiles/Game_client.dir/player.cpp.o: CMakeFiles/Game_client.dir/flags.make
CMakeFiles/Game_client.dir/player.cpp.o: ../player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jakub/CLionProjects/Game_client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Game_client.dir/player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game_client.dir/player.cpp.o -c /home/jakub/CLionProjects/Game_client/player.cpp

CMakeFiles/Game_client.dir/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game_client.dir/player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jakub/CLionProjects/Game_client/player.cpp > CMakeFiles/Game_client.dir/player.cpp.i

CMakeFiles/Game_client.dir/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game_client.dir/player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jakub/CLionProjects/Game_client/player.cpp -o CMakeFiles/Game_client.dir/player.cpp.s

# Object files for target Game_client
Game_client_OBJECTS = \
"CMakeFiles/Game_client.dir/main.cpp.o" \
"CMakeFiles/Game_client.dir/player.cpp.o"

# External object files for target Game_client
Game_client_EXTERNAL_OBJECTS =

Game_client: CMakeFiles/Game_client.dir/main.cpp.o
Game_client: CMakeFiles/Game_client.dir/player.cpp.o
Game_client: CMakeFiles/Game_client.dir/build.make
Game_client: /usr/lib/x86_64-linux-gnu/libcurses.so
Game_client: /usr/lib/x86_64-linux-gnu/libform.so
Game_client: CMakeFiles/Game_client.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jakub/CLionProjects/Game_client/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable Game_client"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Game_client.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Game_client.dir/build: Game_client

.PHONY : CMakeFiles/Game_client.dir/build

CMakeFiles/Game_client.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Game_client.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Game_client.dir/clean

CMakeFiles/Game_client.dir/depend:
	cd /home/jakub/CLionProjects/Game_client/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jakub/CLionProjects/Game_client /home/jakub/CLionProjects/Game_client /home/jakub/CLionProjects/Game_client/cmake-build-debug /home/jakub/CLionProjects/Game_client/cmake-build-debug /home/jakub/CLionProjects/Game_client/cmake-build-debug/CMakeFiles/Game_client.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Game_client.dir/depend

