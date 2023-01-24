cmake_minimum_required(VERSION 3.24)
project(RPG)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)

add_executable(RPG
        .idea/.gitignore
        .idea/modules.xml
        .idea/RPG.iml
        .idea/workspace.xml
        includes/global.h
        sourses/main.c includes/main.h
        sourses/heal.c includes/heal.h
        sourses/hello.c includes/hello.h
        sourses/status.c includes/status.h
        sourses/battle.c includes/battle.h
        sourses/looting.c includes/looting.h
        sourses/act_choose.c includes/act_choose.h
        sourses/lvl_up_check.c includes/lvl_up_check.h
        sourses/enemy_choose.c includes/enemy_choose.h
        sourses/global_variables.c includes/global_variables.h
        sourses/player_death_check.c includes/player_death_check.h)
