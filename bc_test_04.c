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
    printf("\n%08x %08x\n", (void*)bigchar[0], (void*)bigchar[1]);
    bc_printbigchar(bigchar, 2, 1, FG_YELLOW, BG_BLUE);
    //bc_bigcharread
    //bc_bigcharwrite
    //bc_getbigcharpos
    //bc_setbigcharpos
    return 0;
}
