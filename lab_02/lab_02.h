#define SC_MEMORY_SIZE 100

extern unsigned int sc_memory[SC_MEMORY_SIZE];
extern char flag_outbound;

/* Initialize memory of Simple Computer by zeros */
int sc_memoryInit();

/* place value at address in sc_memory */
int sc_memorySet(int address, int value);

/* get value from sc_memory */
int sc_memoryGet(int address, int *value);

/* 

/* my dbg */
int dbg_print_sc_memory();
