#include <stdlib.h>
#include "list.h"


Item* Intersect(const Item* i1, const Item* i2) {
	Item* tmp_i2 = i2, * ret;

	ret = ListCreateEmpty();

	while (!ListIsEmpty(i1)) {
		while (!ListIsEmpty(tmp_i2)) {

			if (tmp_i2->value == i1->value) {
				ret = ListInsertBack(ret, &i1->value);

				break;
			}
			tmp_i2 = ListGetTail(tmp_i2);
		}

		tmp_i2 = i2;
		i1 = ListGetTail(i1);
	}

	return ret;
}




//int main(void) {
//
//
//	Item* i1, * i2;
//
//	ElemType ii1[] = { 3, 4, 2, 0, 45, 1, 3 };
//	ElemType ii2[] = { 8, 5, 2, 3, 45, 7 };
//
//	i1 = ListCreateEmpty();
//	i2 = ListCreateEmpty();
//
//	for (int i = 0; i < 7; i++) {
//		i1 = ListInsertHead(&ii1[i], i1);
//	}
//
//	for (int i = 0; i < 6; i++) {
//		i2 = ListInsertHead(&ii2[i], i2);
//	}
//
//	Intersect(i1, i2);
//
//	return 0;
//}