
#include "list.h"

const ElemType* Find(const Item* i, const char* name) {
	if (i == NULL) {
		return NULL;
	}

	for (const Item* tmp = i; !ListIsEmpty(tmp); tmp = ListGetTail(tmp)) {
		if (strcmp(tmp->value.name, name) == 0) {
			return &tmp->value;
		}

	}
	return NULL;
}

//int main(void) {
//	return 0;
//}