#include <stdio.h>
#include "lab_04/myBigChars.h"

int main() {
    /*
    printf("All chars:");
    for(int i = 0 ; i < 256; i++) {
        printf("%d - %c - ", i ,(unsigned char)i);
        printf("%s", ALT_CHARSET_ON);
        printf("%c\n", (unsigned char)i);
        printf("%s", ALT_CHARSET_OFF);
    }*/
    //bc_printA("taaaat");
    //bc_box(1, 1, 24, 124);
    int bigchar[2];
    _bc_getbigcharmatrix_as_int_array_by_number(0, bigchar);
    bc_printbigchar(bigchar, 1, 1, FG_WHITE, BG_BLUE);
    _bc_getbigcharmatrix_as_int_array_by_number(1, bigchar);
    bc_printbigchar(bigchar, 1, 8+1, FG_LIGHT_PURPLE, BG_BLACK);
    _bc_getbigcharmatrix_as_int_array_by_number(2, bigchar);
    bc_printbigchar(bigchar, 1, 16+1, FG_WHITE, BG_BLUE);
    _bc_getbigcharmatrix_as_int_array_by_number(3, bigchar);
    bc_printbigchar(bigchar, 1, 24+1, FG_WHITE, BG_BLACK);
    _bc_getbigcharmatrix_as_int_array_by_number(4, bigchar);
    bc_printbigchar(bigchar, 1, 32+1, FG_YELLOW, BG_BLUE);
    _bc_getbigcharmatrix_as_int_array_by_number(5, bigchar);
    bc_printbigchar(bigchar, 1, 40+1, FG_RED, BG_BLACK);
    _bc_getbigcharmatrix_as_int_array_by_number(6, bigchar);
    bc_printbigchar(bigchar, 1, 48+1, FG_YELLOW, BG_BLUE);
    _bc_getbigcharmatrix_as_int_array_by_number(7, bigchar);
    bc_printbigchar(bigchar, 1, 56+1, FG_RED, BG_WHITE);
    _bc_getbigcharmatrix_as_int_array_by_number(8, bigchar);
    bc_printbigchar(bigchar, 1, 64+1, FG_YELLOW, BG_WHITE);
    _bc_getbigcharmatrix_as_int_array_by_number(9, bigchar);
    bc_printbigchar(bigchar, 1, 72+1, FG_RED, BG_BLACK);
    //bc_bigcharread
    //bc_bigcharwrite
    //bc_getbigcharpos
    //bc_setbigcharpos
    return 0;
}
