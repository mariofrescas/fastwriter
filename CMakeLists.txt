cmake_minimum_required(VERSION 3.6.0)

project(Fastwriter)
set(PROJECT_VERSION_MAJOR 1)
set(PROJECT_VERSION_MINOR 0)
set(PROJECT_VERSION_PATCH 0)

set(EXECUTABLE_NAME fastwriter-bin)
set(LAUNCHER_NAME fastwriter)
set(DESKTOPFILE_NAME fastwriter.desktop)

set(RES_PATH ${PROJECT_SOURCE_DIR}/res)

set(INSTALL_PATH_BIN bin)
set(INSTALL_PATH_EXECUTABLE ${INSTALL_PATH_BIN}/${PROJECT_NAME})
set(INSTALL_PATH_LAUNCHER ${INSTALL_PATH_BIN})
set(INSTALL_PATH_RES share/${PROJECT_NAME})
set(INSTALL_PATH_DESKTOPFILE /usr/share/applications)

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
configure_file(
    ${PROJECT_SOURCE_DIR}/build-tools/fastwriter.desktop.in
    ${PROJECT_BINARY_DIR}/${DESKTOPFILE_NAME}
)
file(COPY ${RES_PATH} DESTINATION ${PROJECT_BINARY_DIR}/)

find_package(SFML 2 REQUIRED system window graphics audio)

include_directories(
    ${PROJECT_BINARY_DIR}
    src/ConfManager/
    src/Confs/
    src/Controls/
    src/Dictionary/
    src/Game/
    src/Gui/
    src/MusicPlayer/
    src/ResourceManager/
    src/SoundPlayer/
    src/StateManager/
    src/States/
    src/Transitions/
    src/WordMap/
)

set(SOURCES
    src/ConfManager/GameConf.cpp
    src/ConfManager/GameConfManager.cpp
    src/Confs/ExpertConf.cpp
    src/Confs/HardConf.cpp
    src/Confs/NormalConf.cpp
    src/Controls/CleanersControl.cpp
    src/Controls/CountDownControl.cpp
    src/Controls/LifesControl.cpp
    src/Controls/PointsControl.cpp
    src/Controls/ResultsControl.cpp
    src/Controls/ShiftModeControl.cpp
    src/Controls/TimeControl.cpp
    src/Controls/WantPointsControl.cpp
    src/Controls/WordControl.cpp
    src/Dictionary/Dictionary.cpp
    src/Game/Game.cpp
    src/Gui/BidirectionalBar.cpp
    src/Gui/GraphicMenu.cpp
    src/Gui/OneDirectionBar.cpp
    src/Gui/TextureBar.cpp
    src/Gui/TextureNumber.inl
    src/MusicPlayer/MusicPlayer.cpp
    src/ResourceManager/ResourceManager.cpp
    src/ResourceManager/ResourceHolder.inl
    src/SoundPlayer/SoundPlayer.cpp
    src/StateManager/State.cpp
    src/StateManager/StateManager.cpp
    src/States/About.cpp
    src/States/Black.cpp
    src/States/DifftyMenu.cpp
    src/States/Help.cpp
    src/States/MainMenu.cpp
    src/States/Paused.cpp
    src/States/QuitConfirm.cpp
    src/States/RestartConfirm.cpp
    src/States/Results.cpp
    src/States/Started.cpp
    src/States/Starting.cpp
    src/States/Wellcome.cpp
    src/Transitions/CircleClose.cpp
    src/Transitions/CircleOpen.cpp
    src/Transitions/Fade.cpp
    src/Transitions/Transition.cpp
    src/WordMap/WordMap.cpp
    src/Main.cpp
)

add_executable(${EXECUTABLE_NAME} ${SOURCES})
if(SFML_FOUND)
    include_directories(${SFML_INCLUDE_DIR})
    target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})
endif()

install(TARGETS ${EXECUTABLE_NAME} DESTINATION ${INSTALL_PATH_EXECUTABLE})
install(PROGRAMS ${PROJECT_BINARY_DIR}/${LAUNCHER_NAME} DESTINATION ${INSTALL_PATH_LAUNCHER})
install(PROGRAMS ${PROJECT_BINARY_DIR}/${DESKTOPFILE_NAME} DESTINATION ${INSTALL_PATH_DESKTOPFILE})
install(DIRECTORY ${RES_PATH} DESTINATION ${INSTALL_PATH_RES})

include(InstallRequiredSystemLibraries)
    set(CPACK_RESOURCE_FILE_LICENSE ${LICENSE_PATH})
    set(CPACK_PACKAGE_VERSION_MAJOR ${PROJECT_VERSION_MAJOR})
    set(CPACK_PACKAGE_VERSION_MINOR ${PROJECT_VERSION_MINOR})
    set(CPACK_PACKAGE_VERSION_PATCH ${PROJECT_VERSION_PATCH})
include(CPack)
