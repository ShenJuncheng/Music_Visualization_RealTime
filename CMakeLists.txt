cmake_minimum_required(VERSION 3.21)
project(test_clion)

set(CMAKE_CXX_STANDARD 11)

add_executable(test_clion test_keyboard.cpp )


#set(ZLIB_INCLUDE E:/OneDrive - University of Glasgow/test_clion/lib/DHT-sensor-library-master)
link_directories(E:/OneDrive - University of Glasgow/test_clion/lib/DHT-sensor-library-master/include)
include_directories(E:/OneDrive - University of Glasgow/test_clion/lib/DHT-sensor-library-master/include)