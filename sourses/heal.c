//
// Created by Hikinari on 24.01.2023.
//

#include "includes/global.h"

int heal() {
    // Лечение за деньги
    int spentCoin;

    printf("How many coins do you want to spend on healing?"
           "\n1 coin = 5 HP\nNow you have %d/%d HP and %d coins\nAmoun of coins:",
           playerHP, playerMaxHP, playerCoins);

    while (1) {
        scanf("%d", &spentCoin);

        if (spentCoin>0) {
            if (spentCoin > playerCoins) {
                printf("You have only %d coins.\n", playerCoins);
            } else {
                playerHP += (spentCoin * 5);
                playerCoins -= spentCoin;
                if (playerHP > playerMaxHP)
                    playerHP = playerMaxHP;
                printf("You were heal by %d HP!\nYour HP: %d\n",
                       spentCoin * 5, playerHP);
                fflush(stdin);
                break;
            }
        }
        else {
            printf("Enter a number!\n");
            fflush(stdin);
        }
    }
    return 0;
}
