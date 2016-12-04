#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h> // memset

void handler(int signo, siginfo_t *siginfo, void *context) {
    if (signo == SIGINT)
        printf("Ignoro il tuo CTRL-C...\n");
    else if (signo == SIGTERM)
        printf("Ignoro il tuo comando kill da console...\n");
}

int main() {
    struct sigaction act;
    memset(&act, 0, sizeof(struct sigaction));

    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = handler;

    // registro un handler comune per SIGINT e SIGTERM
    int ret = sigaction(SIGINT, &act, NULL);
    if (ret) {
        perror("sigaction fallita");
        exit(1);
    }
    ret = sigaction(SIGTERM, &act, NULL);
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
