cmake_minimum_required(VERSION 3.16)
project(robox_user_interface)
set(EXE test)

# Set project configuration
if (NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif ()

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_FLAGS "-Wall -Wextra -Wconversion -Wpedantic")
set(CMAKE_CXX_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_RELEASE "-O3")

# Find packages for external libraries
find_package(Threads REQUIRED)
find_package(wxWidgets REQUIRED)

include(${wxWidgets_USE_FILE})

# Include all project directories.
include_directories(include/config)
include_directories(include/driver)
include_directories(include/interfaces)
include_directories(include/utils)
include_directories(src/)

# Set all header files.
file(GLOB HEADERS CONFIGURE_DEPENDS
        "include/config/*.h"
        "include/driver/*.h"
        "include/interfaces/*.h"
        "include/utils/*.h")

# Set all source files.
file(GLOB SOURCES CONFIGURE_DEPENDS
        "src/*.cpp")

# Include and set local libraries
include_directories(lib/serial)
file(GLOB LIB_SERIAL CONFIGURE_DEPENDS "lib/serial/*.h" "lib/serial/*.cpp")

# Create executable
add_executable(${EXE} ${SOURCES} ${HEADERS} ${LIB_SERIAL})

# Link external libraries
target_link_libraries(${EXE} ${wxWidgets_LIBRARIES})
target_link_libraries(${EXE} ${CMAKE_THREAD_LIBS_INIT})

# Install external libraries
install(TARGETS ${EXE} RUNTIME DESTINATION ${PROJECT_SOURCE_DIR})
