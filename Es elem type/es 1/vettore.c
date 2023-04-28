#include "vettore.h"


Vector* VectorRead(const char* filename) {
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}
	int crt_read;
	ElemType e;
	Vector* v = malloc(sizeof(Vector));
	v->capacity = 1;
	v->size = 0;
	v->data = malloc(sizeof(ElemType));

	crt_read = ElemRead(f, &e);
	if (crt_read == 0) {
		return NULL;
	}

	while (crt_read == 1) {
		// aumento la dimensione del Vector
		if (v->capacity == v->size) {
			v->capacity *= 2;
			v->data = realloc(v->data, v->capacity * sizeof(ElemType));
		}
		v->data[v->size] = e;
		v->size++;

		crt_read = ElemRead(f, &e);
	}
	v->capacity = v->size;
	v->data = realloc(v->data, v->capacity * sizeof(ElemType));

	fclose(f);

	return v;
}

Vector* VectorReadSorted(const char* filename) {
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return NULL;
	}
	int crt_read;
	ElemType e;

	Vector* v = malloc(sizeof(Vector));
	v->capacity = 1;
	v->size = 0;
	v->data = malloc(sizeof(ElemType));

	crt_read = ElemRead(f, &e);
	if (crt_read == 0) {
		return NULL;
	}
	bool find = false;

	while (crt_read == 1) {
		// aumento la dimensione del Vector
		if (v->capacity == v->size) {
			v->capacity *= 2;
			v->data = realloc(v->data, v->capacity * sizeof(ElemType));
		}
		v->data[v->size] = e;
		v->size++;

		// ordinamento
		for (size_t i = 0; i < v->size - 1; i++) {
			if (v->data[i] > e) {
				//posto giusto
				//scambio l'ultimo elemento (e) con quello nel posto giusto
				ElemSwap(&v->data[v->size - 1], &v->data[i]);
			}
		}

		crt_read = ElemRead(f, &e);
	}

	fclose(f);
	return v;
}

