    //
// Created by Hikinari on 24.01.2023.
//
#include "includes/global.h"

int playerDeathCheck() {
    // Проверка смерти игрока и окончание игры в таком случае
    if (playerHP == 0) {
        system("cls");//Очищает окно командной строки
        printf("\n\nYou are dead! Game over!\n");//Вы умерли, конец игры
        saveTheGame();//Сохраняет игру
        getchar();//Оставляет консоль открытой пока не нажать кнопку
        getchar();
        exit(0);//Выход из программы с кодом 0
    }
    return 0;
}
