#ifndef _LAB_02_

#define _LAB_02_

#define SC_MEMORY_SIZE 100

#define FLAG_OPERATION_OVERFLOW 0x1//Operation overflow 
#define FLAG_ZERO_DIVIDITION 0x2//Zero dividition 0
#define FLAG_MEM_ADDR_ERROR 0x4//Wrong memory address E
#define FLAG_IGNORE_IMPULESES 0x8//Ignore tic impulses V
#define FLAG_WRONG_COMMAND 0x10//Wrong command M

#define IS_COMMAND 0x4000
#define MASK_OF_COMMAND 0x3f80
#define MASK_OF_OPERAND 0x7f

#define OP_01_READ 10
#define OP_01_WRITE 11

#define OP_02_LOAD 20
#define OP_02_STORE 21

#define OP_03_ADD 30
#define OP_03_SUB 31
#define OP_03_DIVIDE 32
#define OP_03_MUL 33

#define OP_04_JUMP 40
#define OP_04_JNEG 41
#define OP_04_JZ 42
#define OP_04_HALT 43

#define OP_05_NOT 51
#define OP_05_AND 52
#define OP_05_OR 53
#define OP_05_XOR 54

#define OP_06_JNS 55
#define OP_06_JC 56
#define OP_06_JNC 57
#define OP_06_JP 58
#define OP_06_JNP 59

#define OP_07_CHL 60
#define OP_07_SHR 61
#define OP_07_RCL 62
#define OP_07_RCR 63

#define OP_08_NEG 64

#define OP_09_ADDC 65
#define OP_09_SUBC 66

#define OP_10_LOGLC 67
#define OP_10_LOGRC 68
#define OP_10_RCCL 69
#define OP_10_RCCR 70

#define OP_11_MOVA 71
#define OP_11_MOVR 72
#define OP_11_MOVCA 73
#define OP_11_MOVCR 74

#define OP_12_ADDC 75
#define OP_12_SUBC 76 //0x4C

extern unsigned int sc_memory[];
extern unsigned int sc_reg_accumulator;//15 bit
extern unsigned int sc_reg_command_counter;//7 bit
extern unsigned int sc_reg_flags;//5 bit

extern int sc_errno;

/* Initialize memory of Simple Computer by zeros */
int sc_memoryInit();

/* place value at address in sc_memory */
int sc_memorySet(int address, int value);

/* get value from sc_memory */
int sc_memoryGet(int address, int *value);

/* */
int sc_memorySave(char *filename);

int sc_memoryLoad(char* filename);

int sc_regInit(void);

int sc_regSet(int what_flag, int value);

int sc_regGet(int what_register, int *value);

int sc_commandEncode(int command, int operand, int* value);

#define EPLACE -1
#define ECOMMANDBIT -2
#define EWRONGCOMMAND -3
int sc_commandDecode(int value, int* command, int* operand);

/* my dbg */

int dbg_print_sc_memory();

int dbg_print_flag_register();

int dbg_print_command(int);

int dbg_print_command_and_operand(int, int);

#endif
