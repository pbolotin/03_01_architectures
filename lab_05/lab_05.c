#include <unistd.h>
#include <stdio.h>
#include <termios.h>
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
    if(vtime < 0 || vmin < 0) return -1;
    
    /*
    struct termios{
        tcflag_t c_iflag;
        tcflag_t c_oflag;
        tcflag_t c_lflag;
        tcflag_t c_cflag;
        tcflag_t c_cc[NCCS];
    }*/
    struct termios myTermStruct;
    /*Load old termios value*/
    tcgetattr(0, &myTermStruct);
    
    if(regime & ICANON) {
        printf("Set ICANON flag\n");
        myTermStruct.c_lflag |= ICANON;
    } else {
        printf("Unset ICANON flag\n");
        myTermStruct.c_lflag &= ~ICANON;
    }
    if(echo & ECHO) {
        printf("Set ECHO flag\n");
        myTermStruct.c_lflag |= ECHO;
    } else {
        printf("Unset ECHO flag\n");
        myTermStruct.c_lflag &= ~ECHO;
    }
    if(sigint & ISIG) {
        printf("Set ISIG flag\n");
        myTermStruct.c_lflag |= ISIG;
    } else {
        printf("Unset ISIG flag\n");
        myTermStruct.c_lflag &= ~ISIG;
    }
    /*
    MIN == 0, TIME == 0 (polling read)
    If data is available, read(2) returns immediately,
    with the lesser of the number of bytes available,
    or the number of bytes requested.
    If no data is available, read(2) returns 0.
    */
    if(vmin == 0 && vtime == 0) {
        printf("Set polling read\n");
        myTermStruct.c_cc[VMIN] = vmin;
        myTermStruct.c_cc[VTIME] = vtime;
    }
    /*
    MIN > 0, TIME == 0 (blocking read)
    read(2) blocks until MIN bytes are available,
    and returns up to the number of bytes requested.
    */
    else if(vmin > 0 && vtime == 0) {
        printf("Set blocking read\n");
        myTermStruct.c_cc[VMIN] = vmin;
        myTermStruct.c_cc[VTIME] = vtime;
    }
    /*
    MIN == 0, TIME > 0 (read with timeout)
    TIME specifies the limit for a timer in tenths of a second.
    The timer is started when read(2) is called.
    read(2) returns either when at least one byte of data is available,
    or when the timer expires.
    If the timer expires without any input becoming available,
    read(2) returns 0.  If data is already available
    at the time of the call to read(2),
    the call behaves as though the data was received immediately after the call.
    */ 
    else if(vmin == 0 && vtime > 0) {
        printf("Set read with timeout\n");
        myTermStruct.c_cc[VMIN] = vmin;
        myTermStruct.c_cc[VTIME] = vtime;
    }
    /* MIN > 0, TIME > 0 (read with interbyte timeout)
    TIME specifies the limit for a timer in tenths of a second.
    Once an initial byte of input becomes available,
    the timer is restarted after each further byte is received.
    read(2) returns when any of the following conditions is met:
    MIN bytes have been received.
    The interbyte timer expires.
    The number of bytes requested by read(2) has been received.
    (POSIX does not specify this termination condition,
    and on some other implementations read(2) does not return in this case.)
    Because the timer is started only after the initial byte becomes available,
    at least one byte will be read.
    If data is already available at the time of the call to read(2),
    the call behaves as though the data was received immediately after the call.
    */
    else if(vmin > 0 && vtime > 0) {
        printf("Set read with interbyte timeout\n");
        myTermStruct.c_cc[VMIN] = vmin;
        myTermStruct.c_cc[VTIME] = vtime;
    }
    /*Set new value of termios*/
    tcsetattr(0, TCSADRAIN, &myTermStruct);
    return 0;
}
