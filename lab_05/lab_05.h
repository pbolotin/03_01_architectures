#ifndef _LAB_05_
#define _LAB_05_

enum keys {
    KEY_UP,
    KEY_DOWN
};

int rk_readkey(enum keys * key);

int rk_mytermsave(void);

int rk_mytermrestore(void);

int rk_mytermregime(int regime, int vtime, int vmin, int echo, int sigint);

#endif
