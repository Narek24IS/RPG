//
// Created by Hikinari on 24.01.2023.
//

#include "includes/global.h"

void healMenu(int action) {
    //Вывод списка пунктов на выбор
    system("cls");//Очищает окно командной строки
    printf("Your HP: %d     Coins: %d", playerHP, playerCoins);//Выводит ХП и монеты игрока
    printf("\nHow many coins do you want to spend on healing?");//Как много у вас монет
    printf("\n%s 1. 1 coin - 5 HP", action == 1 ? ">" : " ");
    printf("\n%s 2. 3 coin - 15 HP", action == 2 ? ">" : " ");
    printf("\n%s 3. 5 coin - 25 HP", action == 3 ? ">" : " ");
    printf("\n%s 4. 10 coin - 50 HP", action == 4 ? ">" : " ");
    printf("\n%s 5. %d coin - %d HP", action == 5 ? ">" : " ", playerCoins, playerCoins * 5);//Потратить все
    printf("\n%s 6. Full HP for %d coins", action == 6 ? ">" : " ", (playerMaxHP - playerHP) / 5);//Полное лечение
    printf("\n%s 7. Return\n", action == 7 ? ">" : " ");//Вернутсья назад
}

int heal() {
    // Лечение за деньги
    int spentCoin;
    int action = 1;
    int laction = 7;

    healMenu(action);

    if (playerCoins > 0) {
        while (TRUE) {
            //Бесконечный цикл, который закончится после выбора действия
            if (GetAsyncKeyState(VK_UP)) {
                //Стрелка выбора перескакивает вверх при нажатии на клавиатуре стрелки вверх
                keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
                if (0 < action - 1)
                    action = action - 1;
                else
                    action = laction;
                healMenu(action);
            }
            if (GetAsyncKeyState(VK_DOWN)) {
                //Стрелка выбора перескакивает вниз при нажатии на клавиатуре стрелки вниз
                keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
                if (action < laction)
                    action = action + 1;
                else
                    action = 1;
                healMenu(action);
            }
            if (GetAsyncKeyState(VK_RETURN)) {
                //Выбирается и выполняется тот пункт, на который сейчас указывает стрелка при нажатии Enter
                keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
                healMenu(action);
                switch (action) {
                    case 1:
                        system("cls");//Очищает окно командной строки
                        spentCoin = 1;//Потратиться монет
                        if (spentCoin > playerCoins) {
                            //Если у игрока недостаточно монет - уведомляет об этом
                            printf("You have only %d coins.\n", playerCoins);
                            healMenu(action);
                        } else {
                            playerHP += (spentCoin * 5);//Лечит игрока
                            playerCoins -= spentCoin;//Отнимает деньги за лечение
                            if (playerHP > playerMaxHP)//Если здоровье игрока превышает максимум - исправляет это
                                playerHP = playerMaxHP;
                            printf("You were heal by %d HP!\n\nYour HP: %d\n",
                                   spentCoin * 5, playerHP);//Выводит сколько здоровья было восстановлено
                            //Нужно нажать ENTER, чтобы продолжить
                            printf("\nPress ENTER to continue\n");
                            while (TRUE) {
                                if (GetAsyncKeyState(VK_RETURN)) {
                                    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
                                    break;
                                }
                            }
                            //Переход в конец функции
                            goto end;
                        }
                    case 2:
                        system("cls");//Очищает окно командной строки
                        spentCoin = 3;//Потратиться монет
                        if (spentCoin > playerCoins) {
                            //Если у игрока недостаточно монет - уведомляет об этом
                            printf("You have only %d coins.\n", playerCoins);
                            healMenu(action);
                        } else {
                            playerHP += (spentCoin * 5);//Лечит игрока
                            playerCoins -= spentCoin;//Отнимает деньги за лечение
                            if (playerHP > playerMaxHP)//Если здоровье игрока превышает максимум - исправляет это
                                playerHP = playerMaxHP;
                            printf("You were heal by %d HP!\n\nYour HP: %d\n",
                                   spentCoin * 5, playerHP);//Выводит сколько здоровья было восстановлено
                            //Нужно нажать ENTER, чтобы продолжить
                            printf("\nPress ENTER to continue\n");
                            while (TRUE) {
                                if (GetAsyncKeyState(VK_RETURN)) {
                                    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
                                    break;
                                }
                            }
                            //Переход в конец функции
                            goto end;
                        }
                    case 3:
                        system("cls");//Очищает окно командной строки
                        spentCoin = 5;//Потратиться монет
                        if (spentCoin > playerCoins) {
                            //Если у игрока недостаточно монет - уведомляет об этом
                            printf("You have only %d coins.\n", playerCoins);
                            healMenu(action);
                        } else {
                            playerHP += (spentCoin * 5);//Лечит игрока
                            playerCoins -= spentCoin;//Отнимает деньги за лечение
                            if (playerHP > playerMaxHP)//Если здоровье игрока превышает максимум - исправляет это
                                playerHP = playerMaxHP;
                            printf("You were heal by %d HP!\n\nYour HP: %d\n",
                                   spentCoin * 5, playerHP);//Выводит сколько здоровья было восстановлено
                            //Нужно нажать ENTER, чтобы продолжить
                            printf("\nPress ENTER to continue\n");
                            while (TRUE) {
                                if (GetAsyncKeyState(VK_RETURN)) {
                                    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
                                    break;
                                }
                            }
                            //Переход в конец функции
                            goto end;
                        }
                    case 4:
                        system("cls");//Очищает окно командной строки
                        spentCoin = 10;//Потратиться монет
                        if (spentCoin > playerCoins) {
                            //Если у игрока недостаточно монет - уведомляет об этом
                            printf("You have only %d coins.\n", playerCoins);
                            healMenu(action);
                        } else {
                            playerHP += (spentCoin * 5);//Лечит игрока
                            playerCoins -= spentCoin;//Отнимает деньги за лечение
                            if (playerHP > playerMaxHP)//Если здоровье игрока превышает максимум - исправляет это
                                playerHP = playerMaxHP;
                            printf("You were heal by %d HP!\n\nYour HP: %d\n",
                                   spentCoin * 5, playerHP);//Выводит сколько здоровья было восстановлено
                            //Нужно нажать ENTER, чтобы продолжить
                            printf("\nPress ENTER to continue\n");
                            while (TRUE) {
                                if (GetAsyncKeyState(VK_RETURN)) {
                                    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
                                    break;
                                }
                            }
                            //Переход в конец функции
                            goto end;
                        }
                    case 5:
                        //Лечит игрока на все имеющиеся монеты
                        system("cls");//Очищает окно командной строки
                        playerHP += playerCoins * 5;//Лечит игрока
                        if (playerHP > playerMaxHP)//Если здоровье игрока превышает максимум - исправляет это
                            playerHP = playerMaxHP;
                        printf("You were heal by %d HP!\n\n", playerCoins * 5);//Вы были полностью вылечены
                        playerCoins = 0;//Отнимает все монеты игрока
                        //Нужно нажать ENTER, чтобы продолжить
                        printf("\nPress ENTER to continue\n");
                        while (TRUE) {
                            if (GetAsyncKeyState(VK_RETURN)) {
                                keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
                                break;
                            }
                        }
                        //Переход в конец функции
                        goto end;
                    case 6:
                        system("cls");//Очищает окно командной строки
                        spentCoin = (playerMaxHP - playerHP) / 5;//Потратиться монет
                        if (spentCoin > playerCoins) {
                            //Если у игрока недостаточно монет - уведомляет об этом
                            printf("You have only %d coins.\n", playerCoins);
                            healMenu(action);
                        } else {
                            playerHP = playerMaxHP;//Лечит игрока
                            playerCoins -= spentCoin;//Отнимает деньги за лечение
                            printf("You were heal by full HP!\n\n");//Вы были полностью вылечены
                            //Нужно нажать ENTER, чтобы продолжить
                            printf("\nPress ENTER to continue\n");
                            while (TRUE) {
                                if (GetAsyncKeyState(VK_RETURN)) {
                                    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
                                    break;
                                }
                            }

                            //Переход в конец функции
                            goto end;
                        }
                    case 7:
                        //Переход в конец функции
                        goto end;
                }

            }
        }
    } else {
        printf("\n\nYou haven't any coins!\n\n");
        //Нужно нажать ENTER, чтобы продолжить
        printf("\nPress ENTER to continue\n");
        while (TRUE) {
            if (GetAsyncKeyState(VK_RETURN)) {
                //Выбирается и выполняется тот пункт, на который сейчас указывает стрелка при нажатии Enter
                keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
                break;
            }
        }
    }
    end:
    return 0;
}
