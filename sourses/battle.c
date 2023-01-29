//
// Created by Hikinari on 24.01.2023.
//
#include "includes/global.h"

void battleMenu(int action, char enemyName[10], int enemyLVL, int enemyHP) {
    //Вывод списка пунктов на выбор
    system("cls");//Очищает окно командной строки
    battleTutorial();//Выводит мини-гайд по бою
    printf("\nLVL.%d %s - %d HP\n", enemyLVL, enemyName, enemyHP);//Выводит уровень и ХП врага
    printf("\nLVL.%d %s - %d HP %d DMG\n", playerLevel, nickname, playerHP, playerDmg);//Уровень, ХП и урон игрока
    printf("\nChoose an action:");//Выберите действие
    printf("\n%s 1. Attack", action == 1 ? ">" : " ");//Атаковать
    printf("\n%s 2. Parry", action == 2 ? ">" : " ");//Парировать
    printf("\n%s 3. Run\n", action == 3 ? ">" : " ");//Бежать
}

int battle() {
    // Механика сражения, выборы действий
    int action = 1;
    int laction = 3;
    int enemyMod;
    int enemyLVL = rand() % playerLevel + 1;//Рандомно определяется уровень врага
    int enemyHP;
    char enemyName[10];

    enemyMod = enemyChoose(enemyName);//Выводит меню выбора врага, от которого зависит модификатор сложности

    enemyHP = enemyLVL * playerDmg * enemyMod - rand() % 10 * 10 / 15;//Здоровье врага
    battleMenu(action, enemyName, enemyLVL, enemyHP);

    while (enemyHP >= 0) {
        //Бесконечный цикл, который закончится после выбора действия
        int enemyDMG = rand() % 4 * enemyMod * enemyLVL;//Урон врага при каждом цикле
        int altEnemyDMG = enemyDMG / 3;//Уменьшенный урон врага при парировании
        int altPlayerDMG = rand() % playerDmg + playerDmg / 10;//Уменьшенный урон игрока при парировании

        if (GetAsyncKeyState(VK_UP)) {
            //Стрелка выбора перескакивает вверх при нажатии на клавиатуре стрелки вверх
            keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            if (0 < action - 1)
                action = action - 1;
            else
                action = laction;
            battleMenu(action, enemyName, enemyLVL, enemyHP);
        }
        if (GetAsyncKeyState(VK_DOWN)) {
            //Стрелка выбора перескакивает вниз при нажатии на клавиатуре стрелки вниз
            keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            if (action < laction)
                action = action + 1;
            else
                action = 1;
            battleMenu(action, enemyName, enemyLVL, enemyHP);
        }
        if (GetAsyncKeyState(VK_RETURN)) {
            //Выбирается и выполняется тот пункт, на который сейчас указывает стрелка при нажатии Enter
            keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            battleMenu(action, enemyName, enemyLVL, enemyHP);
            switch (action) {
                case 1:
                    //Обычная атака врага
                    enemyHP -= playerDmg;//Наносит врагу урон, равный урону игрока
                    playerHP -= enemyDMG;//Игрока получает урон
                    if (enemyHP < 0)//Приравнивает здоровье врага к 0, если оно меньше
                        enemyHP = 0;
                    if (playerHP < 0)//Приравнивает игрока врага к 0, если оно меньше
                        playerHP = 0;
                    battleMenu(action, enemyName, enemyLVL, enemyHP);
                    break;
                case 2:
                    enemyHP -= altPlayerDMG;//Наносит врагу урон, равный уменьшенному урону игрока
                    playerHP -= altEnemyDMG;//Игрока получает уменьшенный урон
                    if (enemyHP < 0)//Приравнивает здоровье врага к 0, если оно меньше
                        enemyHP = 0;
                    if (playerHP < 0)//Приравнивает игрока врага к 0, если оно меньше
                        playerHP = 0;
                    battleMenu(action, enemyName, enemyLVL, enemyHP);
                    break;
                case 3:
                    printf("\n\nYou ran away");//Вы убегаете
                    goto quit;//Переходит в конец функции
            }
        }

        playerDeathCheck();//Проверка смерти игрока

        if (enemyHP == 0) {
            //Проверка смерти врага
            looting(enemyMod, enemyLVL, enemyName);//Функция получения награды игроком
            break;
        }
    }
    quit:
    return 0;
}