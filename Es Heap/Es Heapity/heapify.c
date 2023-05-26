
#include "minheap.h"
#include <stdlib.h>


Heap* HeapMinHeapify(const ElemType* v, size_t v_size) {
	Heap* pnt = HeapCreateEmpty();
	if (v == NULL) {
		return pnt;
	}

	for (size_t i = 0; i < v_size; i++) {
		HeapMinInsertNode(pnt, &v[i]);
	}

	return pnt;
}

