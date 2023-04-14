cmake_minimum_required(VERSION 3.10)
project(MusicVisualizationApp)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall")

find_package(Qt5 COMPONENTS Core Widgets Charts Multimedia REQUIRED)

include_directories(/usr/local/include/ws2811)

set(SRC
  main.cpp
  WS2812B.cpp
  SetDevice.cpp
  LEDThread.cpp
  AudioSource.cpp
  mainwindow.cpp
)

set(HEADERS
  WS2812B.h
  SetDevice.h
  LEDThread.h
  AudioSource.h
  mainwindow.h
  ui_mainwindow.h
)

qt5_wrap_cpp(MOC_SRC ${HEADERS})
qt5_wrap_ui(UI_HEADERS mainwindow.ui)

add_executable(${PROJECT_NAME} ${SRC} ${MOC_SRC} ${UI_HEADERS})

target_link_libraries(${PROJECT_NAME}
  Qt5::Core
  Qt5::Widgets
  Qt5::Charts
  Qt5::Multimedia
  ws2811
  m
)

