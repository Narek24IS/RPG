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
        player_death_check.c player_death_check.h battle.c battle.h main.h lvl_up_check.c lvl_up_check.h act_choose.c act_choose.h heal.c heal.h hello.c hello.h status.c status.h looting.c looting.h enemy_choose.c enemy_choose.h global_variables.c global_variables.h)
