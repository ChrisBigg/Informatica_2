

#include "list.h"

Item* Sort(Item* i) {
	if (i == NULL) {
		return NULL;
	}
	bool crt_sort = false;

	while (!crt_sort) {
		crt_sort = true;
		for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
			if (ElemCompare(tmp->value.name, tmp->next->value.name) == 1) {
				ElemSwap(&tmp->value, &tmp->next->value);
				crt_sort = false;
			}
		}
	}
	return i;

}

