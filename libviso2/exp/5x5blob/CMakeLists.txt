cmake_minimum_required( VERSION 2.8 )
project(detector)
 
set( CMAKE_CXX_FLAGS "-std=c++17 -O3")
find_package(OpenCV)
include_directories(${OpenCV})
 
add_executable(detector 5x5blob.cpp)
# 链接OpenCV库
target_link_libraries(detector ${OpenCV_LIBS})