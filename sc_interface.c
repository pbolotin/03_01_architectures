#include <stdio.h>
#include <stdlib.h>
#include "lab_02/lab_02.h"
#include "lab_03/myTerm.h"

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
    //cursor_address=\E[%i%p1%d;%p2%dH
    char cursormoveto[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
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
            //cursor_address=\E[%i%p1%d;%p2%dH
            sprintf(cursormoveto, "\E[%d;%dH", rowY + current_row, colX);
            printf("%s", cursormoveto);
            current_row++;
        }
        printf(" %s", show);
    }
    return 0;
}


int output_reg_flags(int rowY, int colX) {
    char show[] = {' ',' ',' ',' ',' ',' ',' ',' ',' ',0};
    char cursormoveto[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    if(sc_reg_flags & FLAG_OPERATION_OVERFLOW) show[0] = 'O';
    if(sc_reg_flags & FLAG_ZERO_DIVIDITION) show[2] = 'Z';
    if(sc_reg_flags & FLAG_MEM_ADDR_ERROR) show[4] = 'M';
    if(sc_reg_flags & FLAG_IGNORE_IMPULESES) show[6] = 'I';
    if(sc_reg_flags & FLAG_WRONG_COMMAND) show[8] = 'C';

    //cursor_address=\E[%i%p1%d;%p2%dH
    sprintf(cursormoveto, "\E[%d;%dH", rowY, colX);
    printf("%s", cursormoveto);
    printf("%s", show);
    
    return 0;
}

int output_reg_command_counter(int rowY, int colX) {
    char show[6] = {0,0,0,0,0,0};
    char cursormoveto[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};

    sprintf(show, "%c%04x", '+', sc_reg_command_counter);

    //cursor_address=\E[%i%p1%d;%p2%dH
    sprintf(cursormoveto, "\E[%d;%dH", rowY, colX);
    printf("%s", cursormoveto);
    printf(" %s", show);
    
    return 0;
}

int output_reg_accumulator(int rowY, int colX) {
    int ret;
    int decCommand, decOperand;
    char show[6] = {0,0,0,0,0,0};
    char cursormoveto[] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
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

    //cursor_address=\E[%i%p1%d;%p2%dH
    sprintf(cursormoveto, "\E[%d;%dH", rowY, colX);
    printf("%s", cursormoveto);
    printf(" %s", show);
    
    return 0;
}

int output_keys_meaning(void) {
    return 0;
}

int main(void) {
    initialize();
    int value = 0;
    sc_commandEncode(OP_01_READ, 99, &value);
    sc_memorySet(10, value);
/*
FLAG_OPERATION_OVERFLOW
FLAG_ZERO_DIVIDITION
FLAG_MEM_ADDR_ERROR
FLAG_IGNORE_IMPULESES
FLAG_WRONG_COMMAND
*/
    sc_regSet(FLAG_OPERATION_OVERFLOW, 1);
    sc_regSet(FLAG_ZERO_DIVIDITION, 1);
    sc_regSet(FLAG_MEM_ADDR_ERROR, 1);
    sc_regSet(FLAG_IGNORE_IMPULESES, 1);
    sc_regSet(FLAG_WRONG_COMMAND, 1);
    output_reg_flags(11, 70);
    output_reg_command_counter(5, 70);
    output_reg_accumulator(2, 70);
    output_memory(2, 2);
    printf("\n");
    finalize();
    return 0;
}
