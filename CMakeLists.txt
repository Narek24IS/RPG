cmake_minimum_required(VERSION 3.24)
project(RPG)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(RPG
        .idea/.gitignore
        .idea/modules.xml
        .idea/RPG.iml
        .idea/workspace.xml
        headers/global.h
        main.c headers/main.h
        heal.c headers/heal.h
        hello.c headers/hello.h
        status.c headers/status.h
        battle.c headers/battle.h
        looting.c headers/looting.h
        act_choose.c headers/act_choose.h
        lvl_up_check.c headers/lvl_up_check.h
        enemy_choose.c headers/enemy_choose.h
        global_variables.c headers/global_variables.h
        player_death_check.c headers/player_death_check.h)
