cmake_minimum_required(VERSION 3.6.0)

project(Fastwriter)
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)

set(EXECUTABLE_NAME fastwriter-bin)
set(LAUNCHER_NAME fastwriter)

set(RES_PATH ${PROJECT_SOURCE_DIR}/res)

set(INSTALL_PATH_BIN bin)
set(INSTALL_PATH_EXECUTABLE ${INSTALL_PATH_BIN}/${PROJECT_NAME})
set(INSTALL_PATH_LAUNCHER ${INSTALL_PATH_BIN})
set(INSTALL_PATH_RES share/${PROJECT_NAME})

set(INSTALL_FULLPATH_EXEC ${CMAKE_INSTALL_PREFIX}/${INSTALL_PATH_EXECUTABLE})
set(INSTALL_FULLPATH_LAUNCHER ${CMAKE_INSTALL_PREFIX}/${INSTALL_PATH_LAUNCHER})
set(INSTALL_FULLPATH_RES ${CMAKE_INSTALL_PREFIX}/${INSTALL_PATH_RES})

set(LICENSE_PATH ${CMAKE_SOURCE_DIR}/LICENSE)
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})

configure_file(
    ${PROJECT_SOURCE_DIR}/src/Config/Config.h.in
    ${PROJECT_BINARY_DIR}/Config.h
)
configure_file(
    ${PROJECT_SOURCE_DIR}/build-tools/fastwriter-launcher.sh.in
    ${PROJECT_BINARY_DIR}/${LAUNCHER_NAME}
)
file(COPY ${RES_PATH} DESTINATION ${PROJECT_BINARY_DIR}/)

find_package(SFML 2 REQUIRED system window graphics audio)

include_directories(
    ${PROJECT_BINARY_DIR}
    src/Game/
    src/Gui/
    src/ResourceManager/
    src/MusicPlayer/
    src/SoundPlayer/
    src/StateManager/
    src/Transitions/
    src/Transitions/CircleClose/
    src/Transitions/CircleOpen/
    src/Transitions/Fade/
    src/States/About/
    src/States/Black/
    src/States/DifficultyMenu/
    src/States/MainMenu/
    src/States/Wellcome/
    src/States/Game/Paused/
    src/States/Game/Paused/QuitConfirm/
    src/States/Game/Paused/RestartConfirm/
    src/States/Game/Starting/
    src/States/Game/Starting/Controls/CountDownControl/
    src/States/Game/Started/
    src/States/Game/Started/ConfManager/
    src/States/Game/Started/Confs/
    src/States/Game/Started/Controls/CleanersControl/
    src/States/Game/Started/Controls/LifesControl/
    src/States/Game/Started/Controls/PointsControl/
    src/States/Game/Started/Controls/ShiftModeControl/
    src/States/Game/Started/Controls/TimeControl/
    src/States/Game/Started/Controls/WantPointsControl/
    src/States/Game/Started/Controls/WordControl/
    src/States/Game/Started/Controls/WordControl/Dictionary/
    src/States/Game/Started/Controls/WordControl/WordMap/
)

set(SOURCES
    src/Main.cpp
    src/Game/Game.cpp
    src/Gui/GraphicMenu.cpp
    src/ResourceManager/ResourceManager.cpp
    src/ResourceManager/ResourceHolder.inl
    src/MusicPlayer/MusicPlayer.cpp
    src/SoundPlayer/SoundPlayer.cpp
    src/StateManager/State.cpp
    src/StateManager/StateManager.cpp
    src/Transitions/Transition.cpp
    src/Transitions/CircleClose/CircleClose.cpp
    src/Transitions/CircleOpen/CircleOpen.cpp
    src/Transitions/Fade/Fade.cpp
    src/States/About/About.cpp
    src/States/Black/Black.cpp
    src/States/DifficultyMenu/DifftyMenu.cpp
    src/States/MainMenu/MainMenu.cpp
    src/States/Wellcome/Wellcome.cpp
    src/States/Game/Paused/Paused.cpp
    src/States/Game/Paused/QuitConfirm/QuitConfirm.cpp
    src/States/Game/Paused/RestartConfirm/RestartConfirm.cpp
    src/States/Game/Starting/Starting.cpp
    src/States/Game/Starting/Controls/CountDownControl/CountDownControl.cpp
    src/States/Game/Started/Started.cpp
    src/States/Game/Started/ConfManager/GameConf.cpp
    src/States/Game/Started/ConfManager/GameConfManager.cpp
    src/States/Game/Started/Confs/ExpertConf.cpp
    src/States/Game/Started/Confs/HardConf.cpp
    src/States/Game/Started/Confs/NormalConf.cpp
    src/States/Game/Started/Controls/CleanersControl/CleanersControl.cpp
    src/States/Game/Started/Controls/LifesControl/LifesControl.cpp
    src/States/Game/Started/Controls/PointsControl/PointsControl.cpp
    src/States/Game/Started/Controls/ShiftModeControl/ShiftModeControl.cpp
    src/States/Game/Started/Controls/TimeControl/TimeControl.cpp
    src/States/Game/Started/Controls/WantPointsControl/WantPointsControl.cpp
    src/States/Game/Started/Controls/WordControl/WordControl.cpp
    src/States/Game/Started/Controls/WordControl/Dictionary/Dictionary.cpp
    src/States/Game/Started/Controls/WordControl/WordMap/WordMap.cpp
)

add_executable(${EXECUTABLE_NAME} ${SOURCES})
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

install(TARGETS ${EXECUTABLE_NAME} DESTINATION ${INSTALL_PATH_EXECUTABLE})
install(FILES ${PROJECT_BINARY_DIR}/${LAUNCHER_NAME} DESTINATION ${INSTALL_PATH_LAUNCHER}
        PERMISSIONS WORLD_READ WORLD_EXECUTE)
install(DIRECTORY ${RES_PATH} DESTINATION ${INSTALL_PATH_RES})

include(InstallRequiredSystemLibraries)
    set(CPACK_RESOURCE_FILE_LICENSE ${LICENSE_PATH})
    set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
    set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
    set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
include(CPack)

