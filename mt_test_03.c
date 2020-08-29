#include <stdio.h>
#include <unistd.h>
#include "lab_03/lab_03.h"

int test_mt_clrscr(void) {
    printf("test mt_clrscr: screen will be cleared after 5 second:\n");
    printf("5\n");
    sleep(1);
    printf("4\n");
    sleep(1);
    printf("3\n");
    sleep(1);
    printf("2\n");
    sleep(1);
    printf("1\n");
    sleep(1);
    mt_clrscr();
    return 0;
}

int main(void) {
    int sizeX, sizeY;
    test_mt_clrscr();
    mt_gotoXY(10, 10);
    mt_getscreensize(&sizeX, &sizeY);
    mt_setfgcolor(GREEN);
    mt_setbgcolor(BLUE);
    return 0;
}
