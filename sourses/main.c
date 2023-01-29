#include "includes/global.h"

int main() {
    //Основное действие
    srand(time(NULL));
    noCursor();
    setlocale(LC_ALL, "russian");
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    hello();

    while (TRUE) {
        actChoose();
    }
}