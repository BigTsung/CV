# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.13.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.13.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/aemass.yutsungchiu/Chiu/CV/Common/VideoCapture

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/aemass.yutsungchiu/Chiu/CV/Common/VideoCapture/build

# Include any dependencies generated for this target.
include CMakeFiles/VideoCapture.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/VideoCapture.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/VideoCapture.dir/flags.make

CMakeFiles/VideoCapture.dir/VideoCapture.cpp.o: CMakeFiles/VideoCapture.dir/flags.make
CMakeFiles/VideoCapture.dir/VideoCapture.cpp.o: ../VideoCapture.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/aemass.yutsungchiu/Chiu/CV/Common/VideoCapture/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/VideoCapture.dir/VideoCapture.cpp.o"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/VideoCapture.dir/VideoCapture.cpp.o -c /Users/aemass.yutsungchiu/Chiu/CV/Common/VideoCapture/VideoCapture.cpp

CMakeFiles/VideoCapture.dir/VideoCapture.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/VideoCapture.dir/VideoCapture.cpp.i"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/aemass.yutsungchiu/Chiu/CV/Common/VideoCapture/VideoCapture.cpp > CMakeFiles/VideoCapture.dir/VideoCapture.cpp.i

CMakeFiles/VideoCapture.dir/VideoCapture.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/VideoCapture.dir/VideoCapture.cpp.s"
	/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/aemass.yutsungchiu/Chiu/CV/Common/VideoCapture/VideoCapture.cpp -o CMakeFiles/VideoCapture.dir/VideoCapture.cpp.s

# Object files for target VideoCapture
VideoCapture_OBJECTS = \
"CMakeFiles/VideoCapture.dir/VideoCapture.cpp.o"

# External object files for target VideoCapture
VideoCapture_EXTERNAL_OBJECTS =

VideoCapture: CMakeFiles/VideoCapture.dir/VideoCapture.cpp.o
VideoCapture: CMakeFiles/VideoCapture.dir/build.make
VideoCapture: /usr/local/lib/libopencv_gapi.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_stitching.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_aruco.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_bgsegm.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_bioinspired.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_ccalib.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_dnn_objdetect.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_dpm.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_face.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_freetype.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_fuzzy.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_hfs.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_img_hash.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_line_descriptor.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_reg.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_rgbd.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_saliency.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_sfm.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_stereo.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_structured_light.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_superres.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_surface_matching.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_tracking.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_videostab.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_xfeatures2d.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_xobjdetect.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_xphoto.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_shape.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_phase_unwrapping.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_optflow.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_ximgproc.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_dnn.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_datasets.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_ml.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_plot.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_video.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_objdetect.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_calib3d.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_features2d.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_flann.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_highgui.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_videoio.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_imgcodecs.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_photo.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_imgproc.4.0.1.dylib
VideoCapture: /usr/local/lib/libopencv_core.4.0.1.dylib
VideoCapture: CMakeFiles/VideoCapture.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/aemass.yutsungchiu/Chiu/CV/Common/VideoCapture/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable VideoCapture"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/VideoCapture.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/VideoCapture.dir/build: VideoCapture

.PHONY : CMakeFiles/VideoCapture.dir/build

CMakeFiles/VideoCapture.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/VideoCapture.dir/cmake_clean.cmake
.PHONY : CMakeFiles/VideoCapture.dir/clean

CMakeFiles/VideoCapture.dir/depend:
	cd /Users/aemass.yutsungchiu/Chiu/CV/Common/VideoCapture/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/aemass.yutsungchiu/Chiu/CV/Common/VideoCapture /Users/aemass.yutsungchiu/Chiu/CV/Common/VideoCapture /Users/aemass.yutsungchiu/Chiu/CV/Common/VideoCapture/build /Users/aemass.yutsungchiu/Chiu/CV/Common/VideoCapture/build /Users/aemass.yutsungchiu/Chiu/CV/Common/VideoCapture/build/CMakeFiles/VideoCapture.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/VideoCapture.dir/depend

