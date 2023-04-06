cmake_minimum_required(VERSION 3.23)
project(PacmanProject C)

set(CMAKE_C_STANDARD 11)

include_directories(External)
include_directories(External/include)
include_directories(External/include/glad)
include_directories(External/include/GLFW)
include_directories(External/include/KHR)
include_directories(GameMap/inc)
include_directories(GameMap/src)
include_directories(Ghost/inc)
include_directories(Ghost/src)
include_directories(Player)

add_executable(PacmanProject
        External/include/glad/glad.h
        External/include/GLFW/glfw3.h
        External/include/GLFW/glfw3native.h
        External/include/KHR/khrplatform.h
        glad.c
        main.c
        Shader.c
        Shader.h
        Player/PlayerStructure.h
        Player/PlayerStructure.c
        Ghost/GhostStructure.h
        Ghost/GhostStructure.c
        GameMap/GameMapStructure.h
        GameMap/GameMapStructure.c)

find_library(GLFW_LIB glfw3 PATHS C:/glfw-3.3.8.bin.WIN64/lib-mingw-w64)

if(NOT GLFW_LIB)
    message(FATAL_ERROR "glfw3 library not found")
endif()

target_link_libraries(PacmanProject ${GLFW_LIB})
