//
// Created by Hikinari on 24.01.2023.
//

#include "includes/global.h"

void healMenu(int action) {
    system("cls");
    printf("Your HP: %d     Coins: %d", playerHP, playerCoins);
    printf("\nHow many coins do you want to spend on healing?");
    printf("\n%s 1. 1 coin - 5 HP", action == 1 ? ">" : " ");
    printf("\n%s 2. 3 coin - 15 HP", action == 2 ? ">" : " ");
    printf("\n%s 3. 5 coin - 25 HP", action == 3 ? ">" : " ");
    printf("\n%s 4. 10 coin - 50 HP", action == 4 ? ">" : " ");
    printf("\n%s 5. %d coin - %d HP", action == 4 ? ">" : " ", playerCoins, playerCoins*5);
    printf("\n%s 6. Full HP for %d coins", action == 5 ? ">" : " ", (playerMaxHP - playerHP) / 5);
    printf("\n%s 7. Return\n", action == 6 ? ">" : " ");
}

int heal() {
    // Лечение за деньги
    int spentCoin;
    int action = 1;
    int laction = 7;


    healMenu(action);

    if (playerCoins > 0) {
        while (TRUE) {

            if (GetAsyncKeyState(VK_UP)) {
                keybd_event(VK_UP, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
                if (0 < action - 1)
                    action = action - 1;
                else
                    action = laction;
                healMenu(action);
            }
            if (GetAsyncKeyState(VK_DOWN)) {
                keybd_event(VK_DOWN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку
                if (action < laction)
                    action = action + 1;
                else
                    action = 1;
                healMenu(action);
            }
            if (GetAsyncKeyState(VK_RETURN)) {
                keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);//Отжимаем кнопку

                healMenu(action);

                switch (action) {
                    case 1:

                        spentCoin = 1;
                        if (spentCoin > playerCoins) {
                            printf("You have only %d coins.\n", playerCoins);
                            healMenu(action);
                        } else {
                            playerHP += (spentCoin * 5);
                            playerCoins -= spentCoin;
                            if (playerHP > playerMaxHP)
                                playerHP = playerMaxHP;
                            printf("You were heal by %d HP!\n\nYour HP: %d\n",
                                   spentCoin * 5, playerHP);
                            printf("\nPress ENTER to continue\n");
                            while (TRUE) {
                                if (GetAsyncKeyState(VK_RETURN)) {
                                    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
                                    break;
                                }
                            }

                            goto end;
                        }
                    case 2:

                        spentCoin = 3;
                        if (spentCoin > playerCoins) {
                            printf("You have only %d coins.\n", playerCoins);
                            healMenu(action);
                        } else {
                            playerHP += (spentCoin * 5);
                            playerCoins -= spentCoin;
                            if (playerHP > playerMaxHP)
                                playerHP = playerMaxHP;
                            printf("You were heal by %d HP!\n\nYour HP: %d\n",
                                   spentCoin * 5, playerHP);
                            printf("\nPress ENTER to continue\n");
                            while (TRUE) {
                                if (GetAsyncKeyState(VK_RETURN)) {
                                    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
                                    break;
                                }
                            }

                            goto end;
                        }
                    case 3:
                        spentCoin = 5;
                        if (spentCoin > playerCoins) {
                            printf("You have only %d coins.\n", playerCoins);
                            healMenu(action);
                        } else {
                            playerHP += (spentCoin * 5);
                            playerCoins -= spentCoin;
                            if (playerHP > playerMaxHP)
                                playerHP = playerMaxHP;
                            printf("You were heal by %d HP!\n\nYour HP: %d\n",
                                   spentCoin * 5, playerHP);
                            printf("\nPress ENTER to continue\n");
                            while (TRUE) {
                                if (GetAsyncKeyState(VK_RETURN)) {
                                    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
                                    break;
                                }
                            }

                            goto end;
                        }
                    case 4:
                        spentCoin = 10;
                        if (spentCoin > playerCoins) {
                            printf("You have only %d coins.\n", playerCoins);
                            healMenu(action);
                        } else {
                            playerHP += (spentCoin * 5);
                            playerCoins -= spentCoin;
                            if (playerHP > playerMaxHP)
                                playerHP = playerMaxHP;
                            printf("You were heal by %d HP!\n\nYour HP: %d\n",
                                   spentCoin * 5, playerHP);
                            printf("\nPress ENTER to continue\n");
                            while (TRUE) {
                                if (GetAsyncKeyState(VK_RETURN)) {
                                    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
                                    break;
                                }
                            }

                            goto end;
                        }
                    case 5:
                        spentCoin = playerCoins;
                        playerHP = playerCoins*5;
                        playerCoins = 0;
                        if (playerHP > playerMaxHP)
                            playerHP = playerMaxHP;
                        printf("You were heal by %d HP!\n\n", playerCoins*5);
                        printf("\nPress ENTER to continue\n");
                        while (TRUE) {
                            if (GetAsyncKeyState(VK_RETURN)) {
                                keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
                                break;
                            }
                        }
                        goto end;
                    case 6:
                        spentCoin = (playerMaxHP - playerHP) / 5;
                        if (spentCoin > playerCoins) {
                            printf("You have only %d coins.\n", playerCoins);
                            healMenu(action);
                        } else {
                            playerHP = playerMaxHP;
                            playerCoins -= spentCoin;
                            printf("You were heal by full HP!\n\n");
                            printf("\nPress ENTER to continue\n");
                            while (TRUE) {
                                if (GetAsyncKeyState(VK_RETURN)) {
                                    keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
                                    break;
                                }
                            }

                            goto end;
                        }
                    case 7:
                        goto end;
                }

            }
        }
    } else {
        printf("\n\nYou haven't any coins!\n\n");
        printf("\nPress ENTER to continue\n");
        while (TRUE) {
            if (GetAsyncKeyState(VK_RETURN)) {
                keybd_event(VK_RETURN, 0, KEYEVENTF_KEYUP, 0);
                break;
            }
        }
    }
    end:
    return 0;
}
