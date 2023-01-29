//
// Created by Hikinari on 24.01.2023.
//

#include "includes/global.h"

void ngMenu(int action) {
    //Вывод списка пунктов на выбор
    system("cls");//Очищает окно командной строки
    //Вы хотите начать новую игру или продолжить прошлую игровую сессию?
    printf("Do you want to start a new game or continue a previous game session?\n");
    printf("\n%s 1. Continue game \n", action == 1 ? ">" : " ");//Продолжить
    printf("\n%s 2. Start new game \n", action == 2 ? ">" : " ");//Начать новую игру
}

int hello() {
    // Начальное приветствие игрока
    int action = 1;
    int laction = 2;

    ngMenu(action);

    while (TRUE) {
        //Бесконечный цикл, который закончится после выбора действия
        if (GetAsyncKeyState(VK_UP)) {
            //Стрелка выбора перескакивает вверх при нажатии на клавиатуре стрелки вверх
            keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            if (0 < action - 1)
                action = action - 1;
            else
                action = laction;
            ngMenu(action);
        }
        if (GetAsyncKeyState(VK_DOWN)) {
            //Стрелка выбора перескакивает вниз при нажатии на клавиатуре стрелки вниз
            keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            if (action < laction)
                action = action + 1;
            else
                action = 1;
            ngMenu(action);
        }
        if (GetAsyncKeyState(VK_RETURN)) {
            //Выбирается и выполняется тот пункт, на который сейчас указывает стрелка при нажатии Enter
            keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            ngMenu(action);
            switch (action) {
                case 1:
                    //Продолжение прошлой игры
                    system("cls");//Очищает окно командной строки
                    FILE *fin; //Считывает с файла с сохранением статус персонажа и заменяет начальный
                    fin = fopen("C:\\Users\\Hikinari\\Documents\\C\\RPG\\save.txt", "r");
                    fscanf(fin, "%d %d %d %d %d %d %d %s %d", &playerHP, &playerDmg, &playerCoins,
                           &playerLevel, &playerEXP, &levelEXP, &playerMaxHP, &nickname, &newGame);
                    fclose(fin);
                    if (playerHP == 0) {
                        //Если в прошлой игре игрок умер
                        if (playerCoins != 0) {
                            //И у него были монеты
                            playerHP = playerCoins * 5;//Лечит игрока на 5 ХП за каждую монету
                            if (playerHP > playerMaxHP)//Если здоровье игрока превышает максимум - исправляет это
                                playerHP = playerMaxHP;
                            playerCoins = 0;//Отнимает все монеты игрока
                            //Сообщает игроку, что у него отняли монеты и вылечили
                            printf("All your coins were spent on healing because you died in the last game."
                                   "\nBut you are alive!\nYour HP now:%d/%d\n", playerHP, playerMaxHP);
                            newGame = 0;//Меняет значение переменной отвечающей за новую игру
                            actChoose();//Переход к меню выбора действий
                            break;
                        } else {
                            //Если игрок умер в прошлой игре и у него не было монет,
                            //то характеристики остаются начальными
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
                        //Если игрок в прошлой игре не умер, то он просто продолжает
                        newGame = 0;
                        actChoose();
                        break;
                    }
                case 2:
                ng:
                    system("cls");//Очищает окно командной строки
                    printf("\nHi, adventurer! What is your name?\n");//Приветствие игрока
                    getchar();//Убирает лишний ENTER
                    fgets(nickname, sizeof(nickname), stdin); //Ввод ника

                    if (nickname[strlen(nickname) - 1] == '\n')
                        nickname[strlen(nickname) - 1] = '\0'; // убрать Enter в конце ника из буфера
                    else
                        fflush(stdin); // Очистить буфер от лишних символов

                    printf("Okay, %s, now let's check your stats! And then we'll test your skills in battle\n",
                           nickname);//Хорошо, давай проверим твою статистику и пойдём сражаться

                    while (TRUE) {
                        //Буфер для ENTERа после ввода ника
                        if (GetAsyncKeyState(VK_RETURN)) {
                            keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
                            break;
                        }
                    }

                    status();//Вызывает статус игрока

                    battle();//Посылает игрока в пробный бой

                    goto hello_end;//Выходит из бесонечного цикла
            }
        }
    }
    hello_end:
    return 0;
}