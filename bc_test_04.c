#include <stdio.h>
#include <string.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include "lab_04/myBigChars.h"

int test_bc_printA(void) {
    
    char *to_print = "TEST STRING: test string";
    int ret_value;
    
    mt_clrscr();
    printf("Test bc_printA function\n");
    printf("Case 1: Input is not NULL\n");
    printf("Input string:%s\n", to_print);
    printf("It looks like:");
    ret_value = bc_printA(to_print);
    printf("\n");
    printf("And has return value:%d\n", ret_value);
    sleep(10);
    mt_clrscr();
    printf("Test bc_printA function\n");
    printf("Case 2: Input is NULL\n");
    printf("It looks like:");
    ret_value = bc_printA(NULL);
    printf("\n");
    printf("And has return value:%d\n", ret_value);
    sleep(10);
    return 0;
}

int test_bc_box(void) {
    int ret_value;
    int row, col;
    int height, width;
    
    /*Minimal size:*/
    mt_clrscr();
    mt_gotoXY(1,1);
    printf("Now test bc_box with minimal size: 1,1,2,2\n");
    printf("After 5 second here will be the 2 char side square\n");
    sleep(5);
    ret_value = bc_box(1,1,2,2);
    printf("\nReturn value of bc_box:%d\n", ret_value);
    sleep(5);
    
    /*Test size with less width than it can be*/
    mt_clrscr();
    mt_gotoXY(1,1);
    printf("Now test bc_box with incorrect size: 1,1,2,1\n");
    sleep(5);
    ret_value = bc_box(1,1,2,1);
    printf("\nReturn value of bc_box:%d\n", ret_value);
    sleep(5);
    
    /*Max size*/
    mt_clrscr();
    mt_gotoXY(1,1);
    mt_getscreensize(&height, &width);
    printf("Now test bc_box with max size: 1,1,%d,%d\n", height, width);
    printf("After 5 second here will be box\n");
    sleep(5);
    ret_value = bc_box(1,1,height, width);
    mt_gotoXY(2,2);
    printf("Return value of bc_box:%d               \n", ret_value);
    sleep(5);
    
    /*Test size with more width than it can be*/
    mt_clrscr();
    mt_gotoXY(1,1);
    mt_getscreensize(&height, &width);
    printf("Now test bc_box with incorrect size: 1,1,%d,%d\n", height, width + 1);
    sleep(5);
    ret_value = bc_box(1,1,height,width + 1);
    printf("\nReturn value of bc_box:%d\n", ret_value);
    sleep(5);
    
    return 0;
}

int test_bc_printbigchar(void) {
    int bigchar[2];
    int ret_value;
    int posX, posY;
    int i;
    
    memset(&bigchar, 0, sizeof(int)*2);
    
    mt_clrscr();
    printf("Now test printing of bigchars:\n");
    for(i = 0; i < 10; i++) {
        _bc_getbigcharmatrix_as_int_array_by_number(i, bigchar);
        posX = 2, posY = 1 + i*8;
        ret_value = bc_printbigchar(bigchar, posX, posY, FG_BLACK, BG_BLACK+i%7+1);
        mt_setfgcolor(FG_LIGHT_GRAY);
        mt_setbgcolor(BG_BLACK);
        printf("\nposition was row:%d col:%d\n", posX, posY);
        printf("colors was fg:%d bg:%d\n", FG_BLACK, BG_BLACK+i%7+1);
        printf("return value:%d\n", ret_value);
        sleep(2);
    }
    
    int height, width;
    mt_getscreensize(&height, &width);
    mt_clrscr();
    printf("Now screen, row:%d, col:%d\n", height, width);
    printf("Try to print big char out of screen\n");
    _bc_getbigcharmatrix_as_int_array_by_number(0, bigchar);
    posX = 3, posY = width - 8 + 1;
    ret_value = bc_printbigchar(bigchar, posX, posY, FG_BLACK, BG_BLACK+1);
    mt_setfgcolor(FG_LIGHT_GRAY);
    mt_setbgcolor(BG_BLACK);
    printf("\nposition was row:%d col:%d\n", posX, posY);
    printf("colors was fg:%d bg:%d\n", FG_BLACK, BG_BLACK+1);
    printf("return value:%d\n", ret_value);
    sleep(5);
    
    mt_clrscr();
    printf("Try to print big char with NULL pointer\n");
    posX = 2, posY = 1;
    ret_value = bc_printbigchar(NULL, posX, posY, FG_BLACK, BG_BLACK+1);
    mt_setfgcolor(FG_LIGHT_GRAY);
    mt_setbgcolor(BG_BLACK);
    printf("\nposition was row:%d col:%d\n", posX, posY);
    printf("colors was fg:%d bg:%d\n", FG_BLACK, BG_BLACK+1);
    printf("return value:%d\n", ret_value);
    sleep(5);
    
    mt_clrscr();
    printf("Try to print big char with wrong colors\n");
    posX = 2, posY = 1;
    _bc_getbigcharmatrix_as_int_array_by_number(0, bigchar);
    ret_value = bc_printbigchar(bigchar, posX, posY, BG_BLACK, FG_BLACK+1);
    mt_setfgcolor(FG_LIGHT_GRAY);
    mt_setbgcolor(BG_BLACK);
    printf("\nposition was row:%d col:%d\n", posX, posY);
    printf("colors was fg:%d bg:%d\n", BG_BLACK, FG_BLACK+1);
    printf("return value:%d\n", ret_value);
    sleep(5);
    
    return 0;
}

int test_bc_setbigcharpos(void) {
    mt_clrscr();
    printf("test_bc_setbigcharpos function:\n");
    sleep(4);
    int ret_value;
    int bigchar[2];
    memset(bigchar, 0, sizeof(int)*2);
    
    int i;
    for(i = 0; i < 9; i++) {
        mt_clrscr();
        printf("Try add [1] at row:%d col:%d in bigchar\n", i, i);
        ret_value = bc_setbigcharpos(bigchar, i, i, 1);
        printf("return value is:%d\n", ret_value);
        bc_printbigchar(bigchar, 3, 1, FG_BLACK, BG_BLUE);
        printf("\n");
        mt_setfgcolor(FG_LIGHT_GRAY);
        mt_setbgcolor(BG_BLACK);
        sleep(2);
        mt_clrscr();
        printf("Try add 1 at row:%d col:%d in bigchar\n", 7-i, i);
        ret_value = bc_setbigcharpos(bigchar, 7-i, i, 1);
        printf("return value is:%d\n", ret_value);
        bc_printbigchar(bigchar, 3, 1, FG_BLACK, BG_BLUE);
        printf("\n");
        mt_setfgcolor(FG_LIGHT_GRAY);
        mt_setbgcolor(BG_BLACK);
        sleep(2);
    }
    return 0;
}

int test_bc_getbigcharpos(void) {
    int ret_value;
    int bigchar[2];
    int value;
    int i, j;
    for(i = 0; i < 8; i++) {
        for(j = 0; j < 8; j++) {
            bc_getbigcharpos(bigchar, i, j, &value);
            if(value != 0) {
                printf("(%d, %d)\n", i, j);
            }
        }
    }
    bc_printbigchar(bigchar, 1, 1, FG_WHITE, BG_BLACK);
    return 0;
}

int test_bc_bigcharwrite(void)  {
    return 0;
}

int test_bc_bigcharread(void) {
    return 0;
}

int main() {
    //test_bc_printA();
    //test_bc_box();
    //test_bc_printbigchar();
    test_bc_setbigcharpos();
    //test_bc_getbigcharpos();
    //test_bc_bigcharwrite();
    //test_bc_bigcharread();
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
    //bc_getbigcharpos
    //int i;
    //for(i = 0; i < 8; i++) {
        //bc_setbigcharpos(bigchar, i, i, 1);
        //bc_setbigcharpos(bigchar, 7-i, i, 1);
    //}
    //int value;
    //int j;
    //for(i = 0; i < 8; i++) {
        //for(j = 0; j < 8; j++) {
            //bc_getbigcharpos(bigchar, i, j, &value);
            //if(value != 0) {
                //printf("(%d, %d)\n", i, j);
            //}
        //}
    //}
    //bc_printbigchar(bigchar, 1, 1, FG_WHITE, BG_BLACK);
    int big_digits[10*2];
    /*Fill big_digits by the digit-matrixes*/
    _bc_getbigcharmatrix_as_int_array_by_number(0, &big_digits[0*2]);
    _bc_getbigcharmatrix_as_int_array_by_number(1, &big_digits[1*2]);
    _bc_getbigcharmatrix_as_int_array_by_number(2, &big_digits[2*2]);
    _bc_getbigcharmatrix_as_int_array_by_number(3, &big_digits[3*2]);
    _bc_getbigcharmatrix_as_int_array_by_number(4, &big_digits[4*2]);
    _bc_getbigcharmatrix_as_int_array_by_number(5, &big_digits[5*2]);
    _bc_getbigcharmatrix_as_int_array_by_number(6, &big_digits[6*2]);
    _bc_getbigcharmatrix_as_int_array_by_number(7, &big_digits[7*2]);
    _bc_getbigcharmatrix_as_int_array_by_number(8, &big_digits[8*2]);
    _bc_getbigcharmatrix_as_int_array_by_number(9, &big_digits[9*2]);
    int count = 10;
    int test_fd = open("big_digits.bin", O_CREAT|O_WRONLY, 0666);
    if(test_fd < 0) {
        perror("open to write in main failed\n");
        exit(EXIT_FAILURE);
    }
    bc_bigcharwrite(test_fd, big_digits, count);
    close(test_fd);
    
    //bc_bigcharread
    int big_digits_read[10*2];
    test_fd = open("big_digits.bin", O_RDONLY);
    if(test_fd < 0) {
        perror("open to read in main failed\n");
        exit(EXIT_FAILURE);
    }
    int was_read;
    int need_read = 10;
    bc_bigcharread(test_fd, big_digits_read, need_read, &was_read);
    close(test_fd);
    
    /*Test output*/
    int i;
    for(i = 0; i < 10; i++) {
        bc_printbigchar(&big_digits_read[i*2], 1, 1, FG_WHITE, BG_BLUE);
        sleep(2);
    }
    
    return 0;
}
