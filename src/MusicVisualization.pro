    QT       += core gui quick charts qml multimedia

    greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

    INCLUDEPATH += ../lib/rpi_ws281x

    CONFIG += c++11

    SUBDIRS += \
        UnitTest/UnitTest.pro

    SOURCES += \
        AudioSource.cpp \
        LEDThread.cpp \
    SetDevice.cpp \
        WS2812B.cpp \
        main.cpp \
        mainwindow.cpp \
        ../lib/rpi_ws281x/dma.c \
        ../lib/rpi_ws281x/mailbox.c \
        ../lib/rpi_ws281x/pcm.c \
        ../lib/rpi_ws281x/pwm.c \
        ../lib/rpi_ws281x/rpihw.c \
        ../lib/rpi_ws281x/ws2811.c

    HEADERS += \
        AudioSource.h \
        LEDThread.h \
    SetDevice.h \
        WS2812B.h \
        mainwindow.h \
        ../lib/rpi_ws281x/clk.h \
        ../lib/rpi_ws281x/dma.h \
        ../lib/rpi_ws281x/gpio.h \
        ../lib/rpi_ws281x/mailbox.h \
        ../lib/rpi_ws281x/pcm.h \
        ../lib/rpi_ws281x/pwm.h \
        ../lib/rpi_ws281x/rpihw.h \
        ../lib/rpi_ws281x/version.h.in \
        ../lib/rpi_ws281x/ws2811.h

    FORMS += \
        mainwindow.ui

    # Default rules for deployment.
    qnx: target.path = /tmp/$${TARGET}/bin
    else: unix:!android: target.path = /opt/$${TARGET}/bin
    !isEmpty(target.path): INSTALLS += target

    DISTFILES += \
        ../lib/rpi_ws281x/CMakeLists.txt \
        ../lib/rpi_ws281x/DEBIAN/control \
        ../lib/rpi_ws281x/DEBIAN/postinst \
        ../lib/rpi_ws281x/DEBIAN/postrm \
        ../lib/rpi_ws281x/DEBIAN/prerm \
        ../lib/rpi_ws281x/LICENSE \
        ../lib/rpi_ws281x/README.md \
        ../lib/rpi_ws281x/SConscript \
        ../lib/rpi_ws281x/SConstruct \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeCache.txt \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/3.23.2/CMakeCCompiler.cmake \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/3.23.2/CMakeCXXCompiler.cmake \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/3.23.2/CMakeDetermineCompilerABI_C.bin \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/3.23.2/CMakeDetermineCompilerABI_CXX.bin \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/3.23.2/CMakeRCCompiler.cmake \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/3.23.2/CMakeSystem.cmake \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/3.23.2/CompilerIdC/a.exe \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/3.23.2/CompilerIdCXX/a.exe \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/CMakeDirectoryInformation.cmake \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/CMakeOutput.log \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/TargetDirectories.txt \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/clion-environment.txt \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/clion-log.txt \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/cmake.check_cache \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/progress.marks \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/test.dir/DependInfo.cmake \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/test.dir/build.make \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/test.dir/cmake_clean.cmake \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/test.dir/compiler_depend.make \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/test.dir/compiler_depend.ts \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/test.dir/depend.make \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/test.dir/flags.make \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/test.dir/includes_C.rsp \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/test.dir/link.txt \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/test.dir/linklibs.rsp \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/test.dir/objects1.rsp \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/test.dir/progress.make \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/ws2811.dir/DependInfo.cmake \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/ws2811.dir/build.make \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/ws2811.dir/cmake_clean.cmake \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/ws2811.dir/cmake_clean_target.cmake \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/ws2811.dir/compiler_depend.make \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/ws2811.dir/compiler_depend.ts \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/ws2811.dir/depend.make \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/ws2811.dir/flags.make \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/ws2811.dir/includes_C.rsp \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/ws2811.dir/link.txt \
        ../lib/rpi_ws281x/cmake-build-debug/CMakeFiles/ws2811.dir/progress.make \
        ../lib/rpi_ws281x/cmake-build-debug/Testing/Temporary/LastTest.log \
        ../lib/rpi_ws281x/cmake-build-debug/cmake_install.cmake \
        ../lib/rpi_ws281x/cmake-build-debug/libws2811.pc \
        ../lib/rpi_ws281x/cmake-build-debug/rpi_ws281x.cbp \
        ../lib/rpi_ws281x/linux.py \
        ../lib/rpi_ws281x/pkg-config.pc.in \
        ../lib/rpi_ws281x/version \
        ../lib/rpi_ws281x/version.py
