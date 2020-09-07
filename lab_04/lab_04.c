#include <stdio.h>
#include <unistd.h>
#include "lab_04.h"

//alt charset str output
int bc_printA(char *str) {
    return 0;
}

//x1 row, y1 col, x2 row_high, y2 col_width
int bc_box(int x1, int y1, int x2, int y2) {
    return 0;
}

//8x8 big symbol, 
//x y left up corner,
//x row, y col, color foreground, color background
//output bits of int array
int bc_printbigchar(int arr[2], int x, int y, enum colors f, enum colors b) {
    return 0;
}

//set value of the "symbolplace" of the big symbol in row x and col y
int bc_setbigcharpos(int *big, int x, int y, int value) {
    return 0;
}

//get value of the "symbolplace" of the big symbol in row x and col y
int bc_getbigcharpos(int *big, int x, int y, int *value) {
    return 0;
}

//Save count of "big-symbols" in the file, format of the file is userdefined
int bc_bigcharwrite(int fd, int* big, int count) {
    return 0;
}

//Read count of "big-symbols" from the file, count for how many was read, or error
int bc_bigcharread(int fd, int* big, int need_count, int *count) {
    return 0;
}

//all return 0 if success or -1 if failed
