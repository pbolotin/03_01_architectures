#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <sys/ioctl.h>
#include "lab_05/myReadKey.h"

int main() {
    printf("rk_test_05");
    enum keys key_place;

    rk_mytermsave();
    
    //rk_mytermregime(~ICANON, 0, 1, ~ECHO, ISIG);
    rk_mytermregime(~ICANON, 1, 0, ~ECHO, ISIG);
    //rk_mytermregime(ICANON, 0, 0, ~ECHO, ISIG);
    int flag_to_quit = 0;
    while(!flag_to_quit) {
        if(rk_readkey(&key_place) > 0) {
            switch(key_place) {
                case KEY_s:
                case KEY_S:
                    printf("S\n");
                    break;
                case KEY_l:
                case KEY_L:
                    printf("L\n");
                    break;
                case KEY_q:
                case KEY_Q:
                    printf("Q\n");
                    flag_to_quit = 1;
                    break;
                case KEY_UP:
                    printf("UP\n");
                    break;
                case KEY_DOWN:
                    printf("DOWN\n");
                    break;
                case KEY_RIGHT:
                    printf("RIGHT\n");
                    break;
                case KEY_LEFT:
                    printf("LEFT\n");
                    break;
                case KEY_F5:
                    printf("F5\n");
                    break;
                case KEY_F6:
                    printf("F6\n");
                    break;
                case UNKNOWN_KEY:
                    printf("UNKNOWN\n");
                    break;
            }
        }
    }
    rk_mytermrestore();
    return 0;
}
