#include <stdlib.h>

int main() {

	int * buffer = malloc(sizeof(int) * 10);
	// interesting stuff with buffer [...]
	free(buffer);
	// some other stuff [...]
	free(buffer);

	return 0;
}

