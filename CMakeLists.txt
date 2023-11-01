cmake_minimum_required(VERSION 3.0.0)

# project name 
project(hyperengine)

# C++17
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

# Create compile_commands.json for clangd
set(CMAKE_EXPORT_COMPILE_COMMANDS 1)

# Enable warnings
add_compile_options(-Wall -Wextra -Wpedantic)

message(STATUS "Is the C++ compiler loaded? ${CMAKE_CXX_COMPILER_LOADED}")
if(CMAKE_CXX_COMPILER_LOADED)
 message(STATUS "The C++ compiler ID is: ${CMAKE_CXX_COMPILER_ID}")
 message(STATUS "Is the C++ from GNU? ${CMAKE_COMPILER_IS_GNUCXX}")
 message(STATUS "The C++ compiler version is: ${CMAKE_CXX_COMPILER_VERSION}")
endif()
 
message(STATUS "Is the C compiler loaded? ${CMAKE_C_COMPILER_LOADED}")
if(CMAKE_C_COMPILER_LOADED)
 message(STATUS "The C compiler ID is: ${CMAKE_C_COMPILER_ID}")
 message(STATUS "Is the C from GNU? ${CMAKE_COMPILER_IS_GNUCC}")
 message(STATUS "The C compiler version is: ${CMAKE_C_COMPILER_VERSION}")
endif()

# Default to a release build
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

###############
# HyperEngine #
###############

# define the hyperengine static library
file(GLOB_RECURSE hyperengine_source RELATIVE ${PROJECT_SOURCE_DIR} HyperEngine/src/**/*.cpp) 
add_library(
    hyperengine STATIC 
    ${hyperengine_source}
)
target_compile_definitions(hyperengine PRIVATE HE_PLATFORM_MACOS)

# Include directories for the hyperengine 
target_include_directories(hyperengine PUBLIC 
                            "${PROJECT_SOURCE_DIR}/"
                            "${PROJECT_SOURCE_DIR}/HyperEngine"
                            "${PROJECT_SOURCE_DIR}/HyperEngine/vendor/spdlog/include"
                            )

# Precompile the hyperengine
target_precompile_headers(hyperengine PRIVATE 
                            "${PROJECT_SOURCE_DIR}/HyperEngine/hepch.hpp"
)       
###############
#   Sandbox   #
###############

# Define sandbox application
file(GLOB sandbox_sources RELATIVE ${PROJECT_SOURCE_DIR}  Sandbox/*.cpp)
add_executable(sandbox ${sandbox_sources})

# Include directories for the sandbox application
target_include_directories(sandbox PUBLIC "${PROJECT_SOURCE_DIR}/Sandbox")

# Link sandbox with the hyperengine library
target_link_libraries(sandbox PUBLIC hyperengine)