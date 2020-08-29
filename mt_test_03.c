#include <stdio.h>
#include <unistd.h>
#include "lab_03/lab_03.h"

int main(void) {
    int sizeX, sizeY;
    printf("test mt_clrscr: screen will be cleared after 5 second:\n");
    sleep(5);
    mt_clrscr();
    mt_gotoXY(10, 10);
    mt_getscreensize(&sizeX, &sizeY);
    mt_setfgcolor(GREEN);
    mt_setbgcolor(BLUE);
    return 0;
}
