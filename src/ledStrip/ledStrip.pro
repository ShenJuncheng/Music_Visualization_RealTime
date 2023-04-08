QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

INCLUDEPATH += $$PWD/rpi_ws281x

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    LEDThread.cpp \
    WS2812B.cpp \
    main.cpp \
    mainwindow.cpp \
    rpi_ws281x/dma.c \
    rpi_ws281x/mailbox.c \
    rpi_ws281x/pcm.c \
    rpi_ws281x/pwm.c \
    rpi_ws281x/rpihw.c \
    rpi_ws281x/ws2811.c

HEADERS += \
    LEDThread.h \
    WS2812B.h \
    mainwindow.h \
    rpi_ws281x/clk.h \
    rpi_ws281x/dma.h \
    rpi_ws281x/gpio.h \
    rpi_ws281x/mailbox.h \
    rpi_ws281x/pcm.h \
    rpi_ws281x/pwm.h \
    rpi_ws281x/rpihw.h \
    rpi_ws281x/version.h.in \
    rpi_ws281x/ws2811.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    rpi_ws281x/CMakeLists.txt \
    rpi_ws281x/DEBIAN/control \
    rpi_ws281x/DEBIAN/postinst \
    rpi_ws281x/DEBIAN/postrm \
    rpi_ws281x/DEBIAN/prerm \
    rpi_ws281x/LICENSE \
    rpi_ws281x/README.md \
    rpi_ws281x/SConscript \
    rpi_ws281x/SConstruct \
    rpi_ws281x/cmake-build-debug/CMakeCache.txt \
    rpi_ws281x/cmake-build-debug/CMakeFiles/3.23.2/CMakeCCompiler.cmake \
    rpi_ws281x/cmake-build-debug/CMakeFiles/3.23.2/CMakeCXXCompiler.cmake \
    rpi_ws281x/cmake-build-debug/CMakeFiles/3.23.2/CMakeDetermineCompilerABI_C.bin \
    rpi_ws281x/cmake-build-debug/CMakeFiles/3.23.2/CMakeDetermineCompilerABI_CXX.bin \
    rpi_ws281x/cmake-build-debug/CMakeFiles/3.23.2/CMakeRCCompiler.cmake \
    rpi_ws281x/cmake-build-debug/CMakeFiles/3.23.2/CMakeSystem.cmake \
    rpi_ws281x/cmake-build-debug/CMakeFiles/3.23.2/CompilerIdC/a.exe \
    rpi_ws281x/cmake-build-debug/CMakeFiles/3.23.2/CompilerIdCXX/a.exe \
    rpi_ws281x/cmake-build-debug/CMakeFiles/CMakeDirectoryInformation.cmake \
    rpi_ws281x/cmake-build-debug/CMakeFiles/CMakeOutput.log \
    rpi_ws281x/cmake-build-debug/CMakeFiles/TargetDirectories.txt \
    rpi_ws281x/cmake-build-debug/CMakeFiles/clion-environment.txt \
    rpi_ws281x/cmake-build-debug/CMakeFiles/clion-log.txt \
    rpi_ws281x/cmake-build-debug/CMakeFiles/cmake.check_cache \
    rpi_ws281x/cmake-build-debug/CMakeFiles/progress.marks \
    rpi_ws281x/cmake-build-debug/CMakeFiles/test.dir/DependInfo.cmake \
    rpi_ws281x/cmake-build-debug/CMakeFiles/test.dir/build.make \
    rpi_ws281x/cmake-build-debug/CMakeFiles/test.dir/cmake_clean.cmake \
    rpi_ws281x/cmake-build-debug/CMakeFiles/test.dir/compiler_depend.make \
    rpi_ws281x/cmake-build-debug/CMakeFiles/test.dir/compiler_depend.ts \
    rpi_ws281x/cmake-build-debug/CMakeFiles/test.dir/depend.make \
    rpi_ws281x/cmake-build-debug/CMakeFiles/test.dir/flags.make \
    rpi_ws281x/cmake-build-debug/CMakeFiles/test.dir/includes_C.rsp \
    rpi_ws281x/cmake-build-debug/CMakeFiles/test.dir/link.txt \
    rpi_ws281x/cmake-build-debug/CMakeFiles/test.dir/linklibs.rsp \
    rpi_ws281x/cmake-build-debug/CMakeFiles/test.dir/objects1.rsp \
    rpi_ws281x/cmake-build-debug/CMakeFiles/test.dir/progress.make \
    rpi_ws281x/cmake-build-debug/CMakeFiles/ws2811.dir/DependInfo.cmake \
    rpi_ws281x/cmake-build-debug/CMakeFiles/ws2811.dir/build.make \
    rpi_ws281x/cmake-build-debug/CMakeFiles/ws2811.dir/cmake_clean.cmake \
    rpi_ws281x/cmake-build-debug/CMakeFiles/ws2811.dir/cmake_clean_target.cmake \
    rpi_ws281x/cmake-build-debug/CMakeFiles/ws2811.dir/compiler_depend.make \
    rpi_ws281x/cmake-build-debug/CMakeFiles/ws2811.dir/compiler_depend.ts \
    rpi_ws281x/cmake-build-debug/CMakeFiles/ws2811.dir/depend.make \
    rpi_ws281x/cmake-build-debug/CMakeFiles/ws2811.dir/flags.make \
    rpi_ws281x/cmake-build-debug/CMakeFiles/ws2811.dir/includes_C.rsp \
    rpi_ws281x/cmake-build-debug/CMakeFiles/ws2811.dir/link.txt \
    rpi_ws281x/cmake-build-debug/CMakeFiles/ws2811.dir/progress.make \
    rpi_ws281x/cmake-build-debug/Testing/Temporary/LastTest.log \
    rpi_ws281x/cmake-build-debug/cmake_install.cmake \
    rpi_ws281x/cmake-build-debug/libws2811.pc \
    rpi_ws281x/cmake-build-debug/rpi_ws281x.cbp \
    rpi_ws281x/linux.py \
    rpi_ws281x/pkg-config.pc.in \
    rpi_ws281x/version \
    rpi_ws281x/version.py
