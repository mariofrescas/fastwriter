TEMPLATE = app
CONFIG += console c++14
CONFIG -= app_bundle
CONFIG -= qt

LIBS += -lsfml-graphics -lsfml-window -lsfml-system

SOURCES += \
    Main.cpp \
    Menus/ConcreteState.cpp \
    ResourceManager/ResourceHolder.inl \
    ResourceManager/ResourceManager.cpp \
    StateManager/State.cpp \
    StateManager/StateManager.cpp

HEADERS += \
    Menus/ConcreteState.h \
    ResourceManager/ResourceHolder.h \
    ResourceManager/ResourceManager.h \
    StateManager/State.h \
    StateManager/StateManager.h

INCLUDEPATH += \
    Menus \
    ResourceManager \
    StateManager
