//
// Created by Hikinari on 28.01.2023.
//

#include "includes/global.h"

int battleTutorial() {
    printf("\n\n                 TUTORIAL\n\nAttack - you deal full DMG(%d) and take full enemy DMG\n"
           "Parry - you deal a random amount of damage(Maximum - %d) + 10%% of your damage(%d)\n"
           "Run - go to lobby.\n\n", playerDmg, playerDmg, playerDmg / 10);
    printf("Enemies has a random DMG and HP, which depend of their LVL and modifier\n\n");
}
