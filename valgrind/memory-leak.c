#include <stdlib.h>
#include <stdio.h>

#define LEN 10

int main() {

	int * buffer = calloc(sizeof(int) * LEN);
	
	int i;
	for (i = 0; i < LEN; i++)
		printf("buffer[%d] = %d\n", i, buffer[i]);

	return 0;
}