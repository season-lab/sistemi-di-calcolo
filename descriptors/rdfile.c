#include <unistd.h> // read, write, close
#include <fcntl.h>  // open
#include <stdlib.h> // exit
#include <stdio.h>  // printf


int main(int argc, char* argv[]) {

    char buffer[256];
    ssize_t res;

    if (argc < 2) {
        printf("Usage: %s filename\n", argv[0]);
        exit(1);
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd == -1) {
        perror("Error in open");
        exit(1);
    }

    while(1) {
        res = read(fd, buffer, sizeof(buffer));
        if (res == -1) {
            perror("Error in read");
            exit(1);
        }
        if (res == 0) break; // EOF

        if (write(STDOUT_FILENO, buffer, res) == -1) {
            perror("Error in write");
            exit(1);
        }
    }

    if (close(fd)) {
        perror("Error in close");
        exit(1);
    }

    return 0;
}
