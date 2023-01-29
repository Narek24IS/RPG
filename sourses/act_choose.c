//
// Created by Hikinari on 24.01.2023.
//
#include "includes/global.h"

void chooseMenu(int action) {
    //Вывод списка пунктов на выбор
    system("cls");
    printf("\nChoose an action:");//Выберите действие
    printf("\n%s 1. Fight with another enemy", action == 1 ? ">" : " ");//Сразиться с другим врагом
    printf("\n%s 2. Check your status", action == 2 ? ">" : " ");//Проверить свой статус
    printf("\n%s 3. Heal for coins", action == 3 ? ">" : " ");//Полечиться за деньги
    printf("\n%s 4. Save and quit", action == 4 ? ">" : " ");//Сохранить и выйти
    printf("\n%s 5. Quit without saving\n", action == 5 ? ">" : " ");//Выйти без сохранения
}

int actChoose() {
    // Выбор следующего действия
    int action = 1;
    int laction = 5;
    re:

    chooseMenu(action);

    while (TRUE) {
        //Бесконечный цикл, который закончится после выбора действия
        if (GetAsyncKeyState(VK_UP)) {
            //Стрелка выбора перескакивает вверх при нажатии на клавиатуре стрелки вверх
            keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            if (0 < action - 1)
                action = action - 1;
            else
                action = laction;
            chooseMenu(action);
        }
        if (GetAsyncKeyState(VK_DOWN)) {
            //Стрелка выбора перескакивает вниз при нажатии на клавиатуре стрелки вниз
            keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            if (action < laction)
                action = action + 1;
            else
                action = 1;
            chooseMenu(action);
        }
        if (GetAsyncKeyState(VK_RETURN)) {
            //Выбирается и выполняется тот пункт, на который сейчас указывает стрелка при нажатии Enter
            keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            chooseMenu(action);

            switch (action) {
                case 1:
                    //Переходит в меню битвы
                    battle();
                    chooseMenu(action);//Выводит меню выбора действия сразу после окончания действия
                    break;
                case 2:
                    //Показывает статус персонажа
                    status();
                    chooseMenu(action);//Выводит меню выбора действия сразу после окончания действия
                    break;
                case 3:
                    //Переходит в меню хила
                    heal();
                    chooseMenu(action);//Выводит меню выбора действия сразу после окончания действия
                    break;
                case 4:
                    //Выход из игры с сохранением
                    printf("\n\nAre you sure? (y/n)\n");//спрашивает подтверждение действия
                    while (TRUE) {
                        if (GetAsyncKeyState(0x59)) {
                            //Если нажать 'y', то выйдет из программы, предварительно сохранившись
                            keybd_event(0x59, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
                            saveTheGame();//Сохранение игры
                            exit(0);//Выход из программы
                        }
                        if (GetAsyncKeyState(0x4E)) {
                            //Если нажать 'n', то вернёт в меню выбора действий
                            keybd_event(0x4E, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
                            chooseMenu(action);//Выводит меню выбора действия если отказались выйти
                            goto re;//Переходит в начало бесконечного цикла для выбора действий
                        }
                    }
                case 5:

                    printf("\n\nAre you sure? (y/n)\n");
                    while (TRUE) {
                        //Если нажать 'y', то выйдет из программы не сохранившись
                        if (GetAsyncKeyState(0x59)) {
                            keybd_event(0x59, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
                            exit(0);//Выход из программы
                        }
                        if (GetAsyncKeyState(0x4E)) {
                            //Если нажать 'n', то вернёт в меню выбора действий
                            keybd_event(0x4E, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
                            chooseMenu(action);//Выводит меню выбора действия если отказались выйти
                            goto re;//Переходит в начало бесконечного цикла для выбора действий
                        }
                    }
            }
        }

    }
}