//
// Created by Hikinari on 29.01.2023.
//

#include "includes/global.h"

void noCursor() {
    //Убирает курсор в консоли
    HANDLE handle = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_CURSOR_INFO structCursorInfo;
    GetConsoleCursorInfo(handle, &structCursorInfo);
    structCursorInfo.
            bVisible = FALSE;
    SetConsoleCursorInfo(handle, &structCursorInfo);
}
