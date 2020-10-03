#include <unistd.h>
#include <stdio.h>
#include <sys/ioctl.h>
#include "lab_05.h"

int rk_readkey(enum keys * key) {
    int fd = 0;//stdin
    /*Check if fd is a tty*/
    if(!isatty(fd)) {
        perror("Sorry, need to use termian as stdin 0\n");
        return -1;
    }
    char for_read;
    int read_res;
    while(1) {
        read_res = read(0, &for_read, sizeof(for_read));
        if(0 == read_res) {
            printf("\nNo input anymore\n");
            break;
        } else if(read_res < 0) {
            perror("\nError occured when reading\n");
            return -1;
        }
        printf("Was read: %d\n", (int)for_read);
    }
    return 0;
}

int rk_mytermsave(void)  {
    return 0;
}

int rk_mytermrestore(void)  {
    return 0;
}

int rk_mytermregime(int regime, int vtime, int vmin, int echo, int sigint)  {
    return 0;
}
