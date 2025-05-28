cmake_minimum_required(VERSION 3.16)
project(FlashcardsApp)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTORCC ON)
set(CMAKE_AUTOUIC ON)

find_package(Qt5 REQUIRED COMPONENTS Core Widgets WebEngineWidgets Sql)

set(SOURCES
    main.cpp
    src/Card.cpp
    src/Database.cpp
    src/webviewwindow.cpp
)

set(HEADERS
    src/Card.hpp
    src/Database.hpp
    src/webviewwindow.hpp
)

add_executable(FlashcardsApp ${SOURCES} ${HEADERS})

target_include_directories(${PROJECT_NAME} PRIVATE src)

# Include Qt headers and link Qt libs
target_link_libraries(${PROJECT_NAME}
    Qt5::Core
    Qt5::Widgets
    Qt5::WebEngineWidgets
    Qt5::Sql
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