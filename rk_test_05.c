#include <stdio.h>
#include "lab_05/myReadKey.h"

int main() {
    printf("rk_test_05");
    enum keys key_place;
    rk_readkey(&key_place);
    rk_mytermregime(0, 0, 0, 0, 0);
    return 0;
}
