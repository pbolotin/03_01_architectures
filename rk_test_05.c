#include <stdio.h>
#include <unistd.h>
#include <stdio.h>
#include <termios.h>
#include <sys/ioctl.h>
#include "lab_05/myReadKey.h"

int main() {
    printf("rk_test_05");
    enum keys key_place;
    rk_mytermregime(~ICANON, 0, 1, ECHO, ISIG);
    rk_readkey(&key_place);
    rk_mytermregime(ICANON, 0, 0, ~ECHO, ISIG);
    rk_readkey(&key_place);rk_readkey(&key_place);rk_readkey(&key_place);rk_readkey(&key_place);rk_readkey(&key_place);rk_readkey(&key_place);rk_readkey(&key_place);rk_readkey(&key_place);rk_readkey(&key_place);rk_readkey(&key_place);
    return 0;
}
