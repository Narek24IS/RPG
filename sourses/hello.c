//
// Created by Hikinari on 24.01.2023.
//

#include "includes/global.h"

void ngMenu(int action){
    system("cls");
    printf("Do you want to start a new game or continue a previous game session?\n");
    printf("\n%s 1. Continue game \n", action == 1 ? ">" : " ");
    printf("\n%s 2. Start new game \n", action == 2 ? ">" : " ");
}

int hello() {
    // Начальное приветствие игрока
    int action = 1;
    int laction = 2;

    fflush(stdin);
    ngMenu(action);

    while (TRUE) {
        fflush(stdin);
        if (GetAsyncKeyState(VK_UP)) {
            keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            if (0 < action - 1)
                action = action - 1;
            else
                action = laction;
            ngMenu(action);
        }
        if (GetAsyncKeyState(VK_DOWN)) {
            keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            if (action < laction)
                action = action + 1;
            else
                action = 1;
            ngMenu(action);
        }
        if (GetAsyncKeyState(VK_SPACE)) {
            keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            ngMenu(action);
            switch (action) {
                case 1:
                    fflush(stdin);
                    FILE *fin;
                    fin = fopen("C:\\Users\\Hikinari\\Documents\\C\\RPG\\save.txt", "r");
                    fscanf(fin, "%d %d %d %d %d %d %d %s %d", &playerHP, &playerDmg, &playerCoins, &playerLevel,
                           &playerEXP, &levelEXP, &playerMaxHP, &nickname[10], &newGame);
                    fclose(fin);
                    if (playerHP == 0) {
                        if (playerCoins != 0) {
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
                        } else {
                            playerHP = 100;
                            playerDmg = 10;
                            playerCoins = 0;
                            playerLevel = 1;
                            playerEXP = 0;
                            levelEXP = 100;
                            playerMaxHP = 100;
                            newGame = 1;
                            printf("You didn't have any coins.\nYou will have to start new game.\n\n");
                            goto ng;
                        }
                    } else {
                        newGame = 0;
                        actChoose();
                        break;
                    }
                case 2:
                ng:
                    newGame = 1;
                    printf("Hi, adventurer! What is your name?\n");

                    fgets(nickname, sizeof(nickname), stdin); // ввод ника

                    if (nickname[strlen(nickname) - 1] == '\n')
                        nickname[strlen(nickname) - 1] = '\0'; // убрать Enter в конце ника из буфера
                    else
                        fflush(stdin); // очистить буфер от лишних символов

                    printf("Okay, %s, now let's check your stats!\n", nickname);
                    fflush(stdin);
                    status();
                    printf("\n\nNot bad! Let's see how you fight!\n");
                    printf("\nPress ENTER to continue\n");
                    getchar();
                    battle();
                    fflush(stdin);
                    goto hello_end;
            }
        }
    }
    hello_end:
    return 0;
}