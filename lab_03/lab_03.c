#include <malloc.h>
#include <stdio.h>
#include <string.h>
#include <termios.h>
#include <sys/ioctl.h>
#include "lab_03.h"

int mt_clrscr(void) {
    if(printf(CLEAR_SEQ) < 0) {
        return -1;
    }
    return 0;
}

int mt_gotoXY(int X, int Y) {
    #ifdef MOVEXY_BORDERS
    int sizeX, sizeY;
    mt_getscreensize(&sizeX, &sizeY);
    if(X > sizeX || X <=0) return -1;
    if(Y > sizeY || Y <=0) return -1;
    #endif
    int need_length = 0;
    need_length = strlen(MOVEXY_SEQ_BEGIN) +\
                  strlen(MOVEXY_SEQ_MIDDLE) +\
                  strlen(MOVEXY_SEQ_END) +\
                  MOVEXY_STR_INT_MAX_LENGTH +\
                  MOVEXY_STR_INT_MAX_LENGTH;
    char *seq = (char*)calloc(need_length + 1, sizeof(char));
    if(NULL == seq) {
        perror("calloc in mt_gotoXY\n");
        return -1;
    }
    snprintf(seq,\
             need_length,\
             "%s%d%s%d%s",\
             MOVEXY_SEQ_BEGIN,\
             X,\
             MOVEXY_SEQ_MIDDLE,\
             Y,\
             MOVEXY_SEQ_END);
    if(printf("%s", seq) < 0) {
        free(seq);
        return -1;
    }
    free(seq);
    return 0;
}

int mt_getscreensize(int *rows, int *cols) {
    struct winsize ws;
    //unsigned short ws_row;
    //unsigned short ws_col;
    //unsigned short ws_xpixel;   /* unused */
    //unsigned short ws_ypixel;   /* unused */
    //0x00005413   TIOCGWINSZ       struct winsize *
    int ret = ioctl(1, TIOCGWINSZ, (char*)&ws);
    if(ret < 0) {
        perror("ioctl in mt_getscreensize\n");
        return -1;
    }
    *rows = ws.ws_row;
    *cols = ws.ws_col;
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
