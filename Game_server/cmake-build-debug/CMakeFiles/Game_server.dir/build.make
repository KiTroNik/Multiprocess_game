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
CMAKE_SOURCE_DIR = /home/jakub/CLionProjects/Game_server

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jakub/CLionProjects/Game_server/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Game_server.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Game_server.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Game_server.dir/flags.make

CMakeFiles/Game_server.dir/main.cpp.o: CMakeFiles/Game_server.dir/flags.make
CMakeFiles/Game_server.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jakub/CLionProjects/Game_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Game_server.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game_server.dir/main.cpp.o -c /home/jakub/CLionProjects/Game_server/main.cpp

CMakeFiles/Game_server.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game_server.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jakub/CLionProjects/Game_server/main.cpp > CMakeFiles/Game_server.dir/main.cpp.i

CMakeFiles/Game_server.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game_server.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jakub/CLionProjects/Game_server/main.cpp -o CMakeFiles/Game_server.dir/main.cpp.s

CMakeFiles/Game_server.dir/labirynth.cpp.o: CMakeFiles/Game_server.dir/flags.make
CMakeFiles/Game_server.dir/labirynth.cpp.o: ../labirynth.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jakub/CLionProjects/Game_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Game_server.dir/labirynth.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game_server.dir/labirynth.cpp.o -c /home/jakub/CLionProjects/Game_server/labirynth.cpp

CMakeFiles/Game_server.dir/labirynth.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game_server.dir/labirynth.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jakub/CLionProjects/Game_server/labirynth.cpp > CMakeFiles/Game_server.dir/labirynth.cpp.i

CMakeFiles/Game_server.dir/labirynth.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game_server.dir/labirynth.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jakub/CLionProjects/Game_server/labirynth.cpp -o CMakeFiles/Game_server.dir/labirynth.cpp.s

CMakeFiles/Game_server.dir/player.cpp.o: CMakeFiles/Game_server.dir/flags.make
CMakeFiles/Game_server.dir/player.cpp.o: ../player.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jakub/CLionProjects/Game_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Game_server.dir/player.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game_server.dir/player.cpp.o -c /home/jakub/CLionProjects/Game_server/player.cpp

CMakeFiles/Game_server.dir/player.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game_server.dir/player.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jakub/CLionProjects/Game_server/player.cpp > CMakeFiles/Game_server.dir/player.cpp.i

CMakeFiles/Game_server.dir/player.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game_server.dir/player.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jakub/CLionProjects/Game_server/player.cpp -o CMakeFiles/Game_server.dir/player.cpp.s

CMakeFiles/Game_server.dir/beast.cpp.o: CMakeFiles/Game_server.dir/flags.make
CMakeFiles/Game_server.dir/beast.cpp.o: ../beast.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jakub/CLionProjects/Game_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Game_server.dir/beast.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game_server.dir/beast.cpp.o -c /home/jakub/CLionProjects/Game_server/beast.cpp

CMakeFiles/Game_server.dir/beast.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game_server.dir/beast.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jakub/CLionProjects/Game_server/beast.cpp > CMakeFiles/Game_server.dir/beast.cpp.i

CMakeFiles/Game_server.dir/beast.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game_server.dir/beast.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jakub/CLionProjects/Game_server/beast.cpp -o CMakeFiles/Game_server.dir/beast.cpp.s

CMakeFiles/Game_server.dir/server.cpp.o: CMakeFiles/Game_server.dir/flags.make
CMakeFiles/Game_server.dir/server.cpp.o: ../server.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/jakub/CLionProjects/Game_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Game_server.dir/server.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Game_server.dir/server.cpp.o -c /home/jakub/CLionProjects/Game_server/server.cpp

CMakeFiles/Game_server.dir/server.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Game_server.dir/server.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/jakub/CLionProjects/Game_server/server.cpp > CMakeFiles/Game_server.dir/server.cpp.i

CMakeFiles/Game_server.dir/server.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Game_server.dir/server.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/jakub/CLionProjects/Game_server/server.cpp -o CMakeFiles/Game_server.dir/server.cpp.s

# Object files for target Game_server
Game_server_OBJECTS = \
"CMakeFiles/Game_server.dir/main.cpp.o" \
"CMakeFiles/Game_server.dir/labirynth.cpp.o" \
"CMakeFiles/Game_server.dir/player.cpp.o" \
"CMakeFiles/Game_server.dir/beast.cpp.o" \
"CMakeFiles/Game_server.dir/server.cpp.o"

# External object files for target Game_server
Game_server_EXTERNAL_OBJECTS =

Game_server: CMakeFiles/Game_server.dir/main.cpp.o
Game_server: CMakeFiles/Game_server.dir/labirynth.cpp.o
Game_server: CMakeFiles/Game_server.dir/player.cpp.o
Game_server: CMakeFiles/Game_server.dir/beast.cpp.o
Game_server: CMakeFiles/Game_server.dir/server.cpp.o
Game_server: CMakeFiles/Game_server.dir/build.make
Game_server: /usr/lib/x86_64-linux-gnu/libcurses.so
Game_server: /usr/lib/x86_64-linux-gnu/libform.so
Game_server: CMakeFiles/Game_server.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/jakub/CLionProjects/Game_server/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Game_server"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Game_server.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Game_server.dir/build: Game_server

.PHONY : CMakeFiles/Game_server.dir/build

CMakeFiles/Game_server.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Game_server.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Game_server.dir/clean

CMakeFiles/Game_server.dir/depend:
	cd /home/jakub/CLionProjects/Game_server/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jakub/CLionProjects/Game_server /home/jakub/CLionProjects/Game_server /home/jakub/CLionProjects/Game_server/cmake-build-debug /home/jakub/CLionProjects/Game_server/cmake-build-debug /home/jakub/CLionProjects/Game_server/cmake-build-debug/CMakeFiles/Game_server.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Game_server.dir/depend

