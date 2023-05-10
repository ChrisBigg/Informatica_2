
#include "list.h"

const ElemType* MaxElement(const Item* i) {
	const ElemType* pnt_max = &i->value;

	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (ElemCompare(&tmp->value, pnt_max) > 0) {
			pnt_max = &tmp->value;
		}
	}

	return pnt_max;
}
