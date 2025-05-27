cmake_minimum_required(VERSION 3.16)
project(FlashcardsApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets WebEngineWidgets)

# Add your source files
add_executable(${PROJECT_NAME}
    main.cpp
    src/Card.cpp
    src/Card.hpp
)

target_include_directories(${PROJECT_NAME} PRIVATE src)

# Include Qt headers and link Qt libs
target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Widgets
    Qt5::WebEngineWidgets
    "-Wl,-rpath,/usr/lib/x86_64-linux-gnu"
)

# Set these variables BEFORE add_executable or target properties
set(CMAKE_INSTALL_RPATH "/usr/lib/x86_64-linux-gnu")
set(CMAKE_BUILD_WITH_INSTALL_RPATH TRUE)

# Embed RPATH to system Qt libs path
set_target_properties(${PROJECT_NAME} PROPERTIES
    BUILD_RPATH "/usr/lib/x86_64-linux-gnu"
    INSTALL_RPATH "/usr/lib/x86_64-linux-gnu"
    BUILD_WITH_INSTALL_RPATH TRUE
)