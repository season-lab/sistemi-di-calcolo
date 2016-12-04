#include <unistd.h> // read, write, close
#include <fcntl.h>  // open
#include <stdlib.h> // exit

char text[] = "Pen pineapple apple pen\n";

int main(int argc, char* argv[]) {
    int fd = open("test.txt", O_WRONLY | O_CREAT | O_TRUNC, 0640);
    if (fd == -1) {
        perror("Error in open");
        exit(1);
    }
    if (write(fd, text, sizeof(text)) != sizeof(text)) {
        perror("Error in write");
        exit(1);
    }
    if (close(fd)) {
        perror("Error in close");
        exit(1);
    }
    return 0;
}
