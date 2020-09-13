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

int mt_gotoXY(int rowX, int colY) {
    #ifdef MOVEXY_BORDERS
    int sizeColY, sizeRowX;
    mt_getscreensize(&sizeRowX, &sizeColY);
    if(colY > sizeColY || colY <=0) return -1;
    if(rowX > sizeRowX || rowX <=0) return -1;
    #endif
    
    int need_length = 0;
    need_length = strlen(MOVEXY_SEQ_BEGIN) +\
                  strlen(MOVEXY_SEQ_MIDDLE) +\
                  strlen(MOVEXY_SEQ_END) +\
                  INT_MAX_LENGTH +\
                  INT_MAX_LENGTH;
    char *seq = (char*)calloc(need_length + 1, sizeof(char));
    if(NULL == seq) {
        perror("calloc in mt_gotoXY\n");
        return -1;
    }
    snprintf(seq,\
             need_length,\
             "%s%d%s%d%s",\
             MOVEXY_SEQ_BEGIN,\
             rowX,\
             MOVEXY_SEQ_MIDDLE,\
             colY,\
             MOVEXY_SEQ_END);
    if(printf("%s", seq) < 0) {
        free(seq);
        return -1;
    }
    free(seq);
    return 0;
}

int mt_getscreensize(int *rows, int *cols) {
    if(NULL == rows || NULL == cols) return -1;
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

#ifdef VERSION_01

int mt_setfgcolor(enum colors fg) {
    if((fg < FG_BLACK || fg > FG_WHITE) ||\
       (fg > FG_LIGHT_GRAY && fg < FG_DARK_GRAY)) {
        return -1;
    }
    
    char *seq_begin = SETFG_SEQ_BEGIN;
    char *seq_end   = SETFG_SEQ_END;
    
    if(fg >= FG_DARK_GRAY) {
        fg -= FG_DARK_GRAY - FG_BLACK;
        seq_begin = SETFG_SEQ_BEGIN_L;
        seq_end   = SETFG_SEQ_END_L;
    }
    
    int need_length = 0;
    need_length = strlen(seq_begin) +\
                  strlen(seq_end) +\
                  INT_MAX_LENGTH;
    char *seq = (char*)calloc(need_length + 1, sizeof(char));
    if(NULL == seq) {
        perror("calloc in mt_setfgcolor\n");
        return -1;
    }
    snprintf(seq,\
             need_length,\
             "%s%d%s",\
             seq_begin,\
             (int)fg,\
             seq_end);
    if(printf("%s", seq) < 0) {
        free(seq);
        return -1;
    }
    free(seq);
    return 0;
}

int mt_setbgcolor(enum colors bg) {
    if((bg < BG_BLACK || bg > BG_WHITE) ||\
       (bg > BG_LIGHT_GRAY && bg < BG_DARK_GRAY)) {
        return -1;
    }
    
    char *seq_begin = SETBG_SEQ_BEGIN;
    char *seq_end   = SETBG_SEQ_END;
    
    if(bg >= BG_DARK_GRAY) {
        bg -= BG_DARK_GRAY - BG_BLACK;
        seq_begin = SETBG_SEQ_BEGIN_L;
        seq_end   = SETBG_SEQ_END_L;
    }
    
    int need_length = 0;
    need_length = strlen(seq_begin) +\
                  strlen(seq_end) +\
                  INT_MAX_LENGTH;
    char *seq = (char*)calloc(need_length + 1, sizeof(char));
    if(NULL == seq) {
        perror("calloc in mt_setbgcolor\n");
        return -1;
    }
    snprintf(seq,\
             need_length,\
             "%s%d%s",\
             seq_begin,\
             (int)bg,\
             seq_end);
    if(printf("%s", seq) < 0) {
        free(seq);
        return -1;
    }
    free(seq);
    return 0;
}

#endif

#ifdef VERSION_02

int mt_setfgcolor(enum colors fg) {
    if((fg < FG_BLACK || fg > FG_WHITE) ||\
       (fg > FG_LIGHT_GRAY && fg < FG_DARK_GRAY)) {
        return -1;
    }
    
    char *seq_begin = SETFG_SEQ_BEGIN;
    char *seq_end   = SETFG_SEQ_END;
   
    int need_length = 0;
    need_length = strlen(seq_begin) +\
                  strlen(seq_end) +\
                  INT_MAX_LENGTH;
    char *seq = (char*)calloc(need_length + 1, sizeof(char));
    if(NULL == seq) {
        perror("calloc in mt_setfgcolor\n");
        return -1;
    }
    snprintf(seq,\
             need_length,\
             "%s%d%s",\
             seq_begin,\
             (int)fg,\
             seq_end);
    if(printf("%s", seq) < 0) {
        free(seq);
        return -1;
    }
    free(seq);
    return 0;
}

int mt_setbgcolor(enum colors bg) {
    if((bg < BG_BLACK || bg > BG_WHITE) ||\
       (bg > BG_LIGHT_GRAY && bg < BG_DARK_GRAY)) {
        return -1;
    }
    
    char *seq_begin = SETBG_SEQ_BEGIN;
    char *seq_end   = SETBG_SEQ_END;
    
    int need_length = 0;
    need_length = strlen(seq_begin) +\
                  strlen(seq_end) +\
                  INT_MAX_LENGTH;
    char *seq = (char*)calloc(need_length + 1, sizeof(char));
    if(NULL == seq) {
        perror("calloc in mt_setbgcolor\n");
        return -1;
    }
    snprintf(seq,\
             need_length,\
             "%s%d%s",\
             seq_begin,\
             (int)bg,\
             seq_end);
    if(printf("%s", seq) < 0) {
        free(seq);
        return -1;
    }
    free(seq);
    return 0;
}

#endif

