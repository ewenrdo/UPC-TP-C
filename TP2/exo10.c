#include <stdio.h>

int main(void) {

    time_t startTime = time(NULL);

    while (time(NULL) - startTime < 10) {
        puts("J'adore ce TP!");
    }
}