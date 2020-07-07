#include <stdio.h>
#include "lab_02/lab_02.h"

int main() {
    printf("Simple Computer\n");
    //dbg_print_sc_memory();
    sc_memoryInit();
    sc_memorySet(0, 11);
    sc_memorySet(99, 100);
    
    int from_sc_memory = 0;
    sc_memoryGet(0, &from_sc_memory);
    printf("From sc_memory:%d\n", from_sc_memory);
    sc_memoryGet(99, &from_sc_memory);
    printf("From sc_memory:%d\n", from_sc_memory);
    sc_memorySave("test_sc_memorySave.bin");
    sc_memoryInit();
    sc_memoryLoad("test_sc_memorySave.bin");
    dbg_print_sc_memory();
    
    sc_regInit();
    dbg_print_flag_register();
    sc_regSet(FLAG_04, 1);
    sc_regSet(FLAG_03, 1);
    sc_regSet(FLAG_02, 1);
    sc_regSet(FLAG_03, 0);
    dbg_print_flag_register();
    return 0;
}
