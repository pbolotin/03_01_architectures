#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "lab_02/lab_02.h"
#include "lab_03/myTerm.h"
#include "lab_04/myBigChars.h"

int initialize(void) {
    sc_memoryInit();
    mt_clrscr();
    return 0;
}

int finalize(void) {
    return 0;
}

int output_memory(int rowY, int colX) {
    int i;
    int memValue = 0;
    int decCommand = 0;
    int decOperand = 0;
    int ret = 0;
    char show[6] = {0,0,0,0,0,0};
    int current_row = 0;
    bc_box(1,1,12,62);
    mt_gotoXY(1,31);
    printf(" Memory ");
    for(i = 0; i < SC_MEMORY_SIZE; i++) {
        sc_memoryGet(i, &memValue);
        ret = sc_commandDecode(memValue, &decCommand, &decOperand);
        /*Error handling*/
        if(ret < 0) {
            switch(sc_errno) {
                case EPLACE:
                    fprintf(stderr, "ouput_memory sc_commandDecode\
                               NULL as place where to put result?\n");
                    exit(EXIT_FAILURE);
                break;
                case ECOMMANDBIT:
                    //fprintf(stderr, "ouput_memory sc_commandDecode\
                                    value not a command!\n");
                    sprintf(show, "%c%04x", ' ', memValue);
                break;
                case EWRONGCOMMAND:
                    //fprintf(stderr, "ouput_memory sc_commandDecode\
                                    unknown command!\n");
                    sprintf(show, "%c%04x", '+', decCommand + decOperand);
                break;
            }
        /*If decode was ok*/
        } else {
            sprintf(show, "%c%04x", '+', decCommand + decOperand);
        }
        if(i%10 == 0) {
            mt_gotoXY(rowY + current_row, colX);
            current_row++;
        }
        printf(" %s", show);
    }
    return 0;
}

int output_reg_flags(int rowY, int colX) {
    char show[] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',0};
    if(sc_reg_flags & FLAG_OPERATION_OVERFLOW) show[0] = 'O';
    if(sc_reg_flags & FLAG_ZERO_DIVIDITION) show[2] = 'Z';
    if(sc_reg_flags & FLAG_MEM_ADDR_ERROR) show[4] = 'M';
    if(sc_reg_flags & FLAG_IGNORE_IMPULESES) show[6] = 'I';
    if(sc_reg_flags & FLAG_WRONG_COMMAND) show[8] = 'C';

    bc_box(10,63,3,22);
    mt_gotoXY(10,69);
    printf(" Flags ");
    mt_gotoXY(rowY,colX);    
    printf("%s", show);
    
    return 0;
}

int output_operation(int rowY, int colX) {
    bc_box(rowY, colX, 3, 22);
    mt_gotoXY(rowY, colX + 5);
    printf(" Operation ");
    return 0;
}

int output_reg_command_counter(int rowY, int colX) {
    char show[6] = {0,0,0,0,0,0};

    bc_box(4,63,3,22);
    mt_gotoXY(4,64);
    printf(" instructionCounter ");
    sprintf(show, "%c%04x", '+', sc_reg_command_counter);
    mt_gotoXY(rowY, colX);
    printf(" %s", show);
    
    return 0;
}

int output_reg_accumulator(int rowY, int colX) {
    int ret;
    int decCommand, decOperand;
    char show[6] = {0,0,0,0,0,0};
    ret = sc_commandDecode(sc_reg_accumulator, &decCommand, &decOperand);
    /*Error handling*/
    if(ret < 0) {
        switch(sc_errno) {
            case EPLACE:
                fprintf(stderr, "ouput_reg_accumulator sc_commandDecode\
                           NULL as place where to put result?\n");
                exit(EXIT_FAILURE);
            break;
            case ECOMMANDBIT:
                //fprintf(stderr, "ouput_reg_accumulator sc_commandDecode\
                                value not a command!\n");
                sprintf(show, "%c%04x", ' ', sc_reg_accumulator);
            break;
            case EWRONGCOMMAND:
                //fprintf(stderr, "ouput_reg_accumulator sc_commandDecode\
                                unknown command!\n");
                sprintf(show, "%c%04x", '+', decCommand + decOperand);
            break;
        }
    /*If decode was ok*/
    } else {
        sprintf(show, "%c%04x", '+', decCommand + decOperand);
    }

    bc_box(1,63,3,22);
    mt_gotoXY(1,67);
    printf(" accumulator ");
    mt_gotoXY(rowY, colX);
    printf(" %s", show);
    
    return 0;
}

int output_keys_meaning(int rowY, int colX) {
    char *show[] = {
        "l  - load",
        "s  - save",
        "r  - run",
        "t  - step",
        "i  - reset",
        "F5 - accumulator",
        "F6 - instructionCounter"
    };
    
    int i;
    bc_box(13,48,10,37);
    mt_gotoXY(13,50);
    printf(" Keys: ");
    for(i = 0; i < 7; i++) {
        mt_gotoXY(rowY + i, colX);
        printf("%s", show[i]);
    }
    return 0;
}

int output_memory_cell(int rowY, int colX) {
    
    int memValue;
    sc_memoryGet(sc_reg_command_counter, &memValue);
    
    int decCommand;
    int decOperand;
    int ret;
    char show[] = {0,0,0,0,0,0,0};
    ret = sc_commandDecode(memValue, &decCommand, &decOperand);
    /*Error handling*/
    if(ret < 0) {
        switch(sc_errno) {
            case EPLACE:
                fprintf(stderr, "ouput_memory sc_commandDecode\
                           NULL as place where to put result?\n");
                exit(EXIT_FAILURE);
            break;
            case ECOMMANDBIT:
                //fprintf(stderr, "ouput_memory sc_commandDecode\
                                value not a command!\n");
                sprintf(show, "%c%04x", ' ', memValue);
            break;
            case EWRONGCOMMAND:
                //fprintf(stderr, "ouput_memory sc_commandDecode\
                                unknown command!\n");
                sprintf(show, "%c%04x", '+', decCommand + decOperand);
            break;
        }
    /*If decode was ok*/
    } else {
        sprintf(show, "%c%04x", '+', decCommand + decOperand);
    }
    int i;
    int bigchar[2];
    for(i = 0; i < 5; i++) {
        _bc_getbigcharmatrix_as_int_array_by_char(show[i], bigchar);
        bc_printbigchar(bigchar, rowY + 1, colX + 1 + i*9, FG_WHITE, BG_BLACK);
    }
    mt_setbgcolor(BG_BLACK);
    mt_setfgcolor(FG_LIGHT_GRAY);
    bc_box(rowY,colX, 10, 47);
    return 0;
}

int main(void) {
    initialize();
    int value = 0;
    sc_commandEncode(OP_01_READ, 99, &value);
    sc_memorySet(10, value);
    sc_commandEncode(OP_01_READ, 99, &value);
    sc_memorySet(0, value);
    sc_regSet(FLAG_OPERATION_OVERFLOW, 1);
    sc_regSet(FLAG_ZERO_DIVIDITION, 1);
    sc_regSet(FLAG_MEM_ADDR_ERROR, 1);
    sc_regSet(FLAG_IGNORE_IMPULESES, 1);
    sc_regSet(FLAG_WRONG_COMMAND, 1);
    output_reg_flags(11, 70);
    output_operation(7, 63);
    output_reg_command_counter(5, 70);
    output_reg_accumulator(2, 70);
    output_memory(2, 2);
    output_keys_meaning(14, 49);
    output_memory_cell(13, 1);
    printf("\n");
    finalize();
    return 0;
}
