#include <stdio.h>
#include <stdlib.h>

int main() {

	int size = sizeof(int) * 10;
	int * array = calloc(1, size);

	int k;
	for (k = 0; k < size / sizeof(int); k++)
		printf("array[%d] = %d\n", k, array[k]);

	free(array);
	return 0;
}
