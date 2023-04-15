cmake_minimum_required(VERSION 3.1)

project(tests)

find_package(GTest REQUIRED)
find_package(Qt5 COMPONENTS Core Widgets Charts Multimedia REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS} /usr/local/include/ws2811 ${CMAKE_CURRENT_SOURCE_DIR}/..)

add_executable(tests
    test_AudioSource.cpp
    test_SetDevice.cpp
    test_WS2812B.cpp
    ../AudioSource.cpp
    ../SetDevice.cpp
    ../WS2812B.cpp
)
target_link_libraries(tests ${GTEST_BOTH_LIBRARIES} Qt5::Core Qt5::Widgets Qt5::Charts Qt5::Multimedia ws2811 m pthread)

enable_testing()
add_test(NAME all_tests COMMAND tests)
