#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>

#define NUMCHILD    4

volatile int stoppedChildren = 0;

void handler(int sig, siginfo_t *siginfo, void *context) {
    if (sig == SIGCHLD) {
        // PID letto da siginfo piuttosto che dal return value di wait
        printf("Figlio con PID %d terminato!\n", siginfo->si_pid);
        if (wait(NULL)==-1) {
            perror("Wait fallita");
            exit(1);
        }
        stoppedChildren++;
    }
}

void childProcess(int index) {
    sleep(2+index);

    _exit(0); // _exit() preferibile ad exit()
}

int main() {
    // registro il signal handler per SIGCHLD
    struct sigaction act;
    memset(&act, 0, sizeof(struct sigaction));

    act.sa_flags = SA_SIGINFO;
    act.sa_sigaction = handler;
    int ret = sigaction(SIGCHLD, &act, NULL);
    if (ret) {
        perror("sigaction fallita");
        exit(1);
    }

    // codice creazione figli
    int i = 0;
    while (i++ < NUMCHILD) {
        pid_t pid = fork();
        if (pid == -1) {
            perror("Fork fallita");
            exit(1);
        }
        if (pid==0) {
            // child
            childProcess(i);
        } else {
            // parent
            printf("Creato figlio con PID %d\n", pid);
        }
    }

    // solo il parent arriva ad eseguire questa porzione di codice
    // dato che il metodo childProcess contiene _exit()
    while (stoppedChildren != NUMCHILD);

    printf("Tutti i figli sono terminati. Uscita...\n");
    return 0;
}
