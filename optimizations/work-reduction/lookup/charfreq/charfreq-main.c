#include <stdio.h>
#include <string.h>

void charfreq(const char* text, unsigned* freq);

int main() {
    unsigned i, freq[256];
    memset(freq, 0xAF, 256*sizeof(unsigned)); // inizializzazione farlocca per verificare poi se freq viene calcolato correttamente...
    charfreq("Traveling through hyperspace ain't like dusting crops, farm boy.", freq);
    for (i=0; i<256; ++i) printf(i < 32 || i>127 ? "%3d: %u\n": "\'%c\': %u\n", i, freq[i]); // fra gli altri, deve stampare 'e': 4, ecc.
    return 0;
}
