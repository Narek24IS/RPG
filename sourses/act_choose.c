//
// Created by Hikinari on 24.01.2023.
//
#include "includes/global.h"

int act_choose() {
    // Выбор следующего действия
    printf("\nChoose an action:\n 1. Fight with another enemy\n 2. Check your status\n "
           "3. Heal for coins\n 4. Quit the game\n");
    int action = getchar();

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
            heal();
            fflush(stdin);
            break;
        case '4':
            printf("Good Bye!\n");
            exit(0);
            break;
        default:
            printf("Please, select one of the options from the list!\n");
            fflush(stdin);
            break;
    }
    return 0;
}