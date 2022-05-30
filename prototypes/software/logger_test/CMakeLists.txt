cmake_minimum_required(VERSION 3.16)
project(robox_user_interface)
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

include_directories(lib/config)
include_directories(lib/interfaces)
include_directories(lib/utils)

file(GLOB LIB CONFIGURE_DEPENDS
        "lib/config/*.h"        "lib/config/*.cpp"
        "lib/interfaces/*.h"    "lib/interfaces/*.cpp"
        "lib/utils/*.h"         "lib/utils/*.cpp")

include_directories(frame/)
file(GLOB FRAME CONFIGURE_DEPENDS
        "frame/*.h" "frame/*.cpp")


include_directories(include/utils)
include_directories(include/base)
include_directories(include/widgets)
include_directories(src/)

set(HEADERS
        include/utils/LogToConsole.h
        include/utils/LogToWidget.h
        include/utils/LogMessage.h
        include/utils/Bitmap.h

        include/widgets/LogMessagePanel.h
        include/widgets/ConcreteMessagePanels.h
        include/widgets/ScrolledLogWindow.h
        include/widgets/LogPanel.h
        )
set(SOURCES
        src/LogToConsole.cpp
        src/LogToWidget.cpp
        src/LogMessagePanel.cpp
        src/ConcreteMessagePanels.cpp
        src/ScrolledLogWindow.cpp
        src/LogPanel.cpp
        src/main.cpp)


add_executable(${EXE} ${SOURCES} ${HEADERS} ${LIB} ${FRAME})

target_link_libraries(${EXE} ${wxWidgets_LIBRARIES})
target_link_libraries(${EXE} ${CMAKE_THREAD_LIBS_INIT})

install(TARGETS ${EXE} RUNTIME DESTINATION ${PROJECT_SOURCE_DIR})
