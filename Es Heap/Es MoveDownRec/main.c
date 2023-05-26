#include "minheap.h"
#include <stdlib.h>

extern void HeapMinMoveDownRec(Heap* h, int i);

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

int main(void) {


	const ElemType v[] = { 5, 4, 6, 12, 23, 32 };

	Heap* h = HeapMinHeapify(v, 6);
	ElemSwap(&h->data[0], &h->data[5]);
	ElemSwap(&h->data[5], &h->data[2]);

	HeapMinMoveDownRec(h, 0);

	return 0;

}
