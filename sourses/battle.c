//
// Created by Hikinari on 24.01.2023.
//
#include "includes/global.h"

int battle() {
    // Механика сражения, выборы действий
    int action;
    int enemyMod;
    int enemyLVL = rand() % playerLevel + 1;
    int enemy_hp;
    char enemyName[10];

    enemyMod = enemyChoose(action, enemyName);

    enemy_hp = enemyLVL * playerDmg * enemyMod - rand() % 10 * 10 / 15;

    printf("\nYou meet a %s:\nLevel:%d\nHP:%d\n", enemyName, enemyLVL, enemy_hp);

    while (enemy_hp >= 0) {
        int enemy_dmg = rand() % 4 * enemyMod * enemyLVL;
        int min_e_mdg = enemy_dmg / 3;

        printf("\nChoose an action:\n 1. Attack\n 2. Parry\n 3. Run\n");
        action = getchar();

        switch (action) {
            case '1':
                printf("You dealt %d damage to %s!\n", playerDmg, enemyName);
                enemy_hp -= playerDmg;
                printf("%s dealt to you %d damage!\n", enemyName, enemy_dmg);
                playerHP -= enemy_dmg;
                fflush(stdin);
                break;
            case '2':
                printf("You parry the %s attack and damage %d to him!\n", enemyName, playerDmg / 2);
                enemy_hp -= playerDmg / 2;
                printf("%s dealt to you %d damage!\n", enemyName, min_e_mdg);
                playerHP -= min_e_mdg;
                fflush(stdin);
                break;
            case '3':
                printf("You ran away");
                fflush(stdin);
                break;
            default:
                printf("\nChoose one of the 1-3 buttons,what to perform the action\n");
                fflush(stdin);
                break;
        }

        if (action == '3')
            break;

        if (enemy_hp < 0)
            enemy_hp = 0;

        if (playerHP < 0)
            playerHP = 0;

        printf("\nYour HP:%d\n%s's HP:%d\n", playerHP, enemyName, enemy_hp);

        playerDeathCheck();

        fflush(stdin); // clear buffer

        if (enemy_hp == 0) {
            looting(enemyMod, enemyLVL, enemyName);
            break;
        }
    }
    return 0;
}