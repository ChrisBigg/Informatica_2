#include "list.h"

const ElemType* MaxElement(const Item* i);

int main(void) {
	
    ElemType e1[] = { 3, 4, 2, 0, 45, 1, 3 };
    size_t e1_size = sizeof(e1) / sizeof(ElemType);

    Item* l1 = ListCreateEmpty();
    for (size_t i = 0; i < e1_size; ++i) {
        l1 = ListInsertBack(l1, e1 + i);
    }

    MaxElement(l1);

	return 0;
}