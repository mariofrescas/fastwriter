TARGET = Fastwriter
CONFIG += console c++1y

LIBS += -lsfml-graphics -lsfml-window -lsfml-system -lsfml-audio

INCLUDEPATH += \
           Gui/ \
           ResourceManager/ \
           SoundPlayer/ \
           MusicPlayer/ \
           StateManager/ \
           Transitions/ \
           States/About/ \
           States/Black/ \
           States/DifficultyMenu/ \
           States/MainMenu/ \
           States/Wellcome/ \
           Transitions/CircleClose/ \
           Transitions/CircleOpen/ \
           Transitions/Fade/ \
           States/Game/Paused/ \
           States/Game/Started/ \
           States/Game/Starting/ \
           States/Game/Paused/QuitConfirm/ \
           States/Game/Paused/RestartConfirm/ \
           States/Game/Started/ConfManager/ \
           States/Game/Started/Confs/ \
           States/Game/Started/Controls/CleanersControl/ \
           States/Game/Started/Controls/LifesControl/ \
           States/Game/Started/Controls/PointsControl/ \
           States/Game/Started/Controls/ShiftModeControl/ \
           States/Game/Started/Controls/TimeControl/ \
           States/Game/Started/Controls/WantPointsControl/ \
           States/Game/Started/Controls/WordControl/ \
           States/Game/Starting/Controls/CountDownControl/ \
           States/Game/Started/Controls/WordControl/Dictionary/ \
           States/Game/Started/Controls/WordControl/WordMap/

HEADERS += \
           Gui/GraphicMenu.h \
           ResourceManager/ResourceHolder.h \
           ResourceManager/ResourceManager.h \
           MusicPlayer/MusicPlayer.h \
           SoundPlayer/SoundPlayer.h \
           StateManager/State.h \
           StateManager/StateManager.h \
           Transitions/Transition.h \
           States/About/About.h \
           States/Black/Black.h \
           States/DifficultyMenu/DifftyMenu.h \
           States/MainMenu/MainMenu.h \
           States/Wellcome/Wellcome.h \
           Transitions/CircleClose/CircleClose.h \
           Transitions/CircleOpen/CircleOpen.h \
           Transitions/Fade/Fade.h \
           States/Game/Paused/Paused.h \
           States/Game/Started/Started.h \
           States/Game/Starting/Starting.h \
           States/Game/Paused/QuitConfirm/QuitConfirm.h \
           States/Game/Paused/RestartConfirm/RestartConfirm.h \
           States/Game/Started/ConfManager/GameConf.h \
           States/Game/Started/ConfManager/GameConfManager.h \
           States/Game/Started/Confs/ExpertConf.h \
           States/Game/Started/Confs/HardConf.h \
           States/Game/Started/Confs/NormalConf.h \
           States/Game/Started/Controls/CleanersControl/CleanersControl.h \
           States/Game/Started/Controls/LifesControl/LifesControl.h \
           States/Game/Started/Controls/PointsControl/PointsControl.h \
           States/Game/Started/Controls/ShiftModeControl/ShiftModeControl.h \
           States/Game/Started/Controls/TimeControl/TimeControl.h \
           States/Game/Started/Controls/WantPointsControl/WantPointsControl.h \
           States/Game/Started/Controls/WordControl/WordControl.h \
           States/Game/Starting/Controls/CountDownControl/CountDownControl.h \
           States/Game/Started/Controls/WordControl/Dictionary/Dictionary.h \
           States/Game/Started/Controls/WordControl/WordMap/WordMap.h

SOURCES += \
           Main.cpp \
           Gui/GraphicMenu.cpp \
           ResourceManager/ResourceManager.cpp \
           MusicPlayer/MusicPlayer.cpp \
           SoundPlayer/SoundPlayer.cpp \
           StateManager/State.cpp \
           StateManager/StateManager.cpp \
           Transitions/Transition.cpp \
           States/About/About.cpp \
           States/Black/Black.cpp \
           States/DifficultyMenu/DifftyMenu.cpp \
           States/MainMenu/MainMenu.cpp \
           States/Wellcome/Wellcome.cpp \
           Transitions/CircleClose/CircleClose.cpp \
           Transitions/CircleOpen/CircleOpen.cpp \
           Transitions/Fade/Fade.cpp \
           States/Game/Paused/Paused.cpp \
           States/Game/Started/Started.cpp \
           States/Game/Starting/Starting.cpp \
           States/Game/Paused/QuitConfirm/QuitConfirm.cpp \
           States/Game/Paused/RestartConfirm/RestartConfirm.cpp \
           States/Game/Started/ConfManager/GameConf.cpp \
           States/Game/Started/ConfManager/GameConfManager.cpp \
           States/Game/Started/Confs/ExpertConf.cpp \
           States/Game/Started/Confs/HardConf.cpp \
           States/Game/Started/Confs/NormalConf.cpp \
           States/Game/Started/Controls/CleanersControl/CleanersControl.cpp \
           States/Game/Started/Controls/LifesControl/LifesControl.cpp \
           States/Game/Started/Controls/PointsControl/PointsControl.cpp \
           States/Game/Started/Controls/ShiftModeControl/ShiftModeControl.cpp \
           States/Game/Started/Controls/TimeControl/TimeControl.cpp \
           States/Game/Started/Controls/WantPointsControl/WantPointsControl.cpp \
           States/Game/Started/Controls/WordControl/WordControl.cpp \
           States/Game/Starting/Controls/CountDownControl/CountDownControl.cpp \
           States/Game/Started/Controls/WordControl/Dictionary/Dictionary.cpp \
           States/Game/Started/Controls/WordControl/WordMap/WordMap.cpp
