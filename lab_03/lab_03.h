#ifndef _LAB_03_
#define _LAB_03_

enum colors {BLACK, RED, GREEN, BLUE};

#define CLEAR_SEQ "\E[H\E[2J"
int mt_clrscr(void);

/* if defined MOVEXY_BORDERS
 * then there error will be if there was trying to
 * move cursor out of the screen*/
#define MOVEXY_BORDERS

#define MOVEXY_SEQ_BEGIN "\E["
#define MOVEXY_SEQ_MIDDLE ";"
#define MOVEXY_SEQ_END "H"
#define MOVEXY_STR_INT_MAX_LENGTH 20
int mt_gotoXY(int X, int Y);

int mt_getscreensize(int *rows, int *cols);

int mt_setfgcolor(enum colors);

int mt_setbgcolor(enum colors);

#endif
