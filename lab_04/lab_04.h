#ifndef _LAB_04_

#define _LAB_04_

#include "../lab_03/lab_03.h"

//alt charset str output
int bc_printA(char *str);

//x1 row, y1 col, x2 row_high, y2 col_width
int bc_box(int x1, int y1, int x2, int y2);

//8x8 big symbol, 
//x y left up corner,
//x row, y col, color foreground, color background
//output bits of big array
int bc_printbigchar(int *big, int x, int y, enum colors, enum colors);

//set value of the "symbolplace" of the big symbol in row x and col y
int bc_setbigcharpos(int *big, int x, int y, int value);

//get value of the "symbolplace" of the big symbol in row x and col y
int bc_getbigcharpos(int *big, int x, int y, int *value);

//Save count of "big-symbols" in the file, format of the file is userdefined
int bc_bigcharwrite(int fd, int* big, int count);

//Read count of "big-symbols" from the file, count for how many was read, or error
int bc_bigcharread(int fd, int* big, int need_count, int *count);

//all return 0 if success or -1 if failed

#endif
