
#include "cc.h"

int main(void) {

	ElemType e1[] = { 0, 1, 3, 4, 5, 6, 8, 7 };
	size_t e1_size = sizeof(e1) / sizeof(ElemType);

	Item* l1 = ListCreateEmpty();
	for (size_t i = 0; i < e1_size; ++i) {
		l1 = ListInsertBack(l1, e1 + i);
	}

	ElemType v[] = { 7,8,0,4,6 };

	ComponentiConnesse(l1, v, 5);


	return EXIT_SUCCESS;
}