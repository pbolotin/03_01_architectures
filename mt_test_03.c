#include "lab_03/lab_03.h"
#include <stdio.h>

int main(void) {
    int sizeX, sizeY;
    mt_clrscr();
    mt_gotoXY(10, 10);
    mt_getscreensize(&sizeX, &sizeY);
    mt_setfgcolor(GREEN);
    mt_setbgcolor(BLUE);
    return 0;
}
