
#include <stdlib.h>
#include <stdio.h>


int main(int argc, char** argv) {

	if (argc != 3) {
		fprintf(stderr, "Il numero di parametri non e' corretto. Sintassi del programma: mul <a> <b>");
		return EXIT_FAILURE;
	}
	int a, b;

	a = atoi(argv[1]);
	b = atoi(argv[2]);

	printf("%i", a * b);


	return EXIT_SUCCESS;
}
