//
// Created by Hikinari on 24.01.2023.
//

#include "global.h"
#include "status.h"

int status() {
    // Показывает все характеристики игрока на данный момент
    printf("\n%s\nLevel:%d\nEXP:%d/%d\nHP:%d/%d\nDamage:%d\nYour coins:%d\n",
           nickname, player_level, player_exp, level_exp, player_hp, player_max_hp,
           player_dmg, player_coins);

    return 0;
}
