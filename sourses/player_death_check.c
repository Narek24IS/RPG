    //
// Created by Hikinari on 24.01.2023.
//
#include "includes/global.h"

int actChoose() {
    // Проверка смерти игрока и окончание игры в таком случае
    if (playerHP == 0) {
        printf("You are dead! Game over!\n");
        FILE *fout;
        fout = fopen("C:\\Users\\Hikinari\\Documents\\C\\RPG\\save.txt", "w");
        fprintf(fout, "%d %d %d %d %d %d %d %s %d", playerHP, playerDmg, playerCoins, playerLevel, playerEXP, levelEXP,
                playerMaxHP, nickname, newGame);
        fclose(fout);
        getchar();
        getchar();
        exit(0);
    }
    return 0;
}
