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
    printf("test_bc_setbigcharpos function case 1:\n");
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
        printf("Try add [1] at row:%d col:%d in bigchar\n", 7-i, i);
        ret_value = bc_setbigcharpos(bigchar, 7-i, i, 1);
        printf("return value is:%d\n", ret_value);
        bc_printbigchar(bigchar, 3, 1, FG_BLACK, BG_BLUE);
        printf("\n");
        mt_setfgcolor(FG_LIGHT_GRAY);
        mt_setbgcolor(BG_BLACK);
        sleep(2);
    }
    
    mt_clrscr();
    printf("test_bc_setbigcharpos function case 2:\n");
    sleep(4);
    memset(bigchar, 0xFF, sizeof(int)*2);
    
    for(i = 0; i < 9; i++) {
        mt_clrscr();
        printf("Try add [0] at row:%d col:%d in bigchar\n", i, i);
        ret_value = bc_setbigcharpos(bigchar, i, i, 0);
        printf("return value is:%d\n", ret_value);
        bc_printbigchar(bigchar, 3, 1, FG_BLACK, BG_BLUE);
        printf("\n");
        mt_setfgcolor(FG_LIGHT_GRAY);
        mt_setbgcolor(BG_BLACK);
        sleep(2);
        mt_clrscr();
        printf("Try add [0] at row:%d col:%d in bigchar\n", 7-i, i);
        ret_value = bc_setbigcharpos(bigchar, 7-i, i, 0);
        printf("return value is:%d\n", ret_value);
        bc_printbigchar(bigchar, 3, 1, FG_BLACK, BG_BLUE);
        printf("\n");
        mt_setfgcolor(FG_LIGHT_GRAY);
        mt_setbgcolor(BG_BLACK);
        sleep(2);
    }
    
    mt_clrscr();
    printf("test_bc_setbigcharpos function case 3:\n");
    printf("try to use NULL as pointer to big char\n");
    printf("Try add [1] at row:%d col:%d in bigchar\n", 1, 1);
    ret_value = bc_setbigcharpos(NULL, 1, 1, 1);
    printf("return value is:%d\n", ret_value);
    sleep(4);
    return 0;
}

int test_bc_getbigcharpos(void) {
    mt_clrscr();
    printf("test bc_getbigcharpos function case 1:\n");

    int bigchar[2];
    _bc_getbigcharmatrix_as_int_array_by_number(2, bigchar);
    bc_printbigchar(bigchar, 2, 1, FG_BLACK, BG_LIGHT_GREEN);
    printf("\n");
    mt_setfgcolor(FG_LIGHT_GRAY);
    mt_setbgcolor(BG_BLACK);
    
    int ret_value;
    int value;
    int i, j;
    for(i = 0; i < 9; i++) {
        for(j = 0; j < 9; j++) {
            ret_value = bc_getbigcharpos(bigchar, i, j, &value);
            mt_gotoXY(10, 1);
            printf("Try to get at row:%d, col:%d\n", i, j);
            printf("Return value (0 is success, -1 is error):%2d\n", ret_value);
            printf("Value (what in matrix in this pos):%d\n", value);
            sleep(1);
        }
    }
    
    mt_clrscr();
    printf("test bc_getbigcharpos function case 2:\n");
    printf("Try to use NULL instead pointer to value\n");
    ret_value = bc_getbigcharpos(bigchar, 1, 1, NULL);
    printf("Try to get at row:%d, col:%d\n", 1, 1);
    printf("Return value (0 is success, -1 is error):%d\n", ret_value);
    sleep(4);
    
    mt_clrscr();
    printf("test bc_getbigcharpos function case 3:\n");
    printf("Try to use NULL instead pointer to bigchar\n");
    ret_value = bc_getbigcharpos(NULL, 1, 1, &value);
    printf("Try to get at row:%d, col:%d\n", 1, 1);
    printf("Return value (0 is success, -1 is error):%d\n", ret_value);
    sleep(4);
    return 0;
}

int test_bc_bigcharwrite(void)  {
    mt_clrscr();
    printf("test bc_bigcharwrite function case 1:\n");
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
    printf("Try to write 10 big digits (0123456789) into file:%s\n", "big_digits.bin");
    int ret_value;
    ret_value = bc_bigcharwrite(test_fd, big_digits, count);
    printf("Return value:%d\n", ret_value);
    close(test_fd);
    
    printf("Test to read from file, to make sure that all was wrote right\n");
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
        bc_printbigchar(&big_digits_read[i*2], 5, 1, FG_BLACK, BG_LIGHT_BLUE);
        printf("\n");
        sleep(2);
    }
    mt_setbgcolor(BG_BLACK);
    mt_setfgcolor(FG_LIGHT_GRAY);
    
    mt_clrscr();
    printf("test bc_bigcharwrite function case 2:\n");
    printf("Try to write 10 big digits (0123456789) into file:%s\n", "big_digits.bin");
    printf("But not have the correct file descriptor now\n");
    ret_value = bc_bigcharwrite(-1, big_digits, count);
    printf("Return value:%d\n", ret_value);
    sleep(5);
    
    mt_clrscr();
    printf("test bc_bigcharwrite function case 3:\n");
    test_fd = open("big_digits.bin", O_CREAT|O_WRONLY, 0666);
    if(test_fd < 0) {
        perror("open to write in main failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Try to write 10 big digits (0123456789) into file:%s\n", "big_digits.bin");
    printf("But have zero count of records which need to write\n");
    ret_value = bc_bigcharwrite(test_fd, big_digits, 0);
    printf("Return value:%d\n", ret_value);
    close(test_fd);
    sleep(5);
    
    mt_clrscr();
    printf("test bc_bigcharwrite function case 4:\n");
    test_fd = open("big_digits.bin", O_CREAT|O_WRONLY, 0666);
    if(test_fd < 0) {
        perror("open to write in main failed\n");
        exit(EXIT_FAILURE);
    }
    printf("Try to write 10 big digits (0123456789) into file:%s\n", "big_digits.bin");
    printf("But by mistake send NULL istead poiter to array fo big digits\n");
    ret_value = bc_bigcharwrite(test_fd, NULL, count);
    printf("Return value:%d\n", ret_value);
    close(test_fd);
    sleep(5);
    return 0;
}

int test_bc_bigcharread(void) {
    mt_clrscr();
    printf("test bc_bigcharread function case 1:\n");
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
    
    printf("10 digits were written into the file: big_digits.bin\n");
    //bc_bigcharread
    int big_digits_read[10*2];
    test_fd = open("big_digits.bin", O_RDONLY);
    if(test_fd < 0) {
        perror("open to read in main failed\n");
        exit(EXIT_FAILURE);
    }
    int ret_value;
    int was_read;
    int need_read = 10;
    printf("Now try to read all 10 digits from this file\n");
    ret_value = bc_bigcharread(test_fd, big_digits_read, need_read, &was_read);
    printf("Return value is: %d. arg number 4 after calling is: %d\n", ret_value, was_read);
    printf("Show what was read:\n");
    close(test_fd);
    
    /*Test output*/
    int i;
    for(i = 0; i < was_read; i++) {
        ret_value = bc_printbigchar(&big_digits_read[i*2], 6, 1, FG_BLACK, BG_LIGHT_RED);
        printf("\n");
        sleep(2);
    }
    sleep(4);
    mt_setbgcolor(BG_BLACK);
    mt_setfgcolor(FG_LIGHT_GRAY);
    
    mt_clrscr();
    printf("test bc_bigcharread function case 2:\n");
    printf("10 digits were written into the file: big_digits.bin\n");
    //bc_bigcharread
    test_fd = open("big_digits.bin", O_RDONLY);
    if(test_fd < 0) {
        perror("open to read in main failed\n");
        exit(EXIT_FAILURE);
    }
    need_read = 1;
    printf("Now try to read just 1 digits from this file\n");
    ret_value = bc_bigcharread(test_fd, big_digits_read, need_read, &was_read);
    close(test_fd);
    printf("Return value is: %d. arg number 4 after calling is: %d\n", ret_value, was_read);
    printf("Show what was read:\n");
    
    /*Test output*/
    i;
    for(i = 0; i < was_read; i++) {
        ret_value = bc_printbigchar(&big_digits_read[i*2], 6, 1, FG_BLACK, BG_LIGHT_GREEN);
        printf("\n");
        sleep(2);
    }
    sleep(4);
    mt_setbgcolor(BG_BLACK);
    mt_setfgcolor(FG_LIGHT_GRAY);
    
    mt_clrscr();
    printf("test bc_bigcharread function case 3:\n");
    printf("10 digits were written into the file: big_digits.bin\n");
    //bc_bigcharread
    test_fd = open("big_digits.bin", O_RDONLY);
    if(test_fd < 0) {
        perror("open to read in main failed\n");
        exit(EXIT_FAILURE);
    }
    was_read = 0;
    need_read = 0;
    printf("Now try to read 0 digits from this file\n");
    ret_value = bc_bigcharread(test_fd, big_digits_read, need_read, &was_read);
    close(test_fd);
    printf("Return value is: %d. Error, nothing was read\n", ret_value);
    sleep(4);
    //printf("Show what was read:\n");
    
    /*Test output*/
    /*
    for(i = 0; i < was_read; i++) {
        ret_value = bc_printbigchar(&big_digits_read[i*2], 6, 1, FG_BLACK, BG_LIGHT_BLUE);
        printf("\n");
        sleep(2);
    }
    sleep(4);
    mt_setbgcolor(BG_BLACK);
    mt_setfgcolor(FG_LIGHT_GRAY);
    */
    
    mt_clrscr();
    printf("test bc_bigcharread function case 4:\n");
    printf("10 digits were written into the file: big_digits.bin\n");
    //bc_bigcharread
    test_fd = open("big_digits.bin", O_RDONLY);
    if(test_fd < 0) {
        perror("open to read in main failed\n");
        exit(EXIT_FAILURE);
    }
    was_read = 0;
    need_read = 12;
    printf("Now try to read %d digits from this file\n", need_read);
    ret_value = bc_bigcharread(test_fd, big_digits_read, need_read, &was_read);
    close(test_fd);
    printf("Return value is: %d. was read: %d\n", ret_value, was_read);
    printf("Show what was read:\n");
    
    /*Test output*/
    i;
    for(i = 0; i < was_read; i++) {
        bc_printbigchar(&big_digits_read[i*2], 6, 1, FG_BLACK, BG_LIGHT_GREEN);
        printf("\n");
        sleep(2);
    }
    mt_setbgcolor(BG_BLACK);
    mt_setfgcolor(FG_LIGHT_GRAY);
    sleep(4);
    
    
    return 0;
}

int main() {
    test_bc_printA();
    test_bc_box();
    test_bc_printbigchar();
    test_bc_setbigcharpos();
    test_bc_getbigcharpos();
    test_bc_bigcharwrite();
    test_bc_bigcharread();
    return 0;
}
