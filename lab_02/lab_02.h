#define SC_MEMORY_SIZE 100

#define FLAG_01 0x1
#define FLAG_02 0x2
#define FLAG_03 0x4
#define FLAG_04 0x8
#define FLAG_05 0x10
#define FLAG_06 0x20
#define FLAG_07 0x40
#define FLAG_08 0x80
#define FLAG_09 0x100


extern int sc_memory[SC_MEMORY_SIZE];
extern char flag_outbound;
extern int flag_register;

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

/* my dbg */

int dbg_print_sc_memory();

int dbg_print_flag_register();
