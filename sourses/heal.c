//
// Created by Hikinari on 24.01.2023.
//

#include "includes/global.h"

int heal() {
    // Лечение за деньги
    int sp_coin;

    printf("How many coins do you want to spend on healing?"
           "\n1 coin = 5 HP\nNow you have %d/%d HP and %d coins\nAmoun of coins:",
           player_hp, player_max_hp, player_coins);
    scanf("%d", &sp_coin);
    if (sp_coin > player_coins) {
        printf("You have only %d coins.", player_coins);
    } else {
        player_hp += (sp_coin * 5);
        player_coins -= sp_coin;
        if (player_hp > player_max_hp)
            player_hp = player_max_hp;
        printf("You were heal by %d HP!\nYour HP: %d",
               sp_coin * 5, player_hp);
    }
    return 0;
}
