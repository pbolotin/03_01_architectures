#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
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

int test_mt_gotoXY(void) {
    int i = 1;
    while(-1 != mt_gotoXY(i, i)) {
        printf("%d\n", i);
        i++;
        sleep(1);
    }
    mt_gotoXY(1, 1);
    printf("error was at %d, %d position\n", i, i);
    return 0;
}

int test_mt_getscreensize(void) {
    printf("test mt_getscreensize:\n");
    int sizeX, sizeY;
    if(0 > mt_getscreensize(&sizeX, &sizeY)) {
        perror("Error in mt_getscreensize\n");
        exit(EXIT_FAILURE);
    }
    printf("Now terminal has %d rows and %d cols\n", sizeY, sizeX);
    
    int max_time = 10;
    printf("You have %d seconds to change terminal size, if you want to test\n", max_time);
    int i;
    for(i = max_time; i > 0; i--) {
        printf("%d\n", i);
        sleep(1);
    }
    if(0 > mt_getscreensize(&sizeX, &sizeY)) {
        perror("Error in mt_getscreensize\n");
        exit(EXIT_FAILURE);
    }
    printf("Now terminal has %d rows and %d cols\n", sizeY, sizeX);
    return 0;
}

int test_mt_setcolors() {
    enum colors bg, fg;
    int bg_check, fg_check;
    for(bg = BG_BLACK; bg <= BG_WHITE; bg++) {
        if(bg > BG_LIGHT_GRAY && bg < BG_DARK_GRAY) bg = BG_DARK_GRAY;
        for(fg = FG_BLACK; fg <= FG_WHITE; fg++) {
            if(fg > FG_LIGHT_GRAY && fg < FG_DARK_GRAY) fg = FG_DARK_GRAY;
            bg_check = mt_setbgcolor(bg);
            fg_check = mt_setfgcolor(fg);
            printf("(%2d %2d)", bg_check, fg_check);
        }
        mt_setbgcolor(BG_BLACK);
        printf("\n");
    }
    mt_setfgcolor(FG_LIGHT_GRAY);
    printf("\n");
    return 0;
}

int main(void) {
    int sizeX, sizeY;
    test_mt_clrscr();
    test_mt_gotoXY();
    test_mt_getscreensize();
    test_mt_setcolors();
    return 0;
}
