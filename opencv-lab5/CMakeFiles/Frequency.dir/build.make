# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/gzr/opencv-workspace/opencv-lab5

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gzr/opencv-workspace/opencv-lab5

# Include any dependencies generated for this target.
include CMakeFiles/Frequency.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Frequency.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Frequency.dir/flags.make

CMakeFiles/Frequency.dir/fdma.cpp.o: CMakeFiles/Frequency.dir/flags.make
CMakeFiles/Frequency.dir/fdma.cpp.o: fdma.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gzr/opencv-workspace/opencv-lab5/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Frequency.dir/fdma.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Frequency.dir/fdma.cpp.o -c /home/gzr/opencv-workspace/opencv-lab5/fdma.cpp

CMakeFiles/Frequency.dir/fdma.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Frequency.dir/fdma.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gzr/opencv-workspace/opencv-lab5/fdma.cpp > CMakeFiles/Frequency.dir/fdma.cpp.i

CMakeFiles/Frequency.dir/fdma.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Frequency.dir/fdma.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gzr/opencv-workspace/opencv-lab5/fdma.cpp -o CMakeFiles/Frequency.dir/fdma.cpp.s

CMakeFiles/Frequency.dir/fdma.cpp.o.requires:

.PHONY : CMakeFiles/Frequency.dir/fdma.cpp.o.requires

CMakeFiles/Frequency.dir/fdma.cpp.o.provides: CMakeFiles/Frequency.dir/fdma.cpp.o.requires
	$(MAKE) -f CMakeFiles/Frequency.dir/build.make CMakeFiles/Frequency.dir/fdma.cpp.o.provides.build
.PHONY : CMakeFiles/Frequency.dir/fdma.cpp.o.provides

CMakeFiles/Frequency.dir/fdma.cpp.o.provides.build: CMakeFiles/Frequency.dir/fdma.cpp.o


# Object files for target Frequency
Frequency_OBJECTS = \
"CMakeFiles/Frequency.dir/fdma.cpp.o"

# External object files for target Frequency
Frequency_EXTERNAL_OBJECTS =

Frequency: CMakeFiles/Frequency.dir/fdma.cpp.o
Frequency: CMakeFiles/Frequency.dir/build.make
Frequency: /usr/local/lib/libopencv_shape.so.3.2.0
Frequency: /usr/local/lib/libopencv_stitching.so.3.2.0
Frequency: /usr/local/lib/libopencv_superres.so.3.2.0
Frequency: /usr/local/lib/libopencv_videostab.so.3.2.0
Frequency: /usr/local/lib/libopencv_objdetect.so.3.2.0
Frequency: /usr/local/lib/libopencv_calib3d.so.3.2.0
Frequency: /usr/local/lib/libopencv_features2d.so.3.2.0
Frequency: /usr/local/lib/libopencv_flann.so.3.2.0
Frequency: /usr/local/lib/libopencv_highgui.so.3.2.0
Frequency: /usr/local/lib/libopencv_ml.so.3.2.0
Frequency: /usr/local/lib/libopencv_photo.so.3.2.0
Frequency: /usr/local/lib/libopencv_video.so.3.2.0
Frequency: /usr/local/lib/libopencv_videoio.so.3.2.0
Frequency: /usr/local/lib/libopencv_imgcodecs.so.3.2.0
Frequency: /usr/local/lib/libopencv_imgproc.so.3.2.0
Frequency: /usr/local/lib/libopencv_core.so.3.2.0
Frequency: CMakeFiles/Frequency.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gzr/opencv-workspace/opencv-lab5/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Frequency"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Frequency.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Frequency.dir/build: Frequency

.PHONY : CMakeFiles/Frequency.dir/build

CMakeFiles/Frequency.dir/requires: CMakeFiles/Frequency.dir/fdma.cpp.o.requires

.PHONY : CMakeFiles/Frequency.dir/requires

CMakeFiles/Frequency.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Frequency.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Frequency.dir/clean

CMakeFiles/Frequency.dir/depend:
	cd /home/gzr/opencv-workspace/opencv-lab5 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gzr/opencv-workspace/opencv-lab5 /home/gzr/opencv-workspace/opencv-lab5 /home/gzr/opencv-workspace/opencv-lab5 /home/gzr/opencv-workspace/opencv-lab5 /home/gzr/opencv-workspace/opencv-lab5/CMakeFiles/Frequency.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Frequency.dir/depend

