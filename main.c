#include "global.h"
#include "main.h"

int main() {
    //Основное действие
    srand(time(NULL));

    hello();

    while (1)
    {
        act_choose();
    }
}