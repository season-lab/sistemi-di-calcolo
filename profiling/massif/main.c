#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define NUMBUFFERS  200
#define BUFSIZE     500

void* buffers[NUMBUFFERS];

int i = 0;

void allocateFirstHalf() {
    while (i<NUMBUFFERS/2) buffers[i++] = malloc(BUFSIZE);
}

void allocateSecondHalf() {
    while (i<NUMBUFFERS) buffers[i++] = malloc(BUFSIZE);
}

int main() {
    allocateFirstHalf();
    allocateSecondHalf();

    i = 0;
    while (i<NUMBUFFERS) free(buffers[i++]);

    return 0;
}
