#include <stdio.h>
#include <unistd.h>

void busy_loop(long iterations) {
    volatile long i;
    for (i = 0; i < iterations; i++) {
    }
}

void work_heavy() {
    busy_loop(200000000);
}

void work_medium() {
    busy_loop(100000000);
}

void work_light() {
    busy_loop(50000000);
}

int main() {
    for (int i = 0; i < 3; i++) {
        work_heavy();
        work_medium();
        work_light();
        usleep(200000);
    }
    return 0;
}
