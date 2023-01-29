//
// Created by Hikinari on 24.01.2023.
//

#include "includes/global.h"

int looting(int enemyMod, int enemyLVL, char *enemyName) {
    // Выпадение награды за победу над противником
    int enemyEXP = (rand() % 50 + enemyMod + enemyLVL) * enemyMod * enemyLVL;
    int enemyCoins = rand() % 4 + enemyMod + enemyLVL;

    printf("\n\n%s has been defeat! You earn %d coins and %d EXP!\n", enemyName, enemyCoins, enemyEXP);
    playerCoins += enemyCoins;
    playerEXP += enemyEXP;
    lvlUpCheck();
    printf("\nPress ENTER to continue\n");
    getchar();
    return 0;
}