#include "minheap.h"
#include <stdlib.h>

void HeapMinMoveDownRec(Heap* h, int i) {

	if (i >= h->size - 1) {
		return;
	}

	int index_e;
	ElemType e;
	bool skip = false;

	if (HeapLeft(i) >= h->size && HeapRight(i) < h->size) {
		index_e = HeapRight(i);
		e = *HeapGetNodeValue(h, index_e);
		skip = true;
	}

	if (HeapRight(i) >= h->size && HeapLeft(i) < h->size) {
		index_e = HeapLeft(i);
		e = *HeapGetNodeValue(h, index_e);
		skip = true;
	}

	if (!skip) {
		if (*HeapGetNodeValue(h, HeapLeft(i)) < *HeapGetNodeValue(h, HeapRight(i))) {

			index_e = HeapLeft(i);
			e = *HeapGetNodeValue(h, index_e);
		}
		else {
			index_e = HeapRight(i);
			e = *HeapGetNodeValue(h, index_e);
		}
	}


	if (*HeapGetNodeValue(h, i) > e) {
		ElemSwap(HeapGetNodeValue(h, i), HeapGetNodeValue(h, index_e));
		HeapMinMoveDownRec(h, index_e);
	}
	else {
		return;
	}



}

