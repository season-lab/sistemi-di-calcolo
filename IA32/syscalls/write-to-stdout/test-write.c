#include <unistd.h>

unsigned mywrite(int fd,
                 const void* buffer,
                 unsigned size);

int main() {
    int x = mywrite(1, "Hello\n", 6);
    return x;
}
