#include <stdio.h>
#include "lab_03.h"

int mt_clrscr(void) {
    if(printf("mt_clrscr\n") < 0) {
        return -1;
    }
    return 0;
}

int mt_gotoXY(int X, int Y) {
    if(printf("mt_gotoXY\n") < 0) {
        return -1;
    }
    return 0;
}

int mt_getscreensize(int *rows, int *cols) {
    if(printf("mt_getscreensize\n") < 0) {
        return -1;
    }
    return 0;
}

int mt_setfgcolor(enum colors fg) {
    if(printf("mt_setfgcolor\n") < 0) {
        return -1;
    }
    return 0;
}

int mt_setbgcolor(enum colors bg) {
    if(printf("mt_setbgcolor\n") < 0) {
        return -1;
    }
    return 0;
}
