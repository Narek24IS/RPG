cmake_minimum_required(VERSION 3.24)
project(RPG
        LANGUAGES C)

set(CMAKE_C_STANDARD 11)

include_directories(.)

set(SOURCE
        sourses/main.c
        sourses/heal.c
        sourses/hello.c
        sourses/status.c
        sourses/battle.c
        sourses/looting.c
        sourses/act_choose.c
        sourses/lvl_up_check.c
        sourses/enemy_choose.c
        sourses/global_variables.c
        sourses/player_death_check.c
        sourses/save_the_game.c
        sourses/battle_tutorial.c)

set(HEADER
        includes/global.h
        includes/main.h
        includes/heal.h
        includes/hello.h
        includes/status.h
        includes/battle.h
        includes/looting.h
        includes/act_choose.h
        includes/lvl_up_check.h
        includes/enemy_choose.h
        includes/global_variables.h
        includes/player_death_check.h
        includes/save_the_game.h
        includes/battle_tutorial.h)

add_executable(RPG
        .idea/.gitignore
        .idea/modules.xml
        .idea/RPG.iml
        .idea/workspace.xml
        ${SOURCE}
        ${HEADER})

