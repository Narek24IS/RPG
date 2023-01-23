cmake_minimum_required(VERSION 3.24)
project(RPG)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(RPG
        .idea/.gitignore
        .idea/modules.xml
        .idea/RPG.iml
        .idea/workspace.xml
        global.h
        main.c
        )
