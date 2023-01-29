//
// Created by Hikinari on 24.01.2023.
//

#include "includes/global.h"

int status() {
    // Показывает все характеристики игрока на данный момент
    printf("\n%s\nLevel:%d\nEXP:%d/%d\nHP:%d/%d\nDamage:%d\nYour coins:%d\n",
           nickname, playerLevel, playerEXP, levelEXP, playerHP, playerMaxHP,
           playerDmg, playerCoins);
    printf("\nPress ENTER to continue\n");
    getchar();
    return 0;
}
