cmake_minimum_required(VERSION 3.21)
project(test_clion)

set(CMAKE_CXX_STANDARD 11)  #宏定义，或者参数设置

add_executable(test_clion src/test_keyboard.cpp)  #添加执行文件


#set(ZLIB_INCLUDE E:/OneDrive - University of Glasgow/test_clion/lib/DHT-sensor-library-master)
link_directories(E:/OneDrive - University of Glasgow/test_clion/lib/DHT-sensor-library-master/include)
include_directories(E:/OneDrive - University of Glasgow/test_clion/lib/DHT-sensor-library-master/include)



#
#https://blog.csdn.net/weixin_43903639/article/details/126691319?utm_medium=distribute.pc_relevant.none-task-blog-2~default~baidujs_baidulandingword~default-1-126691319-blog-89023918.pc_relevant_vip_default&spm=1001.2101.3001.4242.1&utm_relevant_index=4