#include <stdio.h>
#include <stdlib.h>

int main() {

	int array[10] = { 0 };

	int k;
	for (k = 0; k <= sizeof(array) / sizeof(int); k++)
		printf("array[%d] = %d\n", k, array[k]);

	return 0;
}
