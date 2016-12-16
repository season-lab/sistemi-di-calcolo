#include <unistd.h>   // getpagesize
#include <sys/mman.h> // mprotect
#include <stdio.h>    // printf
#include <stdlib.h>   // exit

int main() {
    // stringa in sola lettura
    char* str = "hello world!";

    // ottiene dimensione della pagina in byte
    int pagesize = getpagesize();
    printf("page size = %d bytes\n", pagesize);

    // calcola indirizzo della pagina che contiene la stringa
    void* page_ptr = (void*)(((long)str / pagesize) * pagesize);

    // metodo alternativo valido per page size == 2^N
    //void* page_ptr = (void*)((long)str & ~(pagesize-1));

    // imposta privilegi rwx per la pagina che contiene la stringa
    #if 1  // mettere 0 per verificare che str è protetta di default
    int res = mprotect(page_ptr, pagesize, PROT_READ | PROT_WRITE | PROT_EXEC);
    if (res == -1) {
        perror("errore in mprotect");
        exit(1);
    }
    #endif

    str[0] = 'H'; // modifica stringa originariamente in sola lettura
    puts(str);

    return 0;
}
