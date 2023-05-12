
#include "list.h"

Item* Delete(Item* i, const char* name) {
	if (i == NULL) {
		return i;
	}
	Item* pnt_back = i, * pnt_actual = i;

	for (Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {

		if (strcmp(tmp->value.name, name) == 0) {
			pnt_actual = tmp;
			break;
		}
		else {
			pnt_back = tmp;
		}
	}
	if (pnt_actual != i) {
		pnt_back->next = pnt_actual->next;
		ListDelete(pnt_actual);
	}

	return i;

}



