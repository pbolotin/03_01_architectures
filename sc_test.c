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
    dbg_print_sc_memory();
    return 0;
}
