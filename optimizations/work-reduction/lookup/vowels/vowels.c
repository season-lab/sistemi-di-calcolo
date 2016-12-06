#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define LENGTH  1000
#define COUNT   10000

#define ELAPSED(start, end)     (((end)->tv_nsec/1000+(end)->tv_sec*1000000)-\
                                ((start)->tv_nsec/1000+(start)->tv_sec*1000000))

int countVowels(char* s) {
    int count = 0;
    while (*s) {
        switch (*s++) {
            case 'a':
            case 'A':
            case 'e':
            case 'E':
            case 'i':
            case 'I':
            case 'o':
            case 'O':
            case 'u':
            case 'U':
                        count++;
                        break;
        }
    }
    return count;
}

int countVowelsWithLookup(char* s, char* lookup) {
    int count = 0;
    while (*s) {
        if (lookup[(unsigned char)*s++]) count++;
    }
    return count;
}

int main(int argc, char* argv[]) {
    int count = (argc > 1) ? atoi(argv[1]) : COUNT;
    int length = (argc > 2) ? atoi(argv[2]) : LENGTH;

    char* s = malloc(length+1);
    s[length] = '\0';

    int i=0;
    while (i < length) s[i++] = 1 + rand() % 255;

    int ret;
    struct timespec start, end;

    clock_gettime(CLOCK_REALTIME, &start);
    for (i = 0, ret = 0; i < count; i++) {
        ret += countVowels(s);
    }
    clock_gettime(CLOCK_REALTIME, &end);
    printf("Vowels in string: %d\n", ret);
    printf("Elapsed: %ld usec\n", ELAPSED(&start, &end));

    char lookup[256];
    memset(lookup, 0, 256);
    lookup[65] = lookup[69] = lookup[73] = lookup[79] = lookup[85] = 1;
    lookup[97] = lookup[101] = lookup[105] = lookup[111] = lookup[117] = 1;

    clock_gettime(CLOCK_REALTIME, &start);
    for (i = 0, ret = 0; i < count; i++) {
        ret += countVowelsWithLookup(s, lookup);
    }
    clock_gettime(CLOCK_REALTIME, &end);
    printf("Vowels in string (with lookup): %d\n", ret);
    printf("Elapsed: %ld usec\n", ELAPSED(&start, &end));

    return 0;
}
