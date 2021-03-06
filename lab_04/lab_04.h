#ifndef _LAB_04_

#define _LAB_04_

#include "../lab_03/lab_03.h"

#define MAX_STR_LENGTH 4096
#define ALT_CHARSET_ON  "\E(0"
#define ALT_CHARSET_OFF "\E(B"

/*Matrixes of numbrs*/
extern const char* bigchar_0[8];
extern const char* bigchar_1[8];
extern const char* bigchar_2[8];
extern const char* bigchar_3[8];
extern const char* bigchar_4[8];
extern const char* bigchar_5[8];
extern const char* bigchar_6[8];
extern const char* bigchar_7[8];
extern const char* bigchar_8[8];
extern const char* bigchar_9[8];
extern const char* bigchar_plus[8];
extern const char* bigchar_empty[8];

/*Bit fields for bigchar representation*/
typedef struct bigcharmatrix {
    /*First byte*/
    unsigned int b0_0 : 1;
    unsigned int b0_1 : 1;
    unsigned int b0_2 : 1;
    unsigned int b0_3 : 1;
    unsigned int b0_4 : 1;
    unsigned int b0_5 : 1;
    unsigned int b0_6 : 1;
    unsigned int b0_7 : 1;
    /*Next byte*/
    unsigned int b1_0 : 1;
    unsigned int b1_1 : 1;
    unsigned int b1_2 : 1;
    unsigned int b1_3 : 1;
    unsigned int b1_4 : 1;
    unsigned int b1_5 : 1;
    unsigned int b1_6 : 1;
    unsigned int b1_7 : 1;
    /*Next byte*/
    unsigned int b2_0 : 1;
    unsigned int b2_1 : 1;
    unsigned int b2_2 : 1;
    unsigned int b2_3 : 1;
    unsigned int b2_4 : 1;
    unsigned int b2_5 : 1;
    unsigned int b2_6 : 1;
    unsigned int b2_7 : 1;
    /*Next byte*/
    unsigned int b3_0 : 1;
    unsigned int b3_1 : 1;
    unsigned int b3_2 : 1;
    unsigned int b3_3 : 1;
    unsigned int b3_4 : 1;
    unsigned int b3_5 : 1;
    unsigned int b3_6 : 1;
    unsigned int b3_7 : 1;
    /*Next byte*/
    unsigned int b4_0 : 1;
    unsigned int b4_1 : 1;
    unsigned int b4_2 : 1;
    unsigned int b4_3 : 1;
    unsigned int b4_4 : 1;
    unsigned int b4_5 : 1;
    unsigned int b4_6 : 1;
    unsigned int b4_7 : 1;
    /*Next byte*/
    unsigned int b5_0 : 1;
    unsigned int b5_1 : 1;
    unsigned int b5_2 : 1;
    unsigned int b5_3 : 1;
    unsigned int b5_4 : 1;
    unsigned int b5_5 : 1;
    unsigned int b5_6 : 1;
    unsigned int b5_7 : 1;
    /*Next byte*/
    unsigned int b6_0 : 1;
    unsigned int b6_1 : 1;
    unsigned int b6_2 : 1;
    unsigned int b6_3 : 1;
    unsigned int b6_4 : 1;
    unsigned int b6_5 : 1;
    unsigned int b6_6 : 1;
    unsigned int b6_7 : 1;
    /*Next byte*/
    unsigned int b7_0 : 1;
    unsigned int b7_1 : 1;
    unsigned int b7_2 : 1;
    unsigned int b7_3 : 1;
    unsigned int b7_4 : 1;
    unsigned int b7_5 : 1;
    unsigned int b7_6 : 1;
    unsigned int b7_7 : 1;
} bigcharmatrix;

int _bc_setbigcharmatrix_from_strmatrix(const char** str, bigcharmatrix* bcm);

int _bc_getbigcharmatrix_as_int_array_by_number(int number, int int_order_bcm[2]);

int _bc_getbigcharmatrix_as_int_array_by_char(char symbol, int int_order_bcm[2]);

int _bc_bigcharmatrix_from_int_order(const int int_order_bcm[2], bigcharmatrix* bcm);

int _bc_int_order_from_bigcharmatrix(const bigcharmatrix* bcm, int int_order_bcm[2]);

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
