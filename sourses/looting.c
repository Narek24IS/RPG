//
// Created by Hikinari on 24.01.2023.
//

#include "includes/global.h"

int looting(int enemyMod, int enemyLVL, char *enemyName) {
    // Выпадение награды за победу над противником
    int enemyEXP = (rand() % 50 + enemyMod + enemyLVL) * enemyMod * enemyLVL;//Формула выпадения опыта с врага
    int enemyCoins = rand() % 4 + enemyMod + enemyLVL;//Формула выпадения монеток с врага

    system("cls");//Очищает окно командной строки
    printf("\n\n%s has been defeat! You earn %d coins and %d LVL!\n", enemyName, enemyCoins, enemyEXP);
    //Враг побеждён, вы заработали n монет и n опыта
    playerCoins += enemyCoins;//Добавляет монеты с врага игроку
    playerEXP += enemyEXP;//Добавляет опыт с врага игроку
    //Нужно нажать ENTER, чтобы продолжить
    printf("\nPress ENTER to continue\n");
    while (TRUE) {
        if (GetAsyncKeyState(VK_RETURN)) {
            keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
            break;
        }
    }
    lvlUpCheck();//Проверяет, поднял ли уровень игрок
    return 0;
}