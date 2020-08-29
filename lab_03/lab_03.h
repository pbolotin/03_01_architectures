#ifndef _LAB_03_
#define _LAB_03_

enum colors {BLACK, RED, GREEN, BLUE};

int mt_clrscr(void);

int mt_gotoXY(int, int);

int mt_getscreensize(int *rows, int *cols);

int mt_setfgcolor(enum colors);

int mt_setbgcolor(enum colors);

#endif
