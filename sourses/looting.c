//
// Created by Hikinari on 24.01.2023.
//

#include "includes/global.h"

int looting(int enemyMod, int enemyLVL, char *enemyName) {
    // Выпадение награды за победу над противником
    int enemyEXP = (rand() % 50 + enemyMod + enemyLVL) * enemyMod * enemyLVL;
    int enemyCoins = rand() % 4 + enemyMod + enemyLVL;

    system("cls");
    printf("\n\n%s has been defeat! You earn %d coins and %d EXP!\n", enemyName, enemyCoins, enemyEXP);
    playerCoins += enemyCoins;
    playerEXP += enemyEXP;
    printf("\nPress ENTER to continue\n");
    while(TRUE) {
        if (GetAsyncKeyState(VK_RETURN)) {
            keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
            break;
        }
    }
    lvlUpCheck();
    return 0;
}