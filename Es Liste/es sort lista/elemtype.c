#define _CRT_SECURE_NO_WARNINGS
#include "elemtype.h"

#include <string.h>
#include <stdlib.h>

#define _unused(x) ((void)(x))

int ElemCompare(const ElemType* e1, const ElemType* e2) {
	return strcmp(e1->name, e2->name);
}

ElemType ElemCopy(const ElemType* e) {
	return *e;
}

void ElemSwap(ElemType* e1, ElemType* e2) {
	ElemType tmp= *e1;
	*e1 = *e2;
	*e2 = tmp;
}

void ElemDelete(ElemType* e) {
	// In questo caso la funzione ElemDelete non deve fare nulla, ma il 
	// compilatore potrebbe segnalare il mancato utilizzo di e, come warning
	// o come errore. Utilizzando la macro _unused sopra definita eliminiamo
	// questo problema.
	_unused(e);
}

int ElemRead(FILE* f, ElemType* e) {
	int ris = fscanf(f, "%s %s %i %s %s %s", e->name, e->street, &e->number, e->city, e->province, e->postal_code);
	if (ris == 6) {
		return 1;
	}
	else {
		if (ris == EOF) {
			return ris;
		}
		else {
			return 0;
		}
	}
}


int ElemReadStdin(ElemType *e) {
    return ElemRead(stdin, e);
}

void ElemWrite(const ElemType *e, FILE *f) {
    fprintf(f, "%s %s %i %s %s %s", e->name, e->street, e->number, e->city, e->province, e->postal_code);
}

void ElemWriteStdout(const ElemType *e) {
    ElemWrite(e, stdout);
}