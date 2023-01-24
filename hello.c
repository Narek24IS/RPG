//
// Created by Hikinari on 24.01.2023.
//

#include "headers/global.h"
#include "headers/hello.h"

int hello() {
    // Начальное приветствие игрока

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
    printf("Not bad! Let's see how you fight!\n"
           "Choose your enemy!\n");
    battle();

    return 0;
}