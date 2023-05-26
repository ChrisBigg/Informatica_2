
#include "minheap.h"
#include <stdbool.h>
#include <stdlib.h>


bool HeapMinPop(Heap* h, ElemType* e) {

	if (HeapIsEmpty(h)) {
		return false;
	}

	ElemSwap(HeapGetNodeValue(h, 0), HeapGetNodeValue(h, h->size - 1));

	int i = 0;

	

	while(HeapGetNodeValue(h, i) > )
	HeapMinMoveDown(h, 0);

	return true;

}


