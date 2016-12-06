void charfreq(const char* text, unsigned* freq) {
    int i;
    for (i=0; i<256; ++i) freq[i] = 0;
    while (*text) freq[*text++]++;
}
