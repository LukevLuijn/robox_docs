cmake_minimum_required(VERSION 3.16)
project(robox_gui)

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

include_directories(include/robox)
include_directories(src/)

set(BASE
        include/base/Controller.h
        include/base/MainFrame.h)
set(MODEL
        include/model/Device.h
        include/model/Component.h
        include/model/LDR.h
        include/model/LED.h
        include/model/CPWire.h
        include/model/Buzzer.h)
set(VIEW
        include/view/DrawPanel.h
        include/view/LEDPanel.h
        include/view/ConcreteLEDPanels.h
        )

set(HEADERS
        include/robox/MainApp.h
        include/robox/MainFrame.h)
set(SOURCES
        src/main.cpp
        src/MainApp.cpp
        src/MainFrame.cpp)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})

target_link_libraries(${PROJECT_NAME} ${wxWidgets_LIBRARIES})
target_link_libraries(${PROJECT_NAME} ${CMAKE_THREAD_LIBS_INIT})

install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION ${PROJECT_SOURCE_DIR})
