#ifndef _LAB_03_
#define _LAB_03_

#define CLEAR_SEQ "\E[H\E[2J"
int mt_clrscr(void);

/* if defined MOVEXY_BORDERS
 * then there error will be if there was trying to
 * move cursor out of the screen*/
#define MOVEXY_BORDERS

#define MOVEXY_SEQ_BEGIN "\E["
#define MOVEXY_SEQ_MIDDLE ";"
#define MOVEXY_SEQ_END "H"
#define INT_MAX_LENGTH 20
int mt_gotoXY(int X, int Y);

int mt_getscreensize(int *rows, int *cols);
/*
 * Black       0;30     Dark Gray     1;30
 * Blue        0;34     Light Blue    1;34
 * Green       0;32     Light Green   1;32
 * Cyan        0;36     Light Cyan    1;36
 * Red         0;31     Light Red     1;31
 * Purple      0;35     Light Purple  1;35
 * Brown       0;33     Yellow        1;33
 * Light Gray  0;37     White         1;37
 */

//#define VERSION_01 /* 8 COLORS ALL PAIR FG & BG ARE VISIBLE */
#define VERSION_02 /* 16 COLORS HAS THE SAME COLORS FG & BG - INVISIBLE TEXT */

#ifdef VERSION_01
enum colors {FG_BLACK = 30,
             FG_RED,
             FG_GREEN,
             FG_BROWN,
             FG_BLUE,
             FG_PURPLE,
             FG_CYAN,
             FG_LIGHT_GRAY,
             
             BG_BLACK = 40,
             BG_RED,
             BG_GREEN,
             BG_BROWN,
             BG_BLUE,
             BG_PURPLE,
             BG_CYAN,
             BG_LIGHT_GRAY,
             
             FG_DARK_GRAY = 130,
             FG_LIGHT_RED,
             FG_LIGHT_GREEN,
             FG_YELLOW,
             FG_LIGHT_BLUE,
             FG_LIGHT_PURPLE,
             FG_LIGHT_CYAN,
             FG_WHITE,
};

#define BG_DARK_GRAY BG_BLACK
#define BG_LIGHT_RED BG_RED
#define BG_LIGHT_GREEN BG_GREEN
#define BG_YELLOW BG_BROWN
#define BG_LIGHT_BLUE BG_BLUE
#define BG_LIGHT_PURPLE BG_PURPLE
#define BG_LIGHT_CYAN BG_CYAN
#define BG_WHITE BG_LIGHT_GRAY

#define FG_DARK_GRAY FG_BLACK
#define FG_LIGHT_RED FG_RED
#define FG_LIGHT_GREEN FG_GREEN
#define FG_YELLOW FG_BROWN
#define FG_LIGHT_BLUE FG_BLUE
#define FG_LIGHT_PURPLE FG_PURPLE
#define FG_LIGHT_CYAN FG_CYAN
#define FG_WHITE FG_LIGHT_GRAY

#define SETFG_SEQ_BEGIN "\E["
#define SETFG_SEQ_END "m"
#define SETFG_SEQ_BEGIN_L "\E["
#define SETFG_SEQ_END_L ";1m"
int mt_setfgcolor(enum colors fg);

#define SETBG_SEQ_BEGIN "\E[0;"
#define SETBG_SEQ_END "m"
#define SETBG_SEQ_BEGIN_L "\E[0;"
#define SETBG_SEQ_END_L "m"
int mt_setbgcolor(enum colors bg);
#endif

#ifdef VERSION_02
enum colors {FG_BLACK = 30,
             FG_RED,
             FG_GREEN,
             FG_BROWN,
             FG_BLUE,
             FG_PURPLE,
             FG_CYAN,
             FG_LIGHT_GRAY,
             
             BG_BLACK = 40,
             BG_RED,
             BG_GREEN,
             BG_BROWN,
             BG_BLUE,
             BG_PURPLE,
             BG_CYAN,
             BG_LIGHT_GRAY,
             
             FG_DARK_GRAY = 90,
             FG_LIGHT_RED,
             FG_LIGHT_GREEN,
             FG_YELLOW,
             FG_LIGHT_BLUE,
             FG_LIGHT_PURPLE,
             FG_LIGHT_CYAN,
             FG_WHITE,
             
             BG_DARK_GRAY = 100,
             BG_LIGHT_RED,
             BG_LIGHT_GREEN,
             BG_YELLOW,
             BG_LIGHT_BLUE,
             BG_LIGHT_PURPLE,
             BG_LIGHT_CYAN,
             BG_WHITE};

#define SETFG_SEQ_BEGIN "\E["
#define SETFG_SEQ_END "m"
#define SETFG_SEQ_BEGIN_L ""
#define SETFG_SEQ_END_L ""
int mt_setfgcolor(enum colors fg);

#define SETBG_SEQ_BEGIN "\E["
#define SETBG_SEQ_END "m"
#define SETBG_SEQ_BEGIN_L ""
#define SETBG_SEQ_END_L ""
int mt_setbgcolor(enum colors bg);
#endif

#endif
