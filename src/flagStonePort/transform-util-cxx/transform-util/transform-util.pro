# File generated by kdevelop's qmake manager. 
# ------------------------------------------- 
# Subdir relative project main directory: ./../flagStonePort/transform-util-cxx/transform-util
# Target is a library:  
QT       += core gui xml svg

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets
QMAKE_CFLAGS = -fpermissive
QMAKE_CXXFLAGS = -fpermissive
QMAKE_LFLAGS = -fpermissive


INCLUDEPATH += ../../transform-cxx-bsd \
               . 
CONFIG += debug \
          warn_on \
          staticlib 
TEMPLATE = lib 
HEADERS += FSCodec.h \
           FSImageConstructor.h \
           FSShapeConstructor.h \
           FSSoundConstructor.h \
           FSTextConstructor.h \
           FSTransformUtil.h \
           transformutil.h 
SOURCES += FSCodec.cpp \
           FSImageConstructor.cpp \
           FSShapeConstructor.cpp \
           FSSoundConstructor.cpp \
           FSTextConstructor.cpp \
           FSTransformUtil.cpp 