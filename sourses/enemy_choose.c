//
// Created by Hikinari on 24.01.2023.
//

#include "includes/global.h"

void enemyChooseMenu(int action) {
    system("cls");
    printf("\nChoose enemy, %s:\n%s 1. Goblin(1x HP and DMG)", nickname, action == 1 ? ">" : " ");
    printf("\n%s 2. Cobold(2x HP and DMG)", action == 2 ? ">" : " ");
    printf("\n%s 3. Murlok(3x HP and DMG)", action == 3 ? ">" : " ");
    printf("\n%s 4. Ent(4x HP and DMG)\n", action == 4 ? ">" : " ");
}

int enemyChoose(char *enemyName) {
    // Выбор противника на бой
    int enemyMod = 0;
    int action = 1;
    int laction = 4;


    enemyChooseMenu(action);

    while (enemyMod == 0) {

        if (GetAsyncKeyState(VK_UP)) {
            keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            if (0 < action - 1)
                action = action - 1;
            else
                action = laction;
            enemyChooseMenu(action);
        }
        if (GetAsyncKeyState(VK_DOWN)) {
            keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            if (action < laction)
                action = action + 1;
            else
                action = 1;
            enemyChooseMenu(action);
        }
        if (GetAsyncKeyState(VK_RETURN)) {
            keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            enemyChooseMenu(action);
            switch (action) {
                case 1:
                    enemyMod = 1;
                    strcpy(enemyName, "Goblin");

                    break;
                case 2:
                    enemyMod = 2;
                    strcpy(enemyName, "Cobold");

                    break;
                case 3:
                    enemyMod = 3;
                    strcpy(enemyName, "Murlok");

                    break;
                case 4:
                    enemyMod = 4;
                    strcpy(enemyName, "Ent");

                    break;
            }
        }
    }
    return enemyMod;
}