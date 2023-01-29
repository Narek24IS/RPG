//
// Created by Hikinari on 24.01.2023.
//
#include "includes/global.h"

void chooseMenu(int action){
    system("cls");
    printf("\nChoose an action:\n%s 1. Fight with another enemy", action == 1 ? ">" : " ");
    printf("\n%s 2. Check your status", action == 2 ? ">" : " ");
    printf("\n%s 3. Heal for coins", action == 3 ? ">" : " ");
    printf("\n%s 4. Save and quit", action == 4 ? ">" : " ");
    printf("\n%s 5. Quit without saving", action == 5 ? ">" : " ");
}

int actChoose() {
    // Выбор следующего действия
    int action = 1;
    int laction = 5;
    re:
    fflush(stdin);
    chooseMenu(action);

    while (TRUE) {
        fflush(stdin);
        if (GetAsyncKeyState(VK_UP)) {
            keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            if (0 < action - 1)
                action = action - 1;
            else
                action = laction;
            chooseMenu(action);
        }
        if (GetAsyncKeyState(VK_DOWN)) {
            keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            if (action < laction)
                action = action + 1;
            else
                action = 1;
            chooseMenu(action);
        }
        if (GetAsyncKeyState(VK_SPACE)) {
            keybd_event(VK_SPACE, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            chooseMenu(action);

            switch (action) {
                case 1:
                    fflush(stdin);
                    battle();
                    chooseMenu(action);
                    break;
                case 2:
                    status();
                    fflush(stdin);
                    chooseMenu(action);
                    break;
                case 3:
                    fflush(stdin);
                    heal();
                    chooseMenu(action);
                    break;
                case 4:
                    fflush(stdin);
                    printf("\n\nAre you sure? (y/n)\n");
                    while(TRUE)
                    {
                        if (GetAsyncKeyState(0x59)) {
                            keybd_event(0x59, 0, KEYEVENTF_KEYUP, 0);
                            printf("OK,goodbye! Well done!\n");
                            saveTheGame();
                            exit(0);
                        }
                        if (GetAsyncKeyState(0x4E)) {
                            keybd_event(0x4E, 0, KEYEVENTF_KEYUP, 0);
                            chooseMenu(action);
                            fflush(stdin);
                            goto re;
                        }
                    }
                case 5:
                    fflush(stdin);
                    printf("\n\nAre you sure? (y/n)\n");
                    if (getchar() == 'y') {
                        exit(0);
                    } else {
                        chooseMenu(action);
                        fflush(stdin);
                        break;
                    }
            }
        }
        fflush(stdin);
    }
    return 0;
}