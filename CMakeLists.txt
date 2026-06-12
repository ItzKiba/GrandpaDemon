cmake_minimum_required(VERSION 3.21)
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
if ("${CMAKE_SYSTEM_NAME}" STREQUAL "iOS" OR IOS)
    set(CMAKE_OSX_ARCHITECTURES "arm64")
else()
    set(CMAKE_OSX_ARCHITECTURES "arm64;x86_64")
endif()
set(CMAKE_CXX_VISIBILITY_PRESET hidden)

project(GrandpaDemon VERSION 1.0.0)

# Use GLOB_RECURSE instead of GLOB
# to recursively add all source files 
# under src/ 
file(GLOB SOURCES
	src/main.cpp
    src/ListManager.h
    src/LevelInfoLayer.cpp
    src/LevelCell.cpp
    src/EffectsManager.h
    src/LevelSearchLayer.cpp
    src/DemonFilterSelectLayer.cpp
    src/LevelBrowserLayer.cpp
    src/CreatorLayer.cpp
    src/ParticleManager.h
)

# Set up the mod binary
add_library(${PROJECT_NAME} SHARED ${SOURCES})

if (NOT DEFINED ENV{GEODE_SDK})
    message(FATAL_ERROR "Unable to find Geode SDK! Please define GEODE_SDK environment variable to point to Geode")
else()
    message(STATUS "Found Geode: $ENV{GEODE_SDK}")
endif()

add_subdirectory($ENV{GEODE_SDK} ${CMAKE_CURRENT_BINARY_DIR}/geode)

# Set up dependencies, resources, link Geode
setup_geode_mod(${PROJECT_NAME})

