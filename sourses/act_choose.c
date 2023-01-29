//
// Created by Hikinari on 24.01.2023.
//
#include "includes/global.h"

void chooseMenu(int action) {
    system("cls");
    printf("\nChoose an action:\n%s 1. Fight with another enemy", action == 1 ? ">" : " ");
    printf("\n%s 2. Check your status", action == 2 ? ">" : " ");
    printf("\n%s 3. Heal for coins", action == 3 ? ">" : " ");
    printf("\n%s 4. Save and quit", action == 4 ? ">" : " ");
    printf("\n%s 5. Quit without saving\n", action == 5 ? ">" : " ");
}

int actChoose() {
    // Выбор следующего действия
    int action = 1;
    int laction = 5;
    re:

    chooseMenu(action);

    while (TRUE) {

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
        if (GetAsyncKeyState(VK_RETURN)) {
            keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            chooseMenu(action);

            switch (action) {
                case 1:

                    battle();
                    chooseMenu(action);
                    break;
                case 2:
                    status();

                    chooseMenu(action);
                    break;
                case 3:
                    heal();

                    chooseMenu(action);
                    break;
                case 4:

                    printf("\n\nAre you sure? (y/n)\n");
                    while (TRUE) {
                        if (GetAsyncKeyState(0x59)) {
                            keybd_event(0x59, 0, KEYEVENTF_KEYUP, 0);
                            saveTheGame();
                            exit(0);
                        }
                        if (GetAsyncKeyState(0x4E)) {
                            keybd_event(0x4E, 0, KEYEVENTF_KEYUP, 0);
                            chooseMenu(action);

                            goto re;
                        }
                    }
                case 5:

                    printf("\n\nAre you sure? (y/n)\n");
                    while (TRUE) {
                        if (GetAsyncKeyState(0x59)) {
                            keybd_event(0x59, 0, KEYEVENTF_KEYUP, 0);
                            exit(0);
                        }
                        if (GetAsyncKeyState(0x4E)) {
                            keybd_event(0x4E, 0, KEYEVENTF_KEYUP, 0);
                            chooseMenu(action);

                            goto re;
                        }
                    }
            }
        }

    }
}