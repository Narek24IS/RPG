//
// Created by Hikinari on 24.01.2023.
//

#include "includes/global.h"

int lvlUpCheck() {
    // Поверка поднял ли игрок уровень и повышение характеристик в таком случае
    system("cls");
    int hpUp = rand() % 25 + 5;
    if (playerEXP / levelEXP > 0) {
        int dmgUp = rand() % 5 + 1;
        ++playerLevel;
        printf("\nCongratulations %s! You got level %d!\n"
               "\nYour damage has increased by %d and your max health has increased by %d!\n", nickname,
               playerLevel, dmgUp, hpUp);
        playerMaxHP += hpUp;
        playerHP += hpUp;
        playerDmg += dmgUp;
        playerEXP = (playerEXP - levelEXP) % levelEXP;
        levelEXP += 100;
        printf("\nPress ENTER to continue\n");
        while (TRUE) {
            if (GetAsyncKeyState(VK_RETURN)) {
                keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
                break;
            }
        }
    }
    return 0;
}