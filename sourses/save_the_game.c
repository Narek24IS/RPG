//
// Created by Hikinari on 28.01.2023.
//

#include "includes/global.h"

int saveTheGame() {
    FILE *fout;
    fout = fopen("C:\\Users\\Hikinari\\Documents\\C\\RPG\\save.txt", "w");
    fprintf(fout, "%d %d %d %d %d %d %d %s %d", playerHP, playerDmg, playerCoins, playerLevel, playerEXP, levelEXP,
            playerMaxHP, nickname, newGame);
    fclose(fout);
}
