#include <errno.h>
#include <fcntl.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

ssize_t my_write(int fd, const char* buf, int n);

int main() {
    int fd = open("prova.txt", O_WRONLY|O_CREAT|O_TRUNC, 0644);
    if (fd < 0) {
        perror("Unable to open file");
        exit(1);
    }

    char* str = "Ciao\n";
    ssize_t ret = my_write(fd, str, strlen(str));
    // quando invoco una syscall con INT in caso di errore potrei avere
    // un qualsiasi numero negativo come return value (non solo -1)
    if (ret < 0) {
        errno = -ret; // finezza: setto errno come avrebbe fatto write()
        perror("Unable to write");
        exit(1);
    }
    printf("Written bytes: %d\n", ret);

    if (close(fd)) {
        perror("Unable to close file");
        exit(1);
    }
    return 0;
}
