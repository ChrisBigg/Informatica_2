#include "vettore.h"

int main(void) {
	ElemType* elm = malloc(5 * sizeof(ElemType));
	elm[0] = 12;
	elm[1] = 5;
	elm[2] = 6;
	elm[3] = 19;
	elm[4] = 3;
	Vector v = { .capacity = 5, .size = 5, .data = NULL};

	VectorSort(&v);



	return EXIT_SUCCESS;
}