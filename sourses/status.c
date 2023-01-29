//
// Created by Hikinari on 24.01.2023.
//

#include "includes/global.h"

int status() {
    // Показывает все характеристики игрока на данный момент
    system("cls");
    printf("  %s\n\nLevel:%d\nEXP:%d/%d\nHP:%d/%d\nDamage:%d\nYour coins:%d\n",
           nickname, playerLevel, playerEXP, levelEXP, playerHP, playerMaxHP,
           playerDmg, playerCoins);
    //Нужно нажать ENTER, чтобы продолжить
    printf("\nPress ENTER to continue\n");
    while (TRUE) {
        if (GetAsyncKeyState(VK_RETURN)) {
            keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
            break;
        }
    }
    return 0;
}
