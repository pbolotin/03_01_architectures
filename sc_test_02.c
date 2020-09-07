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
/*
FLAG_OPERATION_OVERFLOW
FLAG_ZERO_DIVIDITION
FLAG_MEM_ADDR_ERROR
FLAG_IGNORE_IMPULESES
FLAG_WRONG_COMMAND
*/
    sc_regSet(FLAG_IGNORE_IMPULESES, 1);
    sc_regSet(FLAG_MEM_ADDR_ERROR, 1);
    sc_regSet(FLAG_ZERO_DIVIDITION, 1);
    sc_regSet(FLAG_MEM_ADDR_ERROR, 0);
    dbg_print_flag_register();
    
    int from_flag_register = 0;
    int return_code = sc_regGet(FLAG_ZERO_DIVIDITION, &from_flag_register);
    printf("return code of sc_regGet:%d\n", return_code);
    printf("from flag_register:%d\n", from_flag_register);
    
    int toEncodeCommand = 0;
    return_code = sc_commandEncode(OP_01_READ, 16, &toEncodeCommand);
    printf("return code of sc_encodeCommand:%d\n", return_code);
    printf("toEncodeCommand:%d\n", toEncodeCommand);
    dbg_print_command(toEncodeCommand);
    
    int toDecodeCommand;
    int toDecodeOperand;
    return_code = sc_commandDecode(toEncodeCommand, &toDecodeCommand, &toDecodeOperand);
    printf("return code of sc_decodeCommand:%d\n", return_code);
    printf("toDecodeCommand:%d and Operand:%d\n", toDecodeCommand, toDecodeOperand);
    dbg_print_command_and_operand(toDecodeCommand, toDecodeOperand);
    
    return 0;
}
