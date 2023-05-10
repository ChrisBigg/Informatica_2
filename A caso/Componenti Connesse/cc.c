

#include "cc.h"


int ComponentiConnesse(const Item* i, const ElemType* v, size_t v_size) {
	if (i == NULL || v == NULL) {
		return 0;
	}

	int cnt = 0;
	const ElemType* pnt_start, * pnt_end;
	bool in_vector = false;

	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		in_vector = false;

		for (int v_index = 0; v_index < v_size; v_index++) {

			if (ElemCompare(&v[v_index], &tmp->value) == 0 && !in_vector) {
				pnt_start = tmp;
				in_vector = true;
				break;
			}
		}
		
		if (!in_vector) {
			pnt_end = tmp;
			cnt++;
		}

	}
}
