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

/* functions about commands */
/* Encode */
/* 15 bit total */
/* 1 bit 0 (then this is command) */
/* next 7 bit code of operation */
/* next 7 bit operand */
int sc_commandEncode(int command, int operand, int* value) {
    /* check value */
    if(value == NULL) {
        return -1;
    }
    /* check command */
    switch(command) {
    case OP_01_READ://op 0-99
    case OP_01_WRITE://op 0-99
    
    case OP_02_LOAD://op 0-99
    case OP_02_STORE://op 0-99

    case OP_03_ADD://op 0-99
    case OP_03_SUB://op 0-99
    case OP_03_DIVIDE://op 0-99
    case OP_03_MUL://op 0-99

    case OP_04_JUMP://op 0-99
    case OP_04_JNEG://op 0-99
    case OP_04_JZ://op 0-99
    case OP_04_HALT://op any

    case OP_05_NOT://op 0-99
    case OP_05_AND://op 0-99
    case OP_05_OR://op 0-99
    case OP_05_XOR://op 0-99

    case OP_06_JNS://op 0-99
    case OP_06_JC://op 0-99
    case OP_06_JNC://op 0-99
    case OP_06_JP://op 0-99
    case OP_06_JNP://op 0-99

    case OP_07_CHL://op 0-99
    case OP_07_SHR://op 0-99
    case OP_07_RCL://op 0-99
    case OP_07_RCR://op 0-99

    case OP_08_NEG://op 0-99

    case OP_09_ADDC://op 0-99
    case OP_09_SUBC://op 0-99

    case OP_10_LOGLC://op 0-99
    case OP_10_LOGRC://op 0-99
    case OP_10_RCCL://op 0-99
    case OP_10_RCCR://op 0-99

    case OP_11_MOVA://op 0-99
    case OP_11_MOVR://op 0-99
    case OP_11_MOVCA://op 0-99
    case OP_11_MOVCR://op 0-99
       
    case OP_12_ADDC://op 0-99
    case OP_12_SUBC://op 0-99
    break;
    default:
    return -1;
    }
    /* check operand */
    if(command != OP_04_HALT && (operand < 0 || operand >= SC_MEMORY_SIZE)) return -1;
    if(value == NULL) return -1;
    /* encode */
    int bild_encode = 0;
    bild_encode |= (command << 7);
    bild_encode |= operand;
    bild_encode |= IS_COMMAND;
    *value = bild_encode;
    return 0;
}

int sc_commandDecode(int value, int* command, int* operand) {
    if(command == NULL || operand == NULL) return -1;
    *command = 0x00000000;
    *operand = 0x00000000;
    if(0 == (value | IS_COMMAND)) {
        return -1;
    }
    /* check command */
    switch((value & MASK_OF_COMMAND)>>7) {
    case OP_01_READ://op 0-99
    case OP_01_WRITE://op 0-99
    
    case OP_02_LOAD://op 0-99
    case OP_02_STORE://op 0-99

    case OP_03_ADD://op 0-99
    case OP_03_SUB://op 0-99
    case OP_03_DIVIDE://op 0-99
    case OP_03_MUL://op 0-99

    case OP_04_JUMP://op 0-99
    case OP_04_JNEG://op 0-99
    case OP_04_JZ://op 0-99
    case OP_04_HALT://op any

    case OP_05_NOT://op 0-99
    case OP_05_AND://op 0-99
    case OP_05_OR://op 0-99
    case OP_05_XOR://op 0-99

    case OP_06_JNS://op 0-99
    case OP_06_JC://op 0-99
    case OP_06_JNC://op 0-99
    case OP_06_JP://op 0-99
    case OP_06_JNP://op 0-99

    case OP_07_CHL://op 0-99
    case OP_07_SHR://op 0-99
    case OP_07_RCL://op 0-99
    case OP_07_RCR://op 0-99

    case OP_08_NEG://op 0-99

    case OP_09_ADDC://op 0-99
    case OP_09_SUBC://op 0-99

    case OP_10_LOGLC://op 0-99
    case OP_10_LOGRC://op 0-99
    case OP_10_RCCL://op 0-99
    case OP_10_RCCR://op 0-99

    case OP_11_MOVA://op 0-99
    case OP_11_MOVR://op 0-99
    case OP_11_MOVCA://op 0-99
    case OP_11_MOVCR://op 0-99
       
    case OP_12_ADDC://op 0-99
    case OP_12_SUBC://op 0-99
        *command = value & MASK_OF_COMMAND;
    break;
    default:
        return -1;
    }
    /* get operand */
    *operand = value & MASK_OF_OPERAND;
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

int dbg_print_command(int command) {
    int bitsize = sizeof(command) * 8;
    printf("Command:\n");
    for(int i = 14; i >= 0; i--) {
        if(i == 13 || i == 6) printf(" ");
        printf("%d", 1 & (command >> i));
    }
    printf("\n");
    return 0;
}

int dbg_print_command_and_operand(int command, int operand) {
    printf("Command %d\n", command);
    printf("Operand %d\n", operand);
    return 0;
}
