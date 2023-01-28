//
// Created by Hikinari on 24.01.2023.
//
#include "includes/global.h"

int actChoose() {
    // Выбор следующего действия
    int action;
    printf("\nChoose an action:");
    re: printf("\n 1. Fight with another enemy\n 2. Check your status\n "
           "3. Heal for coins\n 4. Save and quit\n 5. Quit without saving\n");
    action = getchar();

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
            fflush(stdin);
            printf("Are you sure? (y/n)\n");
            if (getchar() == 'y') {
                printf("OK,goodbye! Well done!\n");
                saveTheGame();
                getchar();
                getchar();
                exit(0);
            }
            else {
                printf("OK,then choose an action:");
                fflush(stdin);
                goto re;
            }
        case '5':
            fflush(stdin);
            printf("\nAre you sure? (y/n)\n");
            if (getchar() == 'y') {
                exit(0);
            }
            else {
                printf("\nOK, then choose an action:");
                fflush(stdin);
                goto re;
            }
        default:
            printf("Please, select one of the options from the list!");
            fflush(stdin);
            goto re;
    }
    return 0;
}