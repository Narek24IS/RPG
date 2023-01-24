#include "global.h"

int player_death_check() {
    // Проверка смерти игрока и окончание игры в таком случае
    if (player_hp == 0) {
        printf("You are dead! Game over!\n");
        exit(0);
    }
    return 0;
}

int lvl_up_check() {
    // Поверка поднял ли игрок уровень и повышение характеристик в таком случае
    int hp_up = rand() % 25;
    if (player_exp / level_exp > 0) {
        int dmg_up = rand() % 5 + 1;
        ++player_level;
        printf("Congratulations! You got level %d!\n\
Your damage has increased by %d and your max health has increased by %d!\n\n",
               player_level, dmg_up, hp_up);
        player_max_hp += hp_up;
        player_hp += hp_up;
        player_dmg += dmg_up;
        player_exp = player_exp % level_exp;
        level_exp += 100;
    }

    return 0;
}

int enemy_choose(int action, char *enemy_name) {
    // Выбор противника на бой
    int enemy_mod = 0;

    while (enemy_mod == 0) {
        if (action == '1') {
            enemy_mod = 1;
            strcpy(enemy_name, "Goblin");
            fflush(stdin);
        } else if (action == '2') {
            enemy_mod = 2;
            strcpy(enemy_name, "Cobold");
            fflush(stdin);
        } else if (action == '3') {
            enemy_mod = 3;
            strcpy(enemy_name, "Murlok");
            fflush(stdin);
        } else if (action == '4') {
            enemy_mod = 4;
            strcpy(enemy_name, "Ent");
            fflush(stdin);
        } else {
            printf("Please, select one of the options from the list!\n\n");
            fflush(stdin);
        }
    }
    return enemy_mod;
}

int looting(int enemy_mod, int enemy_lvl, char *enemy_name) {
    // Выпадение награды за победу над противником
    int enemy_exp = (rand() % 50 + enemy_mod + enemy_lvl) * enemy_mod * enemy_lvl;
    int enemy_coins = rand() % 4 + enemy_mod + enemy_lvl;

    printf("\n%s has been defeat! You earn %d coins and %d EXP!\n\n", enemy_name, enemy_coins, enemy_exp);
    player_coins += enemy_coins;
    player_exp += enemy_exp;
    lvl_up_check();
    return 0;
}

int battle() {
    // Механика сражения, выборы действий
    int action;
    int enemy_mod;
    int enemy_lvl = rand() % player_level + 1;
    int enemy_hp;
    char enemy_name[10];

    printf("\nChoose enemy:\n 1. Goblin\n 2. Cobold\n "
           "3. Murlok\n 4. Ent\n");

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

        printf("\nYour HP:%d\n\n%s's HP:%d\n", player_hp, enemy_name, enemy_hp);

        player_death_check();

        fflush(stdin); // clear buffer

        if (enemy_hp == 0) {
            looting(enemy_mod, enemy_lvl, enemy_name);
            break;
        }
    }
    return 0;
}

int status() {
    // Показывает все характеристики игрока на данный момент
    printf("%s\n\nLevel:%d\n\nEXP:%d/%d\n\nHP:%d/%d\n\nDamage:%d\n\nYour coins:%d\n\n",
           nickname, player_level, player_exp, level_exp, player_hp, player_max_hp,
           player_dmg, player_coins);

    return 0;
}

int hello() {
    // Начальное приветствие игрока

    printf("Hi, adventurer! What is your name?\n");

    fgets(nickname, sizeof(nickname), stdin); // ввод ника

    if (nickname[strlen(nickname) - 1] == '\n')
        nickname[strlen(nickname) - 1] = '\0'; // убрать Enter в конце ника из буфера
    else
        fflush(stdin); // очистить буфер от лишних символов

    printf("Okay, %s, now let's check your stats!\n"
           "Press Enter to check your stats...",
           nickname);
    getchar();
    fflush(stdin);
    status();
    printf("Not bad! Let's see how you fight!\n"
           "Choose your enemy!\n");
    battle();

    return 0;
}

int healed() {
    // Лечение за деньги
    int sp_coin;

    printf("How many coins do you want to spend on healing?"
           "\n1 coin = 5 HP\nNow you have %d/%d HP and %d coins\n", player_hp, player_max_hp, player_coins);
    scanf("%d", &sp_coin);
    if (sp_coin > player_coins) {
        printf("You have only %d coins.", player_coins);
    } else {
        player_hp += (sp_coin * 5);
        player_coins -= sp_coin;
        if (player_hp > player_max_hp)
            player_hp = player_max_hp;
        printf("You were healed by %d HP!\n\n Your HP: %d",
               sp_coin * 5, player_hp);
    }
    return 0;
}

int act_choose() {
    // Выбор следующего действия
    int action;

    printf("\nChoose an action:\n 1. Fight with another enemy\n 2. Check your status\n "
           "3. Heal for coins\n 4. Quit the game\n");

    action = getchar();

    if (action == '1') {
        fflush(stdin);
        battle();
    } else if (action == '2') {
        status();
        fflush(stdin);
    } else if (action == '3') {
        healed();
        fflush(stdin);
    } else if (action == '4') {
        printf("Good Bye!\n");
    } else {
        printf("Please, select one of the options from the list!\n\n");
        fflush(stdin);

    }
    return 0;
}

int main() {
    //Основное действие
    srand(time(NULL));

    hello();

    while (1)
    {
        act_choose();
    }
}