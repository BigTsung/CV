# Required by CMake 3.6
CMAKE_MINIMUM_REQUIRED(VERSION 3.6)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=gnu++11")

find_package(OpenCV REQUIRED)

ADD_EXECUTABLE(HandDetection HandDetection.cpp)

TARGET_LINK_LIBRARIES(HandDetection ${OpenCV_LIBS})