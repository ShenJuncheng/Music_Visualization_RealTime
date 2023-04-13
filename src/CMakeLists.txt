cmake_minimum_required(VERSION 3.16)

project(YourProjectName LANGUAGES CXX)

# Find and include required Qt libraries
find_package(Qt5 COMPONENTS Core Gui Quick Charts Qml Multimedia REQUIRED)
if(QT5_FOUND)
    message(STATUS "Found Qt ${Qt5_VERSION}")
else()
    message(FATAL_ERROR "Failed to find Qt ${Qt5_VERSION}")
endif()

# Add optional widgets library for Qt 5 or higher
if(Qt5_VERSION VERSION_GREATER 4)
    find_package(Qt5 COMPONENTS Widgets REQUIRED)
    if(Qt5Widgets_FOUND)
        message(STATUS "Found Qt Widgets ${Qt5Widgets_VERSION}")
    else()
        message(FATAL_ERROR "Failed to find Qt Widgets ${Qt5Widgets_VERSION}")
    endif()
endif()

# Set C++ standard to C++11
set(CMAKE_CXX_STANDARD 11)

# Include header files
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/rpi_ws281x)

# Add source files
set(SOURCES
        AudioSource.cpp
        LEDThread.cpp
        WS2812B.cpp
        main.cpp
        mainwindow.cpp
        rpi_ws281x/dma.c
        rpi_ws281x/mailbox.c
        rpi_ws281x/pcm.c
        rpi_ws281x/pwm.c
        rpi_ws281x/rpihw.c
        rpi_ws281x/ws2811.c
        )

# Add header files
set(HEADERS
        AudioSource.h
        LEDThread.h
        WS2812B.h
        mainwindow.h
        rpi_ws281x/clk.h
        rpi_ws281x/dma.h
        rpi_ws281x/gpio.h
        rpi_ws281x/mailbox.h
        rpi_ws281x/pcm.h
        rpi_ws281x/pwm.h
        rpi_ws281x/rpihw.h
        rpi_ws281x/version.h.in
        rpi_ws281x/ws2811.h
        )

# Add UI forms
set(FORMS
        mainwindow.ui
        )

# Add an executable target
add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS} ${FORMS})

# Link libraries
target_link_libraries(${PROJECT_NAME}
        Qt5::Core
        Qt5::Gui
        Qt5::Quick
        Qt5::Charts
        Qt5::Qml
        Qt5::Multimedia
        )

if(Qt5_VERSION VERSION_GREATER 4)
    target_link_libraries(${PROJECT_NAME}
            Qt5::Widgets
            )
endif()
