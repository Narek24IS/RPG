//
// Created by Hikinari on 24.01.2023.
//
#include "main.h"
#include "battle.h"
#include "global.h"
#include "player_death_check.h"

int battle() {
    // Механика сражения, выборы действий
    int action;
    int enemy_mod;
    int enemy_lvl = rand() % player_level + 1;
    int enemy_hp;
    char enemy_name[10];

    printf("\nChoose enemy, %s:\n 1. Goblin\n 2. Cobold\n "
           "3. Murlok\n 4. Ent\n", nickname);

    action = getchar();

    enemy_mod = enemy_choose(action, enemy_name);

    enemy_hp = enemy_lvl * player_dmg * enemy_mod - rand() % 10 * 10 / 15;

    printf("\nYou meet a %s:\nLevel:%d\nHP:%d\n", enemy_name, enemy_lvl, enemy_hp);

    for (; enemy_hp >= 0;) {
        int enemy_dmg = rand() % 4 * enemy_mod * enemy_lvl;

        printf("\nChoose an action:\n 1. Attack\n 2. Parry\n 3. Run\n");
        action = getchar();

        if (action == '1') {
            printf("You dealt %d damage to %s!\n", player_dmg, enemy_name);
            enemy_hp -= player_dmg;
            printf("%s dealt to you %d damage!\n", enemy_name, enemy_dmg);
            player_hp -= enemy_dmg;
            fflush(stdin);
        } else if (action == '2') {
            int min_e_mdg = enemy_dmg / 3;

            printf("You parry the %s attack and damage %d to him!\n", enemy_name, player_dmg / 2);
            enemy_hp -= player_dmg / 2;
            printf("%s dealt to you %d damage!\n", enemy_name, min_e_mdg);
            player_hp -= min_e_mdg;
            fflush(stdin);
        } else if (action == '3') {
            printf("You ran away");
            fflush(stdin);
            break;
        } else {
            printf("\nChoose one of the 1-3 buttons,what to perform the action\n");
            fflush(stdin);
        }

        if (enemy_hp < 0)
            enemy_hp = 0;

        if (player_hp < 0)
            player_hp = 0;

        printf("\nYour HP:%d\n%s's HP:%d\n", player_hp, enemy_name, enemy_hp);

        player_death_check();

        fflush(stdin); // clear buffer

        if (enemy_hp == 0) {
            looting(enemy_mod, enemy_lvl, enemy_name);
            break;
        }
    }
    return 0;
}