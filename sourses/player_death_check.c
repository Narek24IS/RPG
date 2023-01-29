//
// Created by Hikinari on 24.01.2023.
//
#include "includes/global.h"

int playerDeathCheck() {
    // Проверка смерти игрока и окончание игры в таком случае
    if (playerHP == 0) {
        printf("\n\nYou are dead! Game over!\n");
        saveTheGame();
        getchar();
        exit(0);
    }
    return 0;
}
