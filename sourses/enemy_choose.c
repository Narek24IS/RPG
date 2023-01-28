//
// Created by Hikinari on 24.01.2023.
//

#include "includes/global.h"

int enemyChoose(int action, char *enemyName) {
    // Выбор противника на бой
    int enemyMod = 0;

    while (enemyMod == 0) {
        printf("\nChoose enemy, %s:\n 1. Goblin(1x HP and DMG)\n 2. Cobold(2x HP and DMG)\n "
               "3. Murlok(3x HP and DMG)\n 4. Ent(4x HP and DMG)\n", nickname);

        action = getchar();

        switch (action) {
            case '1':
                enemyMod = 1;
                strcpy(enemyName, "Goblin");
                fflush(stdin);
                break;
            case '2':
                enemyMod = 2;
                strcpy(enemyName, "Cobold");
                fflush(stdin);
                break;
            case '3':
                enemyMod = 3;
                strcpy(enemyName, "Murlok");
                fflush(stdin);
                break;
            case '4':
                enemyMod = 4;
                strcpy(enemyName, "Ent");
                fflush(stdin);
                break;
            default:
                printf("Please, select one of the options from the list!\n");
                fflush(stdin);
                break;
        }
    }
    return enemyMod;
}