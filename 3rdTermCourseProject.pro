TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    cexpression.cpp \
    chromosome.cpp \
    adjacencymatrix.cpp \
    operandsmatrix.cpp \
    operatormatrix.cpp \
    population.cpp

HEADERS += \
    cexpression.h \
    chromosome.h \
    adjacencymatrix.h \
    operandsmatrix.h \
    operatormatrix.h \
    population.h

