//
// Created by Hikinari on 24.01.2023.
//

#include "includes/global.h"

int lvlUpCheck() {
    //Поверка поднял ли игрок уровень и повышение характеристик в таком случае
    if (playerEXP / levelEXP > 0) {
        int hpUp = rand() % 25 + 5;//На сколько поднимается макс. ХП игрока
        int dmgUp = rand() % 5 + 1;//На сколько поднимается урон игрока
        system("cls");//Очищает окно командной строки
        ++playerLevel;//увеличивает уровень игрока
        printf("\nCongratulations %s! You got level %d!\n"
               "\nYour damage has increased by %d and your max health has increased by %d!\n", nickname,
               playerLevel, dmgUp, hpUp);
        //Поздравляем, вы подняли уровень, ваш урон и макс. ХП выросли
        playerMaxHP += hpUp;//Повышает макс ХП игрока
        playerHP += hpUp;//Лечит игрока
        playerDmg += dmgUp;//Повышает урон игрока
        playerEXP = (playerEXP - levelEXP) % levelEXP;//Переносит излишки опыта на следующий уровень
        levelEXP += 100;//Увеличивает количество урона, необходимое для следующего поднятия уровня
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
    return 0;
}