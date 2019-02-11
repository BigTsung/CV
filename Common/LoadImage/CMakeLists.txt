# Required by CMake 3.6
CMAKE_MINIMUM_REQUIRED(VERSION 3.6)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

find_package(OpenCV REQUIRED)

ADD_EXECUTABLE(LoadImage LoadImage.cpp)

TARGET_LINK_LIBRARIES(LoadImage ${OpenCV_LIBS})