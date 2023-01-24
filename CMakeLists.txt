cmake_minimum_required(VERSION 3.24)
project(RPG)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(RPG
        .idea/.gitignore
        .idea/modules.xml
        .idea/RPG.iml
        .idea/workspace.xml
        src/global.h
        main.c src/main.h
        heal.c src/heal.h
        hello.c src/hello.h
        status.c src/status.h
        battle.c src/battle.h
        looting.c src/looting.h
        act_choose.c src/act_choose.h
        lvl_up_check.c src/lvl_up_check.h
        enemy_choose.c src/enemy_choose.h
        global_variables.c src/global_variables.h
        player_death_check.c src/player_death_check.h)
