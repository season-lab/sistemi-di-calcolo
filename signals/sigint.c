#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memset

int main() {
    struct sigaction act;
    memset(&act, 0, sizeof(struct sigaction));

    // ignorando SIGINT il programma non terminerà più al CTRL-C
    act.sa_handler = SIG_IGN;
    int ret = sigaction(SIGINT, &act, NULL);
    if (ret) {
        perror("sigaction fallita");
        exit(1);
    }

    unsigned i = 0;
    while (i++ >= 0) {
        if (i % 100000000 == 0)
            printf("Ciao...\n");
    }

    return 0;
}
