cmake_minimum_required(VERSION 3.24)
project(RPG
        LANGUAGES C)

set(CMAKE_C_STANDARD 11)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR} .)


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
        sourses/player_death_check.c includes/player_death_check.h
        sourses/save_the_game.c includes/save_the_game.h sourses/battle_tutorial.c includes/battle_tutorial.h)

target_link_libraries(${PROJECT_NAME} ${CURSES_LIBRARY})
