CXX = g++
CXXFLAGS = -std=c++11 -Wall -I /usr/local/include/ws2811 -I/usr/include/arm-linux-gnueabihf/qt5 -I/usr/include/arm-linux-gnueabihf/qt5/QtWidgets -I/usr/include/arm-linux-gnueabihf/qt5/QtCore -I/usr/include/arm-linux-gnueabihf/qt5/QtCharts -I/usr/include/arm-linux-gnueabihf/qt5/QtMultimedia

LDFLAGS = -L/usr/lib/arm-linux-gnueabihf -l ws2811 -l Qt5Core -l Qt5Widgets -l Qt5Charts -l Qt5Multimedia -lm
TARGET = app

SRC = main.cpp WS2812B.cpp SetDevice.cpp LEDThread.cpp AudioSource.cpp mainwindow.cpp
OBJ = $(SRC:.cpp=.o)
MOC = moc
MOCFILES = moc_mainwindow.cpp moc_SetDevice.cpp moc_LEDThread.cpp moc_AudioSource.cpp
MOC_OBJ = $(MOCFILES:.cpp=.o)

all: $(TARGET) $(MOCFILES)

$(TARGET): $(OBJ) $(MOC_OBJ)
	$(CXX) $(CXXFLAGS) -o $@ $(OBJ) $(MOC_OBJ) $(LDFLAGS)

%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

moc_%.cpp: %.h
	$(MOC) $< -o $@

ui_mainwindow.h: mainwindow.ui
	uic mainwindow.ui -o ui_mainwindow.h

mainwindow.o: mainwindow.cpp ui_mainwindow.h
	$(CXX) $(CXXFLAGS) -c mainwindow.cpp -o mainwindow.o

clean:
	rm -f $(TARGET) $(OBJ) $(MOCFILES) $(MOC_OBJ) ui_mainwindow.h

.PHONY: all clean
