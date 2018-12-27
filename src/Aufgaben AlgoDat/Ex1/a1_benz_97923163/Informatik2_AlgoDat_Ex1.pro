TEMPLATE = app
CONFIG += console
CONFIG -= app_bundle
CONFIG -= qt

QMAKE_CFLAGS += -std=c99

SOURCES += \
    main.c \
    task1.c \
    task3.c \
    task2.c \
    task5.c \
    task6.c \
    task4.c \
    task7b.c \
    task7a.c

# this is the important part
#It means add the library GLU; GL; glut
#to the list of libraries to link.
unix|win32: LIBS += -lGLU
unix|win32: LIBS += -lGL
unix|win32: LIBS += -lglut
