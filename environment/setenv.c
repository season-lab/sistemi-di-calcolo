#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, char* argv[]) {
    if (argc < 3) {
        printf("Usage: %s env-var value\n", argv[0]);
        return EXIT_FAILURE;
    }
    if (setenv(argv[1],argv[2],0)) {
        perror("Error in setenv");
        switch errno {
            case EINVAL: printf("(EINVAL)\n"); break;
            case ENOMEM: printf("(ENOMEM)\n"); break;
        }
    }
    printf("%s=%s\n", argv[1], getenv(argv[1]));
    return EXIT_SUCCESS;
}
