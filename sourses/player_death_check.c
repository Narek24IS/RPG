    //
// Created by Hikinari on 24.01.2023.
//
#include "includes/global.h"

int player_death_check() {
    // Проверка смерти игрока и окончание игры в таком случае
    if (player_hp == 0) {
        printf("You are dead! Game over!\n");
        getchar();
        getchar();
        exit(0);
    }
    return 0;
}
