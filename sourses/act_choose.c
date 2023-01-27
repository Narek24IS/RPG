//
// Created by Hikinari on 24.01.2023.
//
#include "includes/global.h"

int actChoose() {
    // Выбор следующего действия
    int action;
    printf("\nChoose an action:\n 1. Fight with another enemy\n 2. Check your status\n "
           "3. Heal for coins\n 4. Quit the game\n");
    re: action = getchar();

    switch (action) {
        case '1':
            fflush(stdin);
            battle();
            break;
        case '2':
            status();
            fflush(stdin);
            break;
        case '3':
            fflush(stdin);
            heal();
            break;
        case '4':
            printf("Goodbye! Well done!\n");
            FILE *fout;
            fout = fopen("C:\\Users\\Hikinari\\Documents\\C\\RPG\\save.txt", "w");
            fprintf(fout, "%d %d %d %d %d %d %d %s %d", playerHP, playerDmg, playerCoins, playerLevel, playerEXP, levelEXP,
                    playerMaxHP, nickname, newGame);
            fclose(fout);
            getchar();
            getchar();
            exit(0);
        default:
            printf("Please, select one of the options from the list!\n");
            fflush(stdin);
            goto re;
    }
    return 0;
}