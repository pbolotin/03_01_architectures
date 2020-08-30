#include <malloc.h>
#include <stdio.h>
#include <string.h>
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
    *rows = 0;
    *cols = 0;
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
