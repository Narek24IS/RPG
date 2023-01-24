//
// Created by Hikinari on 24.01.2023.
//
#include "headers/global.h"
#include "headers/act_choose.h"

int act_choose() {
    // Выбор следующего действия
    int action;

    printf("\nChoose an action:\n 1. Fight with another enemy\n 2. Check your status\n "
           "3. Heal for coins\n 4. Quit the game\n");

    action = getchar();

    if (action == '1') {
        fflush(stdin);
        battle();
    } else if (action == '2') {
        status();
        fflush(stdin);
    } else if (action == '3') {
        heal();
        fflush(stdin);
    } else if (action == '4') {
        printf("Good Bye!\n");
        exit(0);
    } else {
        printf("Please, select one of the options from the list!\n");
        fflush(stdin);
    }
    return 0;
}