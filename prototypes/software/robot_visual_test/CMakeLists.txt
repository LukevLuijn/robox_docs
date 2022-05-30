cmake_minimum_required(VERSION 3.16)
project(robot_visual)
set(EXE test)

if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif ()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

find_package(Threads REQUIRED)
find_package(wxWidgets REQUIRED)

include(${wxWidgets_USE_FILE})

include_directories(include/frame)
include_directories(include/utils)
include_directories(include/config)
include_directories(src/)

set(HEADERS_CONFIG
        include/config/msg_protocol.h
        include/config/global_config.h
        )
set(HEADERS_UTILS
        include/utils/String.h
        include/utils/Point.h
        include/utils/Kinematics.h
        )
set(HEADERS_FRAME
        include/frame/FrameInterface.h
        include/frame/ManualCtrlFrame.h
        include/frame/DrawPanel.h
        include/frame/RobotDrawPanel.h
        include/frame/ManualCtrl.h
        )
set(SOURCES
        src/ManualCtrlFrame.cpp
        src/DrawPanel.cpp
        src/RobotDrawPanel.cpp
        src/Kinematics.cpp
        src/ManualCtrl.cpp
        src/main.cpp)


add_executable(${EXE} ${SOURCES} ${HEADERS_FRAME} ${HEADERS_UTILS})

target_link_libraries(${EXE} ${wxWidgets_LIBRARIES})
target_link_libraries(${EXE} ${CMAKE_THREAD_LIBS_INIT})

install(TARGETS ${EXE} RUNTIME DESTINATION ${PROJECT_SOURCE_DIR})
