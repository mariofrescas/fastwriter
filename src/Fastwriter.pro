TARGET = Fastwriter
CONFIG += console c++1y

LIBS += -lsfml-graphics -lsfml-window -lsfml-system

INCLUDEPATH += \
           Menu/ \
           ResourceManager/ \
           StateManager/ \
           States/MainMenu/ \
           States/About/ \
           States/DifficultyMenu/ \
           States/Black/ \
           States/Wellcome/ \
           States/Transitions/ \
           States/Transitions/Fade/ \
           States/Transitions/CircleOpen/ \
           States/Transitions/CircleClose/ \
           States/Game/Starting/ \
           States/Game/Starting/Controls/CountDownControl/ \
           States/Game/Started/ \
           States/Game/Started/ConfManager/ \
           States/Game/Started/Confs/ \
           States/Game/Started/Controls/LifesControl/ \
           States/Game/Started/Controls/CleanersControl/ \
           States/Game/Started/Controls/PointsControl/ \
           States/Game/Started/Controls/ShiftModeControl/ \
           States/Game/Started/Controls/TimeControl/ \
           States/Game/Started/Controls/WantPointsControl/ \
           States/Game/Started/Controls/WordControl/ \
           States/Game/Started/Controls/WordControl/Dictionary/ \
           States/Game/Started/Controls/WordControl/WordMap/ \
           States/Game/Paused/ \
           States/Game/Paused/QuitConfirm/ \
           States/Game/Paused/RestartConfirm/

HEADERS += \
           ResourceManager/ResourceHolder.h \
           ResourceManager/ResourceManager.h \
           StateManager/State.h \
           StateManager/StateManager.h \
           States/MainMenu/MainMenu.h \
           States/Wellcome/Wellcome.h \
           States/Game/Started/Started.h \
           States/Game/Started/ConfManager/GameConf.h \
           States/Game/Started/ConfManager/GameConfManager.h \
           States/Game/Started/Confs/NormalConf.h \
           States/Game/Started/Controls/LifesControl/LifesControl.h \
           States/Game/Started/Controls/PointsControl/PointsControl.h \
           States/Game/Started/Controls/ShiftModeControl/ShiftModeControl.h \
           States/Game/Started/Controls/TimeControl/TimeControl.h \
           States/Game/Started/Controls/WordControl/WordControl.h \
           States/Game/Started/Controls/WordControl/Dictionary/Dictionary.h \
           States/Game/Started/Controls/WordControl/WordMap/WordMap.h \
    States/Game/Started/Controls/WantPointsControl/WantPointsControl.h \
    States/Game/Started/Controls/CleanersControl/CleanersControl.h \
    States/Transitions/Transition.h \
    States/Transitions/Fade/Fade.h \
    Menu/GraphicMenu.h \
    States/DifficultyMenu/DifftyMenu.h \
    States/About/About.h \
    States/Game/Starting/Starting.h \
    States/Game/Starting/Controls/CountDownControl/CountDownControl.h \
    States/Transitions/CircleOpen/CircleOpen.h \
    States/Game/Paused/Paused.h \
    States/Transitions/CircleClose/CircleClose.h \
    States/Game/Paused/QuitConfirm/QuitConfirm.h \
    States/Game/Paused/RestartConfirm/RestartConfirm.h \
    States/Game/Started/Confs/ExpertConf.h \
    States/Game/Started/Confs/HardConf.h \
    States/Black/Black.h

SOURCES += \
           Main.cpp \
           ResourceManager/ResourceManager.cpp \
           StateManager/State.cpp \
           StateManager/StateManager.cpp \
           States/MainMenu/MainMenu.cpp \
           States/Wellcome/Wellcome.cpp \
           States/Game/Started/Started.cpp \
           States/Game/Started/ConfManager/GameConf.cpp \
           States/Game/Started/ConfManager/GameConfManager.cpp \
           States/Game/Started/Confs/NormalConf.cpp \
           States/Game/Started/Controls/LifesControl/LifesControl.cpp \
           States/Game/Started/Controls/PointsControl/PointsControl.cpp \
           States/Game/Started/Controls/ShiftModeControl/ShiftModeControl.cpp \
           States/Game/Started/Controls/TimeControl/TimeControl.cpp \
           States/Game/Started/Controls/WordControl/WordControl.cpp \
           States/Game/Started/Controls/WordControl/Dictionary/Dictionary.cpp \
           States/Game/Started/Controls/WordControl/WordMap/WordMap.cpp \
    States/Game/Started/Controls/WantPointsControl/WantPointsControl.cpp \
    States/Game/Started/Controls/CleanersControl/CleanersControl.cpp \
    States/Transitions/Transition.cpp \
    States/Transitions/Fade/Fade.cpp \
    Menu/GraphicMenu.cpp \
    States/DifficultyMenu/DifftyMenu.cpp \
    States/About/About.cpp \
    States/Game/Starting/Starting.cpp \
    States/Game/Starting/Controls/CountDownControl/CountDownControl.cpp \
    States/Transitions/CircleOpen/CircleOpen.cpp \
    States/Game/Paused/Paused.cpp \
    States/Transitions/CircleClose/CircleClose.cpp \
    States/Game/Paused/QuitConfirm/QuitConfirm.cpp \
    States/Game/Paused/RestartConfirm/RestartConfirm.cpp \
    States/Game/Started/Confs/ExpertConf.cpp \
    States/Game/Started/Confs/HardConf.cpp \
    States/Black/Black.cpp
