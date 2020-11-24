#ifndef _LAB_05_
#define _LAB_05_

enum keys {
    KEY_s,
    KEY_S,
    KEY_l,
    KEY_L,
    KEY_q,
    KEY_Q,
    KEY_UP,
    KEY_DOWN,
    KEY_RIGHT,
    KEY_LEFT,
    KEY_F5,
    KEY_F6,
    UNKNOWN_KEY
};

#define READ_BUFFER_SIZE 1024

typedef struct seq_element {
    int code;
    long time;
} seq_element;

#define _HOW_MANY_CODES_SEQ 12

int _rk_symbol_analysis(char* read_as_str);

#define TIMEOUT_TO_NEW_KEY_NANOSEC 100000000

int rk_readkey(enum keys * key);

int rk_mytermsave(void);

int rk_mytermrestore(void);

int rk_mytermregime(int regime, int vtime, int vmin, int echo, int sigint);

#endif
