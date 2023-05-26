
#include "tree.h"
#include <stdlib.h>

void CountDominantRec(int* count, const Node* tmp) {
	if (TreeIsLeaf(tmp)) {
		return;
	}

	if (*TreeGetRootValue(tmp) > *TreeGetRootValue(tmp->left) + *TreeGetRootValue(tmp->right)) {
		*count += 1;
	}

	CountDominantRec(count, TreeLeft(tmp));
	CountDominantRec(count, TreeRight(tmp));

}



int CountDominant(const Node* t) {
	if (TreeIsEmpty(t)) {
		return 0;
	}
	const Node* tmp = t;
	int count = 0;

	CountDominantRec(&count, tmp);
	return count;
}


//int main(void) {
//
//
//
//
//	return 0;
//}