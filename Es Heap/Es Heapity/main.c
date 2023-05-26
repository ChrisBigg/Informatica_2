#include "minheap.h"
#include <stdlib.h>
extern Heap* HeapMinHeapify(const ElemType* v, size_t v_size);

int main(void) {

	const ElemType v[] = { 1, 9, 5, 4, 7, 3, 2 };

	Heap* h = HeapMinHeapify(v, 7);

	HeapWriteStdout(h);

	return 0;
}