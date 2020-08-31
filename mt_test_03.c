#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>
//#include "lab_03/lab_03.h"
#include "lab_03/myTerm.h"

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
    srand(time(NULL));
    printf("test mt_gotoXY:\n");
    int sizeX, sizeY;
    if(0 > mt_getscreensize(&sizeY, &sizeX)) {
        perror("Error in mt_getscreensize\n");
        exit(EXIT_FAILURE);
    }
    printf("Now terminal has %d rows and %d cols\n", sizeY, sizeX);
    printf("Any error will be printed into stderr stream\n");
    printf("Put %d symbols in here:\n", sizeX);
    int i;
    int check;
    int x, y;
    for(i = 1; i <= sizeX; i++) {
        x = i; y = rand()%sizeY + 1;
        //printf("Try goto %d %d\n", x, y);
        check = mt_gotoXY(x, y);
        if(check < 0) {
            fprintf(stderr, "Error in mt_gotoXY X=%d Y=%d\n", x, y);
            sleep(10);
            break;
        }
        printf("%d", i%10);
        check = mt_gotoXY(1, 1);
        if(check < 0) {
            fprintf(stderr, "Error in mt_gotoXY X=%d Y=%d\n", 1, 1);
            sleep(10);
            break;
        }
        printf("\n");
    }
    check = mt_gotoXY(1, 4);
    if(check < 0) {
        fprintf(stderr, "Error in mt_gotoXY X=%d Y=%d\n", x, y);
    }
    printf("Now test incorrect values of x, y\n");
    
    x = 0; y = 1;
    printf("x=%d y=%d\n", x, y);
    sleep(2);
    check = mt_gotoXY(x, y);
    if(check < 0) {
        fprintf(stderr, "Error in mt_gotoXY X=%d Y=%d\n", x, y);
    }
    
    x = 1; y = 0;
    printf("x=%d y=%d\n", x, y);
    sleep(2);
    check = mt_gotoXY(x, y);
    if(check < 0) {
        fprintf(stderr, "Error in mt_gotoXY X=%d Y=%d\n", x, y);
    }
    
    x = sizeX + 1; y = 1;
    printf("x=%d y=%d\n", x, y);
    sleep(2);
    check = mt_gotoXY(x, y);
    if(check < 0) {
        fprintf(stderr, "Error in mt_gotoXY X=%d Y=%d\n", x, y);
    }
    
    x = 1; y = sizeY + 1;
    printf("x=%d y=%d\n", x, y);
    sleep(2);
    check = mt_gotoXY(x, y);
    if(check < 0) {
        fprintf(stderr, "Error in mt_gotoXY X=%d Y=%d\n", x, y);
    }
    return 0;
}

int test_mt_getscreensize(void) {
    printf("test mt_getscreensize:\n");
    int sizeX, sizeY;
    if(0 > mt_getscreensize(&sizeY, &sizeX)) {
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
    if(0 > mt_getscreensize(&sizeY, &sizeX)) {
        perror("Error in mt_getscreensize\n");
        exit(EXIT_FAILURE);
    }
    printf("Now terminal has %d rows and %d cols\n", sizeY, sizeX);
    printf("Now try to use NULL pointers in mt_getscreensize\n");
    if(0 > mt_getscreensize(NULL, &sizeX)) {
        printf("Error in mt_getscreensize\n");
    }
    if(0 > mt_getscreensize(&sizeY, NULL)) {
        printf("Error in mt_getscreensize\n");
    }
    if(0 > mt_getscreensize(NULL, NULL)) {
        printf("Error in mt_getscreensize\n");
    }
    return 0;
}

int test_mt_setcolors() {
    printf("Test mt_setfgcolor  mt_setbgcolor in all right cases:\n");
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
    printf("Now try to set incorrect bg and fg colors:\n");
    fg_check = mt_setfgcolor(BG_WHITE);
    bg_check = mt_setbgcolor(FG_WHITE);
    printf("(%2d %2d)", bg_check, fg_check);
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
