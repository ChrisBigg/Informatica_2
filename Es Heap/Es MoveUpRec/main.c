#include "minheap.h"
#include <stdlib.h>

extern void HeapMinMoveUpRec(Heap* h, int i);

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

	const ElemType v[] = { 1, 9, 5, 7, 3, 4 };
	Heap* h = HeapMinHeapify(v, 6);
	const ElemType e = 2;

	h->size++;
	h->data = realloc(h->data, sizeof(ElemType) * h->size);
	h->data[h->size - 1] = ElemCopy(&e);

	HeapMinMoveUpRec(h, h->size - 1);
	HeapWriteStdout(h);


	return 0;
}