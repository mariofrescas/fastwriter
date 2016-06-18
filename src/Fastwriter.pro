TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-graphics -lsfml-window -lsfml-system

SOURCES += \
    Main.cpp \
    ResourceManager/ResourceHolder.inl \
    ResourceManager/ResourceManager.cpp \
    StateManager/State.cpp \
    StateManager/StateManager.cpp \
    Menus/MainMenu.cpp

HEADERS += \
    ResourceManager/ResourceHolder.h \
    ResourceManager/ResourceManager.h \
    StateManager/State.h \
    StateManager/StateManager.h \
    Menus/MainMenu.h

INCLUDEPATH += \
    Menus \
    ResourceManager \
    StateManager
