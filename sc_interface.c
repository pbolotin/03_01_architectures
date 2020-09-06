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

int output_memory(void) {
    int i;
    int memValue = 0;
    int decCommand = 0;
    int decOperand = 0;
    int ret = 0;
    char show[6] = {0,0,0,0,0,0};
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
        printf(" %s", show);
        if((i+1)%10 == 0) {
            printf("\n");
        }
    }
    //dbg_print_sc_memory();
    return 0;
}

int output_registers(void) {
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
    output_memory();
    finalize();
    return 0;
}
