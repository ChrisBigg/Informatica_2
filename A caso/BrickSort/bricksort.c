
#include <stdlib.h>
#include <stdbool.h>

void SwapInt(int* a, int* b) {
	int tmp = *a;
	*b = *a;
	*a = tmp;
}

void BrickSort(int* v, size_t v_size) {
	bool swap = false;


	while (!swap) {
		for (int i = 0; i < v_size - 2; i++) {
			for()
			if (v[i] > v[i + 2]) {
				SwapInt(&v[i], &v[i+2])
			}


		}
	}
}

