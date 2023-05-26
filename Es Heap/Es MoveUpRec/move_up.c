#include "minheap.h"
#include <stdlib.h>

void HeapMinMoveUpRec(Heap* h, int i) {
	//bool done = false;

	if (*HeapGetNodeValue(h, HeapParent(i)) > *HeapGetNodeValue(h, i)) {

		ElemSwap(HeapGetNodeValue(h, HeapParent(i)), HeapGetNodeValue(h, i));
		HeapMinMoveUpRec(h, HeapParent(i));

	}
	else {
		//done = true;
		return;
	}


	if (i == 0) {
		//done = true;
		return;
	}


}

