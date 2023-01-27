//
// Created by Hikinari on 24.01.2023.
//

#include "includes/global.h"

int hello() {
    // Начальное приветствие игрока
    int action;
    printf("Do you want to start a new game or continue a previous game session?\n"
           " 1. Continue \n 2. New game\n");
    re: action = getchar();

    switch (action) {
        case '1':
            fflush(stdin);
            FILE *fin;
            fin = fopen("C:\\Users\\Hikinari\\Documents\\C\\RPG\\save.txt", "r");
            fscanf(fin, "%d%d%d%d%d%d%d%s%d", &playerHP, &playerDmg, &playerCoins, &playerLevel, &playerEXP, &levelEXP,
                   &playerMaxHP, &nickname[10], &newGame);
            fclose(fin);
            actChoose();
            break;
        case '2':
            newGame = 1;
            fflush(stdin);
            break;
        default:
            printf("Please, select one of the options from the list!\n");
            fflush(stdin);
            goto re;
    }


    if(newGame == 1)
        {
            printf("Hi, adventurer! What is your name?\n");

            fgets(nickname, sizeof(nickname), stdin); // ввод ника

            if (nickname[strlen(nickname) - 1] == '\n')
                nickname[strlen(nickname) - 1] = '\0'; // убрать Enter в конце ника из буфера
            else
                fflush(stdin); // очистить буфер от лишних символов

            printf("Okay, %s, now let's check your stats!\n"
                   "Press Enter to check your stats...",
                   nickname);
            getchar();
            fflush(stdin);
            status();
            printf("\nNot bad! Let's see how you fight!\n");
            battle();
        }

    return 0;
}