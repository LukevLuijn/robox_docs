cmake_minimum_required(VERSION 3.16)
project (robox_serial_sender)
set (executable_name test)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# find required packages.
find_package(Boost REQUIRED)
find_package(Threads REQUIRED)

#include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include/${PROJECT_NAME})
include_directories(include/${PROJECT_NAME}/)
include_directories(include/serial/)

set(LIB_SERIAL
        include/serial/AsyncSerial.h
        include/serial/AsyncSerial.cpp)

# place library headers here.
set(HEADERS
        include/${PROJECT_NAME}/Console.h)

# place library sources here.
set(SOURCES
        src/Console.cpp)

# remove this.
add_executable(${executable_name} ${HEADERS} ${SOURCES} ${LIB_SERIAL} src/main.cpp)

# link libraries to executable, EX
target_link_libraries(${executable_name} ${Boost_LIBRARIES})
target_link_libraries(${executable_name} ${CMAKE_THREAD_LIBS_INIT})
