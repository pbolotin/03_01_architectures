#include <stdio.h>
#include <unistd.h>
#include "lab_04.h"
#include "../lab_03/lab_03.h"

const char* bigchar_0[8] = {
    "  aaaa  ",
    " a    a ",
    "a    a a",
    "a   a  a",
    "a  a   a",
    "a a    a",
    " a    a ",
    "  aaaa  "
};

const char* bigchar_1[8] = {
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        "
};

const char* bigchar_2[8] = {
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        "
};

const char* bigchar_3[8] = {
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        "
};

const char* bigchar_4[8] = {
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        "
};

const char* bigchar_5[8] = {
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        "
};

const char* bigchar_6[8] = {
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        "
};

const char* bigchar_7[8] = {
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        "
};

const char* bigchar_8[8] = {
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        "
};

const char* bigchar_9[8] = {
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        ",
    "        "
};

//alt charset str output
int bc_printA(char *str) {
    if(str == NULL) return -1;
    printf("%s%s%s", ALT_CHARSET_ON, str, ALT_CHARSET_OFF);
    return 0;
}

//x1 row, y1 col, x2 height, y2 width
int bc_box(int x1, int y1, int x2, int y2) {
    
    //printf("bc_box test\n");
    if(x1 < 1 || y1 < 1 || x2 < 2 || y2 < 2) return -1;
    int screen_rows, screen_cols;
    mt_getscreensize(&screen_rows, &screen_cols);
    if(x1 + x2 - 1 > screen_rows || y1 + y2 - 1 > screen_cols) return -1;

    printf("%s", ALT_CHARSET_ON);
    int i;
    /*Move*/
    mt_gotoXY(x1, y1);
    /*upper left*/
    printf("l");
    for(i = 1; i < y2 - 1; i++) {
        /*horisontal*/
        printf("q");
    }
    /*upper right*/
    printf("k");
    /*Left side*/
    for(i = 1; i < x2 - 1; i++) {
        /*vertical*/
        mt_gotoXY(x1 + i, y1);
        printf("x");
    }
    /*Right side*/
    for(i = 1; i < x2 - 1; i++) {
        /*vertical*/
        mt_gotoXY(x1 + i, y1 + y2 - 1);
        printf("x");
    }
    /*Move*/
    mt_gotoXY(x1 + x2 - 1, y1);
    /*bottom left*/
    printf("m");
    for(i = 1; i < y2 - 1; i++) {
        /*horisontal*/
        printf("q");
    }
    /*bottom right*/
    printf("j");
    printf("%s", ALT_CHARSET_OFF);
    return 0;
}

//8x8 big symbol, 
//x y left up corner,
//x row, y col, color foreground, color background
//output bits of int array
int bc_printbigchar(int arr[2], int x, int y, enum colors f, enum colors b) {
    printf("bc_printbigchar test\n");
    /*Output*/
    mt_setfgcolor(f);
    mt_setbgcolor(b);
    bigcharmatrix* bcm = (bigcharmatrix*)arr;
    /*Goto*/
    mt_gotoXY(x, y);
    printf("%c", bcm->b0_0 == 1? 'a': ' ');
    printf("%c", bcm->b0_1 == 1? 'a': ' ');
    printf("%c", bcm->b0_2 == 1? 'a': ' ');
    printf("%c", bcm->b0_3 == 1? 'a': ' ');
    printf("%c", bcm->b0_4 == 1? 'a': ' ');
    printf("%c", bcm->b0_5 == 1? 'a': ' ');
    printf("%c", bcm->b0_6 == 1? 'a': ' ');
    printf("%c", bcm->b0_7 == 1? 'a': ' ');
    /*Goto*/
    mt_gotoXY(x + 1, y);
    printf("%c", bcm->b1_0 == 1? 'a': ' ');
    printf("%c", bcm->b1_1 == 1? 'a': ' ');
    printf("%c", bcm->b1_2 == 1? 'a': ' ');
    printf("%c", bcm->b1_3 == 1? 'a': ' ');
    printf("%c", bcm->b1_4 == 1? 'a': ' ');
    printf("%c", bcm->b1_5 == 1? 'a': ' ');
    printf("%c", bcm->b1_6 == 1? 'a': ' ');
    printf("%c", bcm->b1_7 == 1? 'a': ' ');
    /*Goto*/
    mt_gotoXY(x + 2, y);
    printf("%c", bcm->b2_0 == 1? 'a': ' ');
    printf("%c", bcm->b2_1 == 1? 'a': ' ');
    printf("%c", bcm->b2_2 == 1? 'a': ' ');
    printf("%c", bcm->b2_3 == 1? 'a': ' ');
    printf("%c", bcm->b2_4 == 1? 'a': ' ');
    printf("%c", bcm->b2_5 == 1? 'a': ' ');
    printf("%c", bcm->b2_6 == 1? 'a': ' ');
    printf("%c", bcm->b2_7 == 1? 'a': ' ');
    /*Goto*/
    mt_gotoXY(x + 3, y);
    printf("%c", bcm->b3_0 == 1? 'a': ' ');
    printf("%c", bcm->b3_1 == 1? 'a': ' ');
    printf("%c", bcm->b3_2 == 1? 'a': ' ');
    printf("%c", bcm->b3_3 == 1? 'a': ' ');
    printf("%c", bcm->b3_4 == 1? 'a': ' ');
    printf("%c", bcm->b3_5 == 1? 'a': ' ');
    printf("%c", bcm->b3_6 == 1? 'a': ' ');
    printf("%c", bcm->b3_7 == 1? 'a': ' ');
    /*Goto*/
    mt_gotoXY(x + 4, y);
    printf("%c", bcm->b4_0 == 1? 'a': ' ');
    printf("%c", bcm->b4_1 == 1? 'a': ' ');
    printf("%c", bcm->b4_2 == 1? 'a': ' ');
    printf("%c", bcm->b4_3 == 1? 'a': ' ');
    printf("%c", bcm->b4_4 == 1? 'a': ' ');
    printf("%c", bcm->b4_5 == 1? 'a': ' ');
    printf("%c", bcm->b4_6 == 1? 'a': ' ');
    printf("%c", bcm->b4_7 == 1? 'a': ' ');
    /*Goto*/
    mt_gotoXY(x + 5, y);
    printf("%c", bcm->b5_0 == 1? 'a': ' ');
    printf("%c", bcm->b5_1 == 1? 'a': ' ');
    printf("%c", bcm->b5_2 == 1? 'a': ' ');
    printf("%c", bcm->b5_3 == 1? 'a': ' ');
    printf("%c", bcm->b5_4 == 1? 'a': ' ');
    printf("%c", bcm->b5_5 == 1? 'a': ' ');
    printf("%c", bcm->b5_6 == 1? 'a': ' ');
    printf("%c", bcm->b5_7 == 1? 'a': ' ');
    /*Goto*/
    mt_gotoXY(x + 6, y);
    printf("%c", bcm->b6_0 == 1? 'a': ' ');
    printf("%c", bcm->b6_1 == 1? 'a': ' ');
    printf("%c", bcm->b6_2 == 1? 'a': ' ');
    printf("%c", bcm->b6_3 == 1? 'a': ' ');
    printf("%c", bcm->b6_4 == 1? 'a': ' ');
    printf("%c", bcm->b6_5 == 1? 'a': ' ');
    printf("%c", bcm->b6_6 == 1? 'a': ' ');
    printf("%c", bcm->b6_7 == 1? 'a': ' ');
    /*Goto*/
    mt_gotoXY(x + 7, y);
    printf("%c", bcm->b7_0 == 1? 'a': ' ');
    printf("%c", bcm->b7_1 == 1? 'a': ' ');
    printf("%c", bcm->b7_2 == 1? 'a': ' ');
    printf("%c", bcm->b7_3 == 1? 'a': ' ');
    printf("%c", bcm->b7_4 == 1? 'a': ' ');
    printf("%c", bcm->b7_5 == 1? 'a': ' ');
    printf("%c", bcm->b7_6 == 1? 'a': ' ');
    printf("%c", bcm->b7_7 == 1? 'a': ' ');
    return 0;
}

//set value of the "symbolplace" of the big symbol in row x and col y
int bc_setbigcharpos(int *big, int x, int y, int value) {
    printf("bc_setbigcharpos test\n");
    return 0;
}

//get value of the "symbolplace" of the big symbol in row x and col y
int bc_getbigcharpos(int *big, int x, int y, int *value) {
    printf("bc_getbigcharpos test\n");
    return 0;
}

//Save count of "big-symbols" in the file, format of the file is userdefined
int bc_bigcharwrite(int fd, int* big, int count) {
    printf("bc_bigcharwrite test\n");
    return 0;
}

//Read count of "big-symbols" from the file, count for how many was read, or error
int bc_bigcharread(int fd, int* big, int need_count, int *count) {
    printf("bc_bigcharread test\n");
    return 0;
}

int _bc_setbigcharmatrix_from_strmatrix(const char** str, bigcharmatrix* bcm) {
    if(str == NULL || bcm == NULL) return -1;
    int i, j;
    /*Through strings*/
    for(i = 0; i < 8; i++) {
        /*Through chars of string*/
        for(j = 0; j < 8; j++) {
            switch(i) {
                case 0:
                switch(j) {
                    case 0:
                        bcm->b0_0 = str[i][j] == ' '?0:1;
                    break;
                    case 1:
                        bcm->b0_1 = str[i][j] == ' '?0:1;
                    break;
                    case 2:
                        bcm->b0_2 = str[i][j] == ' '?0:1;
                    break;
                    case 3:
                        bcm->b0_3 = str[i][j] == ' '?0:1;
                    break;
                    case 4:
                        bcm->b0_4 = str[i][j] == ' '?0:1;
                    break;
                    case 5:
                        bcm->b0_5 = str[i][j] == ' '?0:1;
                    break;
                    case 6:
                        bcm->b0_6 = str[i][j] == ' '?0:1;
                    break;
                    case 7:
                        bcm->b0_7 = str[i][j] == ' '?0:1;
                    break;
                }
                break;
                case 1:
                switch(j) {
                    case 0:
                        bcm->b1_0 = str[i][j] == ' '?0:1;
                    break;
                    case 1:
                        bcm->b1_1 = str[i][j] == ' '?0:1;
                    break;
                    case 2:
                        bcm->b1_2 = str[i][j] == ' '?0:1;
                    break;
                    case 3:
                        bcm->b1_3 = str[i][j] == ' '?0:1;
                    break;
                    case 4:
                        bcm->b1_4 = str[i][j] == ' '?0:1;
                    break;
                    case 5:
                        bcm->b1_5 = str[i][j] == ' '?0:1;
                    break;
                    case 6:
                        bcm->b1_6 = str[i][j] == ' '?0:1;
                    break;
                    case 7:
                        bcm->b1_7 = str[i][j] == ' '?0:1;
                    break;
                }
                break;
                case 2:
                switch(j) {
                    case 0:
                        bcm->b2_0 = str[i][j] == ' '?0:1;
                    break;
                    case 1:
                        bcm->b2_1 = str[i][j] == ' '?0:1;
                    break;
                    case 2:
                        bcm->b2_2 = str[i][j] == ' '?0:1;
                    break;
                    case 3:
                        bcm->b2_3 = str[i][j] == ' '?0:1;
                    break;
                    case 4:
                        bcm->b2_4 = str[i][j] == ' '?0:1;
                    break;
                    case 5:
                        bcm->b2_5 = str[i][j] == ' '?0:1;
                    break;
                    case 6:
                        bcm->b2_6 = str[i][j] == ' '?0:1;
                    break;
                    case 7:
                        bcm->b2_7 = str[i][j] == ' '?0:1;
                    break;
                }
                break;
                case 3:
                switch(j) {
                    case 0:
                        bcm->b3_0 = str[i][j] == ' '?0:1;
                    break;
                    case 1:
                        bcm->b3_1 = str[i][j] == ' '?0:1;
                    break;
                    case 2:
                        bcm->b3_2 = str[i][j] == ' '?0:1;
                    break;
                    case 3:
                        bcm->b3_3 = str[i][j] == ' '?0:1;
                    break;
                    case 4:
                        bcm->b3_4 = str[i][j] == ' '?0:1;
                    break;
                    case 5:
                        bcm->b3_5 = str[i][j] == ' '?0:1;
                    break;
                    case 6:
                        bcm->b3_6 = str[i][j] == ' '?0:1;
                    break;
                    case 7:
                        bcm->b3_7 = str[i][j] == ' '?0:1;
                    break;
                }
                break;
                case 4:
                switch(j) {
                    case 0:
                        bcm->b4_0 = str[i][j] == ' '?0:1;
                    break;
                    case 1:
                        bcm->b4_1 = str[i][j] == ' '?0:1;
                    break;
                    case 2:
                        bcm->b4_2 = str[i][j] == ' '?0:1;
                    break;
                    case 3:
                        bcm->b4_3 = str[i][j] == ' '?0:1;
                    break;
                    case 4:
                        bcm->b4_4 = str[i][j] == ' '?0:1;
                    break;
                    case 5:
                        bcm->b4_5 = str[i][j] == ' '?0:1;
                    break;
                    case 6:
                        bcm->b4_6 = str[i][j] == ' '?0:1;
                    break;
                    case 7:
                        bcm->b4_7 = str[i][j] == ' '?0:1;
                    break;
                }
                break;
                case 5:
                switch(j) {
                    case 0:
                        bcm->b5_0 = str[i][j] == ' '?0:1;
                    break;
                    case 1:
                        bcm->b5_1 = str[i][j] == ' '?0:1;
                    break;
                    case 2:
                        bcm->b5_2 = str[i][j] == ' '?0:1;
                    break;
                    case 3:
                        bcm->b5_3 = str[i][j] == ' '?0:1;
                    break;
                    case 4:
                        bcm->b5_4 = str[i][j] == ' '?0:1;
                    break;
                    case 5:
                        bcm->b5_5 = str[i][j] == ' '?0:1;
                    break;
                    case 6:
                        bcm->b5_6 = str[i][j] == ' '?0:1;
                    break;
                    case 7:
                        bcm->b5_7 = str[i][j] == ' '?0:1;
                    break;
                }
                break;
                case 6:
                switch(j) {
                    case 0:
                        bcm->b6_0 = str[i][j] == ' '?0:1;
                    break;
                    case 1:
                        bcm->b6_1 = str[i][j] == ' '?0:1;
                    break;
                    case 2:
                        bcm->b6_2 = str[i][j] == ' '?0:1;
                    break;
                    case 3:
                        bcm->b6_3 = str[i][j] == ' '?0:1;
                    break;
                    case 4:
                        bcm->b6_4 = str[i][j] == ' '?0:1;
                    break;
                    case 5:
                        bcm->b6_5 = str[i][j] == ' '?0:1;
                    break;
                    case 6:
                        bcm->b6_6 = str[i][j] == ' '?0:1;
                    break;
                    case 7:
                        bcm->b6_7 = str[i][j] == ' '?0:1;
                    break;
                }
                break;
                case 7:
                switch(j) {
                    case 0:
                        bcm->b7_0 = str[i][j] == ' '?0:1;
                    break;
                    case 1:
                        bcm->b7_1 = str[i][j] == ' '?0:1;
                    break;
                    case 2:
                        bcm->b7_2 = str[i][j] == ' '?0:1;
                    break;
                    case 3:
                        bcm->b7_3 = str[i][j] == ' '?0:1;
                    break;
                    case 4:
                        bcm->b7_4 = str[i][j] == ' '?0:1;
                    break;
                    case 5:
                        bcm->b7_5 = str[i][j] == ' '?0:1;
                    break;
                    case 6:
                        bcm->b7_6 = str[i][j] == ' '?0:1;
                    break;
                    case 7:
                        bcm->b7_7 = str[i][j] == ' '?0:1;
                    break;
                }
                break;
            }
        }
    }
    return 0;
}

int _bc_getbigcharmatrix_as_int_array_by_number(int number, int bcm[2]) {
    if(number < 0 || number > 9) return -1;
    if(bcm == NULL) return -1;
    switch(number) {
        case 0:
            _bc_setbigcharmatrix_from_strmatrix(bigchar_0, (bigcharmatrix*)bcm);
        break;
        case 1:
            _bc_setbigcharmatrix_from_strmatrix(bigchar_1, (bigcharmatrix*)bcm);
        break;
        case 2:
            _bc_setbigcharmatrix_from_strmatrix(bigchar_2, (bigcharmatrix*)bcm);
        break;
        case 3:
            _bc_setbigcharmatrix_from_strmatrix(bigchar_3, (bigcharmatrix*)bcm);
        break;
        case 4:
            _bc_setbigcharmatrix_from_strmatrix(bigchar_4, (bigcharmatrix*)bcm);
        break;
        case 5:
            _bc_setbigcharmatrix_from_strmatrix(bigchar_5, (bigcharmatrix*)bcm);
        break;
        case 6:
            _bc_setbigcharmatrix_from_strmatrix(bigchar_6, (bigcharmatrix*)bcm);
        break;
        case 7:
            _bc_setbigcharmatrix_from_strmatrix(bigchar_7, (bigcharmatrix*)bcm);
        break;
        case 8:
            _bc_setbigcharmatrix_from_strmatrix(bigchar_8, (bigcharmatrix*)bcm);
        break;
        case 9:
            _bc_setbigcharmatrix_from_strmatrix(bigchar_9, (bigcharmatrix*)bcm);
        break;
    }
    return 0;
}

//all return 0 if success or -1 if failed


