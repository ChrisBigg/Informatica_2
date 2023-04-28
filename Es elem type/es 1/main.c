#include "vettore.h"

int main(void) {
	Vector *v;

	v = VectorReadSorted("input_int_01.txt");


	free(v->data);
	free(v);
	return EXIT_SUCCESS;
}