//
// Created by Hikinari on 24.01.2023.
//
#include "includes/global.h"

void battleMenu(int action, char enemyName[10], int enemyLVL, int enemyHP) {
    system("cls");
    battleTutorial();
    printf("\nLVL.%d %s - %d HP\n", enemyLVL, enemyName, enemyHP);
    printf("\nLVL.%d %s - %d HP %d DMG\n", playerLevel, nickname, playerHP, playerDmg);
    printf("\nChoose an action:\n%s 1. Attack", action == 1 ? ">" : " ");
    printf("\n%s 2. Parry", action == 2 ? ">" : " ");
    printf("\n%s 3. Run\n", action == 3 ? ">" : " ");
}

int battle() {
    // Механика сражения, выборы действий
    int action = 1;
    int laction = 3;
    int enemyMod;
    int enemyLVL = rand() % playerLevel + 1;
    int enemyHP;
    char enemyName[10];

    enemyMod = enemyChoose(enemyName);

    enemyHP = enemyLVL * playerDmg * enemyMod - rand() % 10 * 10 / 15;
    battleMenu(action, enemyName, enemyLVL, enemyHP);

    while (enemyHP >= 0) {
        int enemyDMG = rand() % 4 * enemyMod * enemyLVL;
        int altEnemyDMG = enemyDMG / 3;
        int altPlayerDMG = rand() % playerDmg + playerDmg / 10;

        if (GetAsyncKeyState(VK_UP)) {
            keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            if (0 < action - 1)
                action = action - 1;
            else
                action = laction;
            battleMenu(action, enemyName, enemyLVL, enemyHP);
        }
        if (GetAsyncKeyState(VK_DOWN)) {
            keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            if (action < laction)
                action = action + 1;
            else
                action = 1;
            battleMenu(action, enemyName, enemyLVL, enemyHP);
        }
        if (GetAsyncKeyState(VK_RETURN)) {
            keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            battleMenu(action, enemyName, enemyLVL, enemyHP);
            switch (action) {
                case 1:
                    enemyHP -= playerDmg;
                    playerHP -= enemyDMG;
                    if (enemyHP < 0)
                        enemyHP = 0;
                    if (playerHP < 0)
                        playerHP = 0;
                    battleMenu(action, enemyName, enemyLVL, enemyHP);
                    break;
                case 2:
                    enemyHP -= altPlayerDMG;
                    playerHP -= altEnemyDMG;
                    if (enemyHP < 0)
                        enemyHP = 0;
                    if (playerHP < 0)
                        playerHP = 0;
                    battleMenu(action, enemyName, enemyLVL, enemyHP);
                    break;
                case 3:
                    printf("\n\nYou ran away");

                    goto quit;
            }
        }

        playerDeathCheck();

        if (enemyHP == 0) {
            looting(enemyMod, enemyLVL, enemyName);
            break;
        }
    }
    quit:

    return 0;
}