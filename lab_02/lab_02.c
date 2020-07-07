#include <stdio.h>
#include "lab_02.h"

int sc_memory[SC_MEMORY_SIZE];
char flag_outbound = 0;
int flag_register;

/* Initialize memory of Simple Computer by zeros */
int sc_memoryInit() {
    for(int j = 0; j < SC_MEMORY_SIZE; j++) {
        sc_memory[j] = 0;
    }
    return 0;
}

/* place value at address in sc_memory */
int sc_memorySet(int address, int value) {
    if(address >= 0 && address < SC_MEMORY_SIZE) {
        sc_memory[address] = value;
        return 0;
    }
    flag_outbound = 1;
    return -1;
}

/* get value from sc_memory */
int sc_memoryGet(int address, int *value) {
    if(address >= 0 && address < SC_MEMORY_SIZE) {
        *value = sc_memory[address];
        return 0;
    }
    flag_outbound = 1;
    return -1;
}

/* save sc_memory to disk */
int sc_memorySave(char* filename) {
    FILE* file_descriptor;
    file_descriptor = fopen(filename, "wb");
    if(file_descriptor == NULL) {
        return -1;
    }
    int how_many = fwrite(sc_memory, sizeof(sc_memory[0]), SC_MEMORY_SIZE, file_descriptor);
    printf("how many was saved: %d\n", how_many);
    if(how_many != SC_MEMORY_SIZE) {
        return -1;
    }
    fclose(file_descriptor);
    return 0;
}

/* load sc_memory from disk */
int sc_memoryLoad(char* filename) {
    FILE* file_descriptor;
    file_descriptor = fopen(filename, "rb");
    if(file_descriptor == NULL) {
        return -1;
    }
    int how_many = fread(sc_memory, sizeof(sc_memory[0]), SC_MEMORY_SIZE, file_descriptor);
    printf("how many was loaded: %d\n", how_many);
    if(how_many != SC_MEMORY_SIZE) {
        return -1;
    }
    fclose(file_descriptor);
    return 0;
}

/* initialization of flag-register by zero */
int sc_regInit(void) {
    flag_register = 0;
    return 0;
}

/* Set particular flag-register with value */
int sc_regSet(int what_register, int value) {
    if(value == 0) {
        flag_register &= ~what_register;
    } else if(value == 1) {
        flag_register |= what_register;
    } else {
        return -1;
    }
    return 0;
}

int is_register_number(int reg_number) {
    if (reg_number == FLAG_01 || 
        reg_number == FLAG_02 ||
        reg_number == FLAG_03 ||
        reg_number == FLAG_04 ||
        reg_number == FLAG_05 ||
        reg_number == FLAG_06 ||
        reg_number == FLAG_07 ||
        reg_number == FLAG_08 ||
        reg_number == FLAG_09) return 1;
    else return 0;
}

/* Get value of particular flag-register */
int sc_regGet(int what_register, int *value) {
    if(value == NULL) return -1;
    if(!is_register_number(what_register)) return -1;
    if(flag_register & what_register) *value = 1;
    else *value = 0;
    return 0;
}

/* ****************** */
/* my debug functions */
/* ****************** */
int dbg_print_sc_memory() {
    for(int i = 0; i < SC_MEMORY_SIZE; i++) {
        if(i % 10 == 0) {
            printf("\n");
        }
        printf("%4d", sc_memory[i]);
    }
    printf("\n");
    return 0;
}

/* print flag-register by bites */
int dbg_print_flag_register() {
    int bitsize = sizeof(flag_register) * 8;
    printf("flag register:\n");
    for(int i = 0; i < bitsize; i++) {
        printf("%d", 1 & (flag_register >> i));
    }
    printf("\n");
    return 0;
}
