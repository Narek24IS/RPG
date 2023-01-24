    //
// Created by Hikinari on 24.01.2023.
//
#include "global.h"
#include "player_death_check.h"

int player_death_check() {
    // Проверка смерти игрока и окончание игры в таком случае
    if (player_hp == 0) {
        printf("%s is dead! Game over!\n", nickname);
        exit(0);
    }
    return 0;
}
