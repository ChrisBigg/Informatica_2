
#include <stdlib.h>
#include "list.h"

Item* Diff(const Item* i1, const Item* i2) {
	Item* tmp_i2 = i2, * ret;

	ret = ListCreateEmpty();

	while (!ListIsEmpty(i1)) {
		while (!ListIsEmpty(tmp_i2)) {


		}
	}


}



int main(void) {

	Item* i1, * i2;

	ElemType ii1[] = { 1, 45, 0, 2, 4, 1, 3 };
	ElemType ii2[] = { 7, 45, 3, 2, 5 };

	i1 = ListCreateEmpty();
	i2 = ListCreateEmpty();

	for (int i = 0; i < 7; i++) {
		i1 = ListInsertBack(i1, &ii1[i]);
	}

	for (int i = 0; i < 6; i++) {
		i2 = ListInsertBack(i2, &ii2[i]);
	}

	return 0;
}
