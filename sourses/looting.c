//
// Created by Hikinari on 24.01.2023.
//

#include "includes/global.h"

int looting(int enemy_mod, int enemy_lvl, char *enemy_name) {
    // Выпадение награды за победу над противником
    int enemy_exp = (rand() % 50 + enemy_mod + enemy_lvl) * enemy_mod * enemy_lvl;
    int enemy_coins = rand() % 4 + enemy_mod + enemy_lvl;

    printf("\n%s has been defeat! You earn %d coins and %d EXP!\n", enemy_name, enemy_coins, enemy_exp);
    player_coins += enemy_coins;
    player_exp += enemy_exp;
    lvl_up_check();
    return 0;
}