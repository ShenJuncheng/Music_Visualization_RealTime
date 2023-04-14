# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.18

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/pi/Desktop/music_Visualization_for_CMake/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/pi/Desktop/music_Visualization_for_CMake/src/build

# Include any dependencies generated for this target.
include CMakeFiles/MusicVisualizationApp.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/MusicVisualizationApp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/MusicVisualizationApp.dir/flags.make

moc_WS2812B.cpp: ../WS2812B.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/pi/Desktop/music_Visualization_for_CMake/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Generating moc_WS2812B.cpp"
	/usr/lib/qt5/bin/moc @/home/pi/Desktop/music_Visualization_for_CMake/src/build/moc_WS2812B.cpp_parameters

moc_SetDevice.cpp: ../SetDevice.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/pi/Desktop/music_Visualization_for_CMake/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating moc_SetDevice.cpp"
	/usr/lib/qt5/bin/moc @/home/pi/Desktop/music_Visualization_for_CMake/src/build/moc_SetDevice.cpp_parameters

moc_LEDThread.cpp: ../LEDThread.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/pi/Desktop/music_Visualization_for_CMake/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Generating moc_LEDThread.cpp"
	/usr/lib/qt5/bin/moc @/home/pi/Desktop/music_Visualization_for_CMake/src/build/moc_LEDThread.cpp_parameters

moc_AudioSource.cpp: ../AudioSource.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/pi/Desktop/music_Visualization_for_CMake/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Generating moc_AudioSource.cpp"
	/usr/lib/qt5/bin/moc @/home/pi/Desktop/music_Visualization_for_CMake/src/build/moc_AudioSource.cpp_parameters

moc_mainwindow.cpp: ../mainwindow.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/pi/Desktop/music_Visualization_for_CMake/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Generating moc_mainwindow.cpp"
	/usr/lib/qt5/bin/moc @/home/pi/Desktop/music_Visualization_for_CMake/src/build/moc_mainwindow.cpp_parameters

moc_ui_mainwindow.cpp: ../ui_mainwindow.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/pi/Desktop/music_Visualization_for_CMake/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Generating moc_ui_mainwindow.cpp"
	/usr/lib/qt5/bin/moc @/home/pi/Desktop/music_Visualization_for_CMake/src/build/moc_ui_mainwindow.cpp_parameters

ui_mainwindow.h: ../mainwindow.ui
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/pi/Desktop/music_Visualization_for_CMake/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Generating ui_mainwindow.h"
	/usr/lib/qt5/bin/uic -o /home/pi/Desktop/music_Visualization_for_CMake/src/build/ui_mainwindow.h /home/pi/Desktop/music_Visualization_for_CMake/src/mainwindow.ui

CMakeFiles/MusicVisualizationApp.dir/main.cpp.o: CMakeFiles/MusicVisualizationApp.dir/flags.make
CMakeFiles/MusicVisualizationApp.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/music_Visualization_for_CMake/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/MusicVisualizationApp.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MusicVisualizationApp.dir/main.cpp.o -c /home/pi/Desktop/music_Visualization_for_CMake/src/main.cpp

CMakeFiles/MusicVisualizationApp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MusicVisualizationApp.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/music_Visualization_for_CMake/src/main.cpp > CMakeFiles/MusicVisualizationApp.dir/main.cpp.i

CMakeFiles/MusicVisualizationApp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MusicVisualizationApp.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/music_Visualization_for_CMake/src/main.cpp -o CMakeFiles/MusicVisualizationApp.dir/main.cpp.s

CMakeFiles/MusicVisualizationApp.dir/WS2812B.cpp.o: CMakeFiles/MusicVisualizationApp.dir/flags.make
CMakeFiles/MusicVisualizationApp.dir/WS2812B.cpp.o: ../WS2812B.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/music_Visualization_for_CMake/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/MusicVisualizationApp.dir/WS2812B.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MusicVisualizationApp.dir/WS2812B.cpp.o -c /home/pi/Desktop/music_Visualization_for_CMake/src/WS2812B.cpp

CMakeFiles/MusicVisualizationApp.dir/WS2812B.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MusicVisualizationApp.dir/WS2812B.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/music_Visualization_for_CMake/src/WS2812B.cpp > CMakeFiles/MusicVisualizationApp.dir/WS2812B.cpp.i

CMakeFiles/MusicVisualizationApp.dir/WS2812B.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MusicVisualizationApp.dir/WS2812B.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/music_Visualization_for_CMake/src/WS2812B.cpp -o CMakeFiles/MusicVisualizationApp.dir/WS2812B.cpp.s

CMakeFiles/MusicVisualizationApp.dir/SetDevice.cpp.o: CMakeFiles/MusicVisualizationApp.dir/flags.make
CMakeFiles/MusicVisualizationApp.dir/SetDevice.cpp.o: ../SetDevice.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/music_Visualization_for_CMake/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/MusicVisualizationApp.dir/SetDevice.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MusicVisualizationApp.dir/SetDevice.cpp.o -c /home/pi/Desktop/music_Visualization_for_CMake/src/SetDevice.cpp

CMakeFiles/MusicVisualizationApp.dir/SetDevice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MusicVisualizationApp.dir/SetDevice.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/music_Visualization_for_CMake/src/SetDevice.cpp > CMakeFiles/MusicVisualizationApp.dir/SetDevice.cpp.i

CMakeFiles/MusicVisualizationApp.dir/SetDevice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MusicVisualizationApp.dir/SetDevice.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/music_Visualization_for_CMake/src/SetDevice.cpp -o CMakeFiles/MusicVisualizationApp.dir/SetDevice.cpp.s

CMakeFiles/MusicVisualizationApp.dir/LEDThread.cpp.o: CMakeFiles/MusicVisualizationApp.dir/flags.make
CMakeFiles/MusicVisualizationApp.dir/LEDThread.cpp.o: ../LEDThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/music_Visualization_for_CMake/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/MusicVisualizationApp.dir/LEDThread.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MusicVisualizationApp.dir/LEDThread.cpp.o -c /home/pi/Desktop/music_Visualization_for_CMake/src/LEDThread.cpp

CMakeFiles/MusicVisualizationApp.dir/LEDThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MusicVisualizationApp.dir/LEDThread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/music_Visualization_for_CMake/src/LEDThread.cpp > CMakeFiles/MusicVisualizationApp.dir/LEDThread.cpp.i

CMakeFiles/MusicVisualizationApp.dir/LEDThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MusicVisualizationApp.dir/LEDThread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/music_Visualization_for_CMake/src/LEDThread.cpp -o CMakeFiles/MusicVisualizationApp.dir/LEDThread.cpp.s

CMakeFiles/MusicVisualizationApp.dir/AudioSource.cpp.o: CMakeFiles/MusicVisualizationApp.dir/flags.make
CMakeFiles/MusicVisualizationApp.dir/AudioSource.cpp.o: ../AudioSource.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/music_Visualization_for_CMake/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/MusicVisualizationApp.dir/AudioSource.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MusicVisualizationApp.dir/AudioSource.cpp.o -c /home/pi/Desktop/music_Visualization_for_CMake/src/AudioSource.cpp

CMakeFiles/MusicVisualizationApp.dir/AudioSource.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MusicVisualizationApp.dir/AudioSource.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/music_Visualization_for_CMake/src/AudioSource.cpp > CMakeFiles/MusicVisualizationApp.dir/AudioSource.cpp.i

CMakeFiles/MusicVisualizationApp.dir/AudioSource.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MusicVisualizationApp.dir/AudioSource.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/music_Visualization_for_CMake/src/AudioSource.cpp -o CMakeFiles/MusicVisualizationApp.dir/AudioSource.cpp.s

CMakeFiles/MusicVisualizationApp.dir/mainwindow.cpp.o: CMakeFiles/MusicVisualizationApp.dir/flags.make
CMakeFiles/MusicVisualizationApp.dir/mainwindow.cpp.o: ../mainwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/music_Visualization_for_CMake/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/MusicVisualizationApp.dir/mainwindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MusicVisualizationApp.dir/mainwindow.cpp.o -c /home/pi/Desktop/music_Visualization_for_CMake/src/mainwindow.cpp

CMakeFiles/MusicVisualizationApp.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MusicVisualizationApp.dir/mainwindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/music_Visualization_for_CMake/src/mainwindow.cpp > CMakeFiles/MusicVisualizationApp.dir/mainwindow.cpp.i

CMakeFiles/MusicVisualizationApp.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MusicVisualizationApp.dir/mainwindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/music_Visualization_for_CMake/src/mainwindow.cpp -o CMakeFiles/MusicVisualizationApp.dir/mainwindow.cpp.s

CMakeFiles/MusicVisualizationApp.dir/moc_WS2812B.cpp.o: CMakeFiles/MusicVisualizationApp.dir/flags.make
CMakeFiles/MusicVisualizationApp.dir/moc_WS2812B.cpp.o: moc_WS2812B.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/music_Visualization_for_CMake/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/MusicVisualizationApp.dir/moc_WS2812B.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MusicVisualizationApp.dir/moc_WS2812B.cpp.o -c /home/pi/Desktop/music_Visualization_for_CMake/src/build/moc_WS2812B.cpp

CMakeFiles/MusicVisualizationApp.dir/moc_WS2812B.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MusicVisualizationApp.dir/moc_WS2812B.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/music_Visualization_for_CMake/src/build/moc_WS2812B.cpp > CMakeFiles/MusicVisualizationApp.dir/moc_WS2812B.cpp.i

CMakeFiles/MusicVisualizationApp.dir/moc_WS2812B.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MusicVisualizationApp.dir/moc_WS2812B.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/music_Visualization_for_CMake/src/build/moc_WS2812B.cpp -o CMakeFiles/MusicVisualizationApp.dir/moc_WS2812B.cpp.s

CMakeFiles/MusicVisualizationApp.dir/moc_SetDevice.cpp.o: CMakeFiles/MusicVisualizationApp.dir/flags.make
CMakeFiles/MusicVisualizationApp.dir/moc_SetDevice.cpp.o: moc_SetDevice.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/music_Visualization_for_CMake/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/MusicVisualizationApp.dir/moc_SetDevice.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MusicVisualizationApp.dir/moc_SetDevice.cpp.o -c /home/pi/Desktop/music_Visualization_for_CMake/src/build/moc_SetDevice.cpp

CMakeFiles/MusicVisualizationApp.dir/moc_SetDevice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MusicVisualizationApp.dir/moc_SetDevice.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/music_Visualization_for_CMake/src/build/moc_SetDevice.cpp > CMakeFiles/MusicVisualizationApp.dir/moc_SetDevice.cpp.i

CMakeFiles/MusicVisualizationApp.dir/moc_SetDevice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MusicVisualizationApp.dir/moc_SetDevice.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/music_Visualization_for_CMake/src/build/moc_SetDevice.cpp -o CMakeFiles/MusicVisualizationApp.dir/moc_SetDevice.cpp.s

CMakeFiles/MusicVisualizationApp.dir/moc_LEDThread.cpp.o: CMakeFiles/MusicVisualizationApp.dir/flags.make
CMakeFiles/MusicVisualizationApp.dir/moc_LEDThread.cpp.o: moc_LEDThread.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/music_Visualization_for_CMake/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/MusicVisualizationApp.dir/moc_LEDThread.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MusicVisualizationApp.dir/moc_LEDThread.cpp.o -c /home/pi/Desktop/music_Visualization_for_CMake/src/build/moc_LEDThread.cpp

CMakeFiles/MusicVisualizationApp.dir/moc_LEDThread.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MusicVisualizationApp.dir/moc_LEDThread.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/music_Visualization_for_CMake/src/build/moc_LEDThread.cpp > CMakeFiles/MusicVisualizationApp.dir/moc_LEDThread.cpp.i

CMakeFiles/MusicVisualizationApp.dir/moc_LEDThread.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MusicVisualizationApp.dir/moc_LEDThread.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/music_Visualization_for_CMake/src/build/moc_LEDThread.cpp -o CMakeFiles/MusicVisualizationApp.dir/moc_LEDThread.cpp.s

CMakeFiles/MusicVisualizationApp.dir/moc_AudioSource.cpp.o: CMakeFiles/MusicVisualizationApp.dir/flags.make
CMakeFiles/MusicVisualizationApp.dir/moc_AudioSource.cpp.o: moc_AudioSource.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/music_Visualization_for_CMake/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Building CXX object CMakeFiles/MusicVisualizationApp.dir/moc_AudioSource.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MusicVisualizationApp.dir/moc_AudioSource.cpp.o -c /home/pi/Desktop/music_Visualization_for_CMake/src/build/moc_AudioSource.cpp

CMakeFiles/MusicVisualizationApp.dir/moc_AudioSource.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MusicVisualizationApp.dir/moc_AudioSource.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/music_Visualization_for_CMake/src/build/moc_AudioSource.cpp > CMakeFiles/MusicVisualizationApp.dir/moc_AudioSource.cpp.i

CMakeFiles/MusicVisualizationApp.dir/moc_AudioSource.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MusicVisualizationApp.dir/moc_AudioSource.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/music_Visualization_for_CMake/src/build/moc_AudioSource.cpp -o CMakeFiles/MusicVisualizationApp.dir/moc_AudioSource.cpp.s

CMakeFiles/MusicVisualizationApp.dir/moc_mainwindow.cpp.o: CMakeFiles/MusicVisualizationApp.dir/flags.make
CMakeFiles/MusicVisualizationApp.dir/moc_mainwindow.cpp.o: moc_mainwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/music_Visualization_for_CMake/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_18) "Building CXX object CMakeFiles/MusicVisualizationApp.dir/moc_mainwindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MusicVisualizationApp.dir/moc_mainwindow.cpp.o -c /home/pi/Desktop/music_Visualization_for_CMake/src/build/moc_mainwindow.cpp

CMakeFiles/MusicVisualizationApp.dir/moc_mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MusicVisualizationApp.dir/moc_mainwindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/music_Visualization_for_CMake/src/build/moc_mainwindow.cpp > CMakeFiles/MusicVisualizationApp.dir/moc_mainwindow.cpp.i

CMakeFiles/MusicVisualizationApp.dir/moc_mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MusicVisualizationApp.dir/moc_mainwindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/music_Visualization_for_CMake/src/build/moc_mainwindow.cpp -o CMakeFiles/MusicVisualizationApp.dir/moc_mainwindow.cpp.s

CMakeFiles/MusicVisualizationApp.dir/moc_ui_mainwindow.cpp.o: CMakeFiles/MusicVisualizationApp.dir/flags.make
CMakeFiles/MusicVisualizationApp.dir/moc_ui_mainwindow.cpp.o: moc_ui_mainwindow.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/pi/Desktop/music_Visualization_for_CMake/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_19) "Building CXX object CMakeFiles/MusicVisualizationApp.dir/moc_ui_mainwindow.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/MusicVisualizationApp.dir/moc_ui_mainwindow.cpp.o -c /home/pi/Desktop/music_Visualization_for_CMake/src/build/moc_ui_mainwindow.cpp

CMakeFiles/MusicVisualizationApp.dir/moc_ui_mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/MusicVisualizationApp.dir/moc_ui_mainwindow.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/pi/Desktop/music_Visualization_for_CMake/src/build/moc_ui_mainwindow.cpp > CMakeFiles/MusicVisualizationApp.dir/moc_ui_mainwindow.cpp.i

CMakeFiles/MusicVisualizationApp.dir/moc_ui_mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/MusicVisualizationApp.dir/moc_ui_mainwindow.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/pi/Desktop/music_Visualization_for_CMake/src/build/moc_ui_mainwindow.cpp -o CMakeFiles/MusicVisualizationApp.dir/moc_ui_mainwindow.cpp.s

# Object files for target MusicVisualizationApp
MusicVisualizationApp_OBJECTS = \
"CMakeFiles/MusicVisualizationApp.dir/main.cpp.o" \
"CMakeFiles/MusicVisualizationApp.dir/WS2812B.cpp.o" \
"CMakeFiles/MusicVisualizationApp.dir/SetDevice.cpp.o" \
"CMakeFiles/MusicVisualizationApp.dir/LEDThread.cpp.o" \
"CMakeFiles/MusicVisualizationApp.dir/AudioSource.cpp.o" \
"CMakeFiles/MusicVisualizationApp.dir/mainwindow.cpp.o" \
"CMakeFiles/MusicVisualizationApp.dir/moc_WS2812B.cpp.o" \
"CMakeFiles/MusicVisualizationApp.dir/moc_SetDevice.cpp.o" \
"CMakeFiles/MusicVisualizationApp.dir/moc_LEDThread.cpp.o" \
"CMakeFiles/MusicVisualizationApp.dir/moc_AudioSource.cpp.o" \
"CMakeFiles/MusicVisualizationApp.dir/moc_mainwindow.cpp.o" \
"CMakeFiles/MusicVisualizationApp.dir/moc_ui_mainwindow.cpp.o"

# External object files for target MusicVisualizationApp
MusicVisualizationApp_EXTERNAL_OBJECTS =

MusicVisualizationApp: CMakeFiles/MusicVisualizationApp.dir/main.cpp.o
MusicVisualizationApp: CMakeFiles/MusicVisualizationApp.dir/WS2812B.cpp.o
MusicVisualizationApp: CMakeFiles/MusicVisualizationApp.dir/SetDevice.cpp.o
MusicVisualizationApp: CMakeFiles/MusicVisualizationApp.dir/LEDThread.cpp.o
MusicVisualizationApp: CMakeFiles/MusicVisualizationApp.dir/AudioSource.cpp.o
MusicVisualizationApp: CMakeFiles/MusicVisualizationApp.dir/mainwindow.cpp.o
MusicVisualizationApp: CMakeFiles/MusicVisualizationApp.dir/moc_WS2812B.cpp.o
MusicVisualizationApp: CMakeFiles/MusicVisualizationApp.dir/moc_SetDevice.cpp.o
MusicVisualizationApp: CMakeFiles/MusicVisualizationApp.dir/moc_LEDThread.cpp.o
MusicVisualizationApp: CMakeFiles/MusicVisualizationApp.dir/moc_AudioSource.cpp.o
MusicVisualizationApp: CMakeFiles/MusicVisualizationApp.dir/moc_mainwindow.cpp.o
MusicVisualizationApp: CMakeFiles/MusicVisualizationApp.dir/moc_ui_mainwindow.cpp.o
MusicVisualizationApp: CMakeFiles/MusicVisualizationApp.dir/build.make
MusicVisualizationApp: /usr/lib/arm-linux-gnueabihf/libQt5Charts.so.5.15.2
MusicVisualizationApp: /usr/lib/arm-linux-gnueabihf/libQt5Multimedia.so.5.15.2
MusicVisualizationApp: /usr/lib/arm-linux-gnueabihf/libQt5Widgets.so.5.15.2
MusicVisualizationApp: /usr/lib/arm-linux-gnueabihf/libQt5Gui.so.5.15.2
MusicVisualizationApp: /usr/lib/arm-linux-gnueabihf/libQt5Network.so.5.15.2
MusicVisualizationApp: /usr/lib/arm-linux-gnueabihf/libQt5Core.so.5.15.2
MusicVisualizationApp: CMakeFiles/MusicVisualizationApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/pi/Desktop/music_Visualization_for_CMake/src/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_20) "Linking CXX executable MusicVisualizationApp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/MusicVisualizationApp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/MusicVisualizationApp.dir/build: MusicVisualizationApp

.PHONY : CMakeFiles/MusicVisualizationApp.dir/build

CMakeFiles/MusicVisualizationApp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/MusicVisualizationApp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/MusicVisualizationApp.dir/clean

CMakeFiles/MusicVisualizationApp.dir/depend: moc_WS2812B.cpp
CMakeFiles/MusicVisualizationApp.dir/depend: moc_SetDevice.cpp
CMakeFiles/MusicVisualizationApp.dir/depend: moc_LEDThread.cpp
CMakeFiles/MusicVisualizationApp.dir/depend: moc_AudioSource.cpp
CMakeFiles/MusicVisualizationApp.dir/depend: moc_mainwindow.cpp
CMakeFiles/MusicVisualizationApp.dir/depend: moc_ui_mainwindow.cpp
CMakeFiles/MusicVisualizationApp.dir/depend: ui_mainwindow.h
	cd /home/pi/Desktop/music_Visualization_for_CMake/src/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/pi/Desktop/music_Visualization_for_CMake/src /home/pi/Desktop/music_Visualization_for_CMake/src /home/pi/Desktop/music_Visualization_for_CMake/src/build /home/pi/Desktop/music_Visualization_for_CMake/src/build /home/pi/Desktop/music_Visualization_for_CMake/src/build/CMakeFiles/MusicVisualizationApp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/MusicVisualizationApp.dir/depend
