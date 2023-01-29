#include "includes/global.h"

int main() {
    //Основное действие
    srand(time(NULL));

    hello();

    fflush(stdin);

    while(TRUE)
    {
        actChoose();
    }
}