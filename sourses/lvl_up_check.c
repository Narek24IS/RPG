//
// Created by Hikinari on 24.01.2023.
//

#include "includes/lvl_up_check.h"
#include "includes/global.h"

int lvl_up_check() {
    // Поверка поднял ли игрок уровень и повышение характеристик в таком случае
    int hp_up = rand() % 25;
    if (player_exp / level_exp > 0) {
        int dmg_up = rand() % 5 + 1;
        ++player_level;
        printf("Congratulations %s! You got level %d!\n\
Your damage has increased by %d and your max health has increased by %d!\n",nickname,
               player_level, dmg_up, hp_up);
        player_max_hp += hp_up;
        player_hp += hp_up;
        player_dmg += dmg_up;
        player_exp = player_exp % level_exp;
        level_exp += 100;
    }

    return 0;
}