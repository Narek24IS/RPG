//
// Created by Hikinari on 24.01.2023.
//

#include "includes/global.h"
#include "includes/enemy_choose.h"

int enemy_choose(int action, char *enemy_name) {
    // Выбор противника на бой
    int enemy_mod = 0;

    while (enemy_mod == 0) {
        printf("\nChoose enemy, %s:\n 1. Goblin\n 2. Cobold\n "
               "3. Murlok\n 4. Ent\n", nickname);

        action = getchar();

        if (action == '1') {
            enemy_mod = 1;
            strcpy(enemy_name, "Goblin");
            fflush(stdin);
        } else if (action == '2') {
            enemy_mod = 2;
            strcpy(enemy_name, "Cobold");
            fflush(stdin);
        } else if (action == '3') {
            enemy_mod = 3;
            strcpy(enemy_name, "Murlok");
            fflush(stdin);
        } else if (action == '4') {
            enemy_mod = 4;
            strcpy(enemy_name, "Ent");
            fflush(stdin);
        } else {
            printf("Please, select one of the options from the list!\n");
            fflush(stdin);
        }
    }
    return enemy_mod;
}