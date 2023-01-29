//
// Created by Hikinari on 24.01.2023.
//

#include "includes/global.h"

void enemyChooseMenu(int action) {
    //Вывод списка пунктов на выбор
    system("cls");//Очищает окно командной строки
    printf("\nChoose enemy, %s:", nickname);//Выберите врага
    printf("\n%s 1. Goblin(1x HP and DMG)", action == 1 ? ">" : " ");
    printf("\n%s 2. Cobold(2x HP and DMG)", action == 2 ? ">" : " ");
    printf("\n%s 3. Murlok(3x HP and DMG)", action == 3 ? ">" : " ");
    printf("\n%s 4. Vasilisk(4x HP and DMG)\n", action == 4 ? ">" : " ");
}

int enemyChoose(char *enemyName) {
    // Выбор противника на бой
    int enemyMod = 0;
    int action = 1;
    int laction = 4;


    enemyChooseMenu(action);

    while (enemyMod == 0) {
        //Бесконечный цикл, который закончится после выбора врага
        if (GetAsyncKeyState(VK_UP)) {
            //Стрелка выбора перескакивает вверх при нажатии на клавиатуре стрелки вверх
            keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            if (0 < action - 1)
                action = action - 1;
            else
                action = laction;
            enemyChooseMenu(action);
        }
        if (GetAsyncKeyState(VK_DOWN)) {
            //Стрелка выбора перескакивает вниз при нажатии на клавиатуре стрелки вниз
            keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            if (action < laction)
                action = action + 1;
            else
                action = 1;
            enemyChooseMenu(action);
        }
        if (GetAsyncKeyState(VK_RETURN)) {
            //Выбирается и выполняется тот пункт, на который сейчас указывает стрелка при нажатии Enter
            keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
            enemyChooseMenu(action);
            switch (action) {
                case 1:
                    //Выбор Гоблина в качестве врага
                    enemyMod = 1;
                    strcpy(enemyName, "Goblin");//Изменение переменной имени врага
                    break;
                case 2:
                    //Выбор Кобольда в качестве врага
                    enemyMod = 2;
                    strcpy(enemyName, "Cobold");//Изменение переменной имени врага
                    break;
                case 3:
                    //Выбор Мурлока в качестве врага
                    enemyMod = 3;
                    strcpy(enemyName, "Murlok");//Изменение переменной имени врага
                    break;
                case 4:
                    //Выбор Василиска в качестве врага
                    enemyMod = 4;
                    strcpy(enemyName, "Vasilisk");//Изменение переменной имени врага
                    break;
            }
        }
    }
    return enemyMod;//Возвращает модификатор врага
}