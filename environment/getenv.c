#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s env-var (try PATH, USER, PWD, HOME)\n", argv[0]);
        return EXIT_FAILURE;
    }
    char* env = getenv(argv[1]);
    printf("%s=%s\n", argv[1], env);
    return EXIT_SUCCESS;
}
