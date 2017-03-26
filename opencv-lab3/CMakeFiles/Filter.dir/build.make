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
CMAKE_SOURCE_DIR = /home/gzr/opencv-workspace/opencv-lab3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/gzr/opencv-workspace/opencv-lab3

# Include any dependencies generated for this target.
include CMakeFiles/Filter.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Filter.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Filter.dir/flags.make

CMakeFiles/Filter.dir/filter.cpp.o: CMakeFiles/Filter.dir/flags.make
CMakeFiles/Filter.dir/filter.cpp.o: filter.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/gzr/opencv-workspace/opencv-lab3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Filter.dir/filter.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Filter.dir/filter.cpp.o -c /home/gzr/opencv-workspace/opencv-lab3/filter.cpp

CMakeFiles/Filter.dir/filter.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Filter.dir/filter.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/gzr/opencv-workspace/opencv-lab3/filter.cpp > CMakeFiles/Filter.dir/filter.cpp.i

CMakeFiles/Filter.dir/filter.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Filter.dir/filter.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/gzr/opencv-workspace/opencv-lab3/filter.cpp -o CMakeFiles/Filter.dir/filter.cpp.s

CMakeFiles/Filter.dir/filter.cpp.o.requires:

.PHONY : CMakeFiles/Filter.dir/filter.cpp.o.requires

CMakeFiles/Filter.dir/filter.cpp.o.provides: CMakeFiles/Filter.dir/filter.cpp.o.requires
	$(MAKE) -f CMakeFiles/Filter.dir/build.make CMakeFiles/Filter.dir/filter.cpp.o.provides.build
.PHONY : CMakeFiles/Filter.dir/filter.cpp.o.provides

CMakeFiles/Filter.dir/filter.cpp.o.provides.build: CMakeFiles/Filter.dir/filter.cpp.o


# Object files for target Filter
Filter_OBJECTS = \
"CMakeFiles/Filter.dir/filter.cpp.o"

# External object files for target Filter
Filter_EXTERNAL_OBJECTS =

Filter: CMakeFiles/Filter.dir/filter.cpp.o
Filter: CMakeFiles/Filter.dir/build.make
Filter: /usr/local/lib/libopencv_shape.so.3.2.0
Filter: /usr/local/lib/libopencv_stitching.so.3.2.0
Filter: /usr/local/lib/libopencv_superres.so.3.2.0
Filter: /usr/local/lib/libopencv_videostab.so.3.2.0
Filter: /usr/local/lib/libopencv_objdetect.so.3.2.0
Filter: /usr/local/lib/libopencv_calib3d.so.3.2.0
Filter: /usr/local/lib/libopencv_features2d.so.3.2.0
Filter: /usr/local/lib/libopencv_flann.so.3.2.0
Filter: /usr/local/lib/libopencv_highgui.so.3.2.0
Filter: /usr/local/lib/libopencv_ml.so.3.2.0
Filter: /usr/local/lib/libopencv_photo.so.3.2.0
Filter: /usr/local/lib/libopencv_video.so.3.2.0
Filter: /usr/local/lib/libopencv_videoio.so.3.2.0
Filter: /usr/local/lib/libopencv_imgcodecs.so.3.2.0
Filter: /usr/local/lib/libopencv_imgproc.so.3.2.0
Filter: /usr/local/lib/libopencv_core.so.3.2.0
Filter: CMakeFiles/Filter.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/gzr/opencv-workspace/opencv-lab3/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Filter"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Filter.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Filter.dir/build: Filter

.PHONY : CMakeFiles/Filter.dir/build

CMakeFiles/Filter.dir/requires: CMakeFiles/Filter.dir/filter.cpp.o.requires

.PHONY : CMakeFiles/Filter.dir/requires

CMakeFiles/Filter.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Filter.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Filter.dir/clean

CMakeFiles/Filter.dir/depend:
	cd /home/gzr/opencv-workspace/opencv-lab3 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/gzr/opencv-workspace/opencv-lab3 /home/gzr/opencv-workspace/opencv-lab3 /home/gzr/opencv-workspace/opencv-lab3 /home/gzr/opencv-workspace/opencv-lab3 /home/gzr/opencv-workspace/opencv-lab3/CMakeFiles/Filter.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Filter.dir/depend
