MAKEFILE      = Makefile
CC            = gcc
CXX           = g++
DEFINES       = -DQT_NO_DEBUG -DQT_GUI_LIB -DQT_CORE_LIB
CFLAGS        = -pipe -O2 -Wall -Wextra -D_REENTRANT -fPIC $(DEFINES)
CXXFLAGS      = -pipe -O2 -std=gnu++1z -Wall -Wextra -D_REENTRANT -fPIC $(DEFINES)
INCPATH       = -I. -I../../../../recipe-sysroot-native/usr/include -I../../../../recipe-sysroot-native/usr/include/QtGui -I../../../../recipe-sysroot-native/usr/include/QtCore -I. -I../../../../recipe-sysroot-native/usr/lib/mkspecs/linux-g++
LFLAGS        = -Wl,-O1 -Wl,-rpath,../../../../recipe-sysroot-native/usr/lib -Wl,-rpath-link,../../../../recipe-sysroot-native/usr/lib
LIBS          = -L../../../../recipe-sysroot-native/usr/lib/ -lQt6Gui -lQt6Core -lpthread   

####### Output directory
OBJECTS_DIR   = ./
SOURCES       = main.cpp 
OBJECTS       = main.o
DESTDIR       = 
TARGET        = ImagePoolCreator


first: all

ImagePoolCreator:  $(SOURCES)  
	$(CXX) -c $(CXXFLAGS) $(INCPATH) -o main.o main.cpp
	$(CXX) $(LFLAGS) -o $(TARGET) $(OBJECTS) $(OBJCOMP) $(LIBS)

all: ImagePoolCreator
