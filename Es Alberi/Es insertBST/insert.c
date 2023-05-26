
#include "tree.h"
#include <stdlib.h>

Node* BstInsert(const ElemType* e, Node* n) {
	if (TreeIsEmpty(n)) {
		return TreeCreateRoot(e, NULL, NULL);
	}
	Node* tmp = n, * padre;
	bool crt = true;

	while (crt) {
		padre = tmp;
		if (ElemCompare(e, TreeGetRootValue(tmp)) > 0) {
			tmp = TreeRight(tmp);

			if (ElemCompare(e, TreeGetRootValue(tmp)) < 0) {
				tmp = TreeCreateRoot(e, NULL, TreeRight(padre));
				padre->right = tmp;

				return n;
			}

			if (TreeIsLeaf(tmp)) {
				Node* t = malloc(sizeof(Node));
				t->value = ElemCopy(e);
				t->left = NULL;
				t->right = NULL;
				if (ElemCompare(TreeGetRootValue(tmp), e) < 0) {
					tmp->right = t;
				}
				else {
					tmp->left = t;
				}

				return n;
			}
		}
		else {
			tmp = TreeLeft(tmp);

			if (ElemCompare(e, TreeGetRootValue(tmp)) < 0) {
				tmp = TreeCreateRoot(e, TreeLeft(padre), NULL);
				padre->left = tmp;

				return n;
			}

			if (TreeIsLeaf(tmp)) {
				Node* t = malloc(sizeof(Node));
				t->value = ElemCopy(e);
				t->left = NULL;
				t->right = NULL;
				if (ElemCompare(TreeGetRootValue(tmp), e) < 0) {
					tmp->right = t;
				}
				else {
					tmp->left = t;
				}

				return n;
			}
		}
	}
	return n;
}

void BstInsertRecRec(const ElemType* e, Node* tmp, Node* padre, bool* crt_insert) {
	if (*crt_insert) {
		return;
	}

	padre = tmp;

	if (ElemCompare(e, TreeGetRootValue(tmp)) > 0) {
		tmp = TreeRight(tmp);

		if (ElemCompare(e, TreeGetRootValue(tmp)) < 0) {
			tmp = TreeCreateRoot(e, NULL, TreeRight(padre));
			padre->right = tmp;

			*crt_insert = true;
			return;
		}
	}
	else {

		tmp = TreeLeft(tmp);

		if (ElemCompare(e, TreeGetRootValue(tmp)) < 0) {
			tmp = TreeCreateRoot(e, TreeLeft(padre), NULL);
			padre->left = tmp;

			*crt_insert = true;
			return;
		}
	}

	if (TreeIsLeaf(tmp)) {
		Node* t = malloc(sizeof(Node));
		t->value = ElemCopy(e);
		t->left = NULL;
		t->right = NULL;
		if (ElemCompare(TreeGetRootValue(tmp), e) < 0) {
			tmp->right = t;
		}
		else {
			tmp->left = t;
		}

		*crt_insert = true;
		return;
	}

		BstInsertRecRec(e, tmp, padre, crt_insert);
}



Node* BstInsertRec(const ElemType* e, Node* n) {
	if (TreeIsEmpty(n)) {
		return TreeCreateRoot(e, NULL, NULL);
	}
	Node* tmp = n, * padre = tmp;
	bool crt_insert = false;


	BstInsertRecRec(e, tmp, padre, &crt_insert);

	return n;
}



int main(void) {
	ElemType e = 1;
	Node* tmp, * tmp2;
	Node* left = TreeCreateRoot(&e, NULL, NULL);
	e = 2;
	Node* right = TreeCreateRoot(&e, NULL, NULL);
	e = 1;
	tmp = TreeCreateRoot(&e, left, right);
	e = 3;
	tmp = TreeCreateRoot(&e, tmp, NULL);
	e = 5;
	left = TreeCreateRoot(&e, NULL, NULL);
	e = 9;
	right = TreeCreateRoot(&e, NULL, NULL);
	e = 7;
	tmp2 = TreeCreateRoot(&e, left, right);
	e = 4;
	tmp = TreeCreateRoot(&e, tmp, tmp2);

	e = 12;
	TreeWriteStdoutInOrder(BstInsertRec(&e, tmp));


	return 0;
}