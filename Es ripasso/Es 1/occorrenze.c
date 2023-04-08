#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv) {

	if (argc != 3) {

		fprintf(stderr,"Il numero di parametri non e' corretto. Sintassi del programma: occorrenze <s> <c>");
		return EXIT_FAILURE;
	}

	int len = strlen(argv[1]);
	int count = 0;
	for (int i = 0; i < len; ++i) {
		if (argv[1][i] == argv[2][0]) {
			count++;
		}
	}
	printf("%i", count);

	return EXIT_SUCCESS;
}