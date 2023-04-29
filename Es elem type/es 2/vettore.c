

#include "vettore.h"

void VectorSort(Vector* v) {

	if (v == NULL || v->data == NULL || v->capacity == NULL || v->size == NULL) {
		return ;
	}
	else {
		bool sort = true;
		size_t i = 0;

		while (true) {

			if (i == (v->size - 1)) {
				i = 0;

				if (sort) {
					break;
				}
				else {
					sort = true;
				}
			}

			if (ElemCompare(&v->data[i], &v->data[i + 1]) == 1) {
				ElemSwap(&v->data[i], &v->data[i + 1]);
				sort = false;
			}

			i++;
		}

		return;
	}
	
}

