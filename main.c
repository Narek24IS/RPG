#include "headers/global.h"
#include "headers/main.h"

int main() {
    //Основное действие
    srand(time(NULL));

    hello();

    while (1)
    {
        act_choose();
    }
}