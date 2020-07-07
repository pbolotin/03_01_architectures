#include <stdio.h>
#include "lab_02.h"

unsigned int sc_memory[SC_MEMORY_SIZE];
char flag_outbound = 0;

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

/* sc_memory save to disk */
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

/* sc_memory save to disk */
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

/* my debug*/
int dbg_print_sc_memory() {
    for(int i = 0; i < SC_MEMORY_SIZE; i++) {
        if(i % 10 == 0) {
            printf("\n");
        }
        printf("%4d", sc_memory[i]);
    }
    return 0;
}
