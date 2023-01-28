//
// Created by Hikinari on 24.01.2023.
//

#include "includes/global.h"

int hello() {
    // Начальное приветствие игрока
    int action;
    printf("Do you want to start a new game or continue a previous game session?\n"
           " 1. Continue game \n 2. Start new game\n");
    re: action = getchar();

    switch (action) {
        case '1':
            fflush(stdin);
            FILE *fin;
            fin = fopen("C:\\Users\\Hikinari\\Documents\\C\\RPG\\save.txt", "r");
            fscanf(fin, "%d %d %d %d %d %d %d %s %d", &playerHP, &playerDmg, &playerCoins, &playerLevel,
                   &playerEXP, &levelEXP, &playerMaxHP, &nickname[10], &newGame);
            fclose(fin);
            if (playerHP == 0) {
                if (playerCoins != 0)
                    {
                        playerHP = playerCoins * 5;
                        if (playerHP > playerMaxHP) {
                            playerHP = playerMaxHP;
                        }
                        playerCoins = 0;
                        printf("All your coins were spent on healing because you died in the last game."
                               "\nBut you are alive!\nYour HP now:%d/%d\n", playerHP, playerMaxHP);
                        newGame = 0;
                        actChoose();
                        break;
                    }
                else {
                    playerHP = 100;
                    playerDmg = 10;
                    playerCoins = 0;
                    playerLevel = 1;
                    playerEXP = 0;
                    levelEXP = 100;
                    playerMaxHP = 100;
                    newGame = 1;
                    printf("You didn't have any coins.\nYou will have to start new game.\n\n");
                }
            }
            else {
                newGame = 0;
                actChoose();
                break;
            }
        case '2':ng:
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