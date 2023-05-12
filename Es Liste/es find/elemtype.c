#define _CRT_SECURE_NO_WARNINGS
#include "elemtype.h"

#include <string.h>
#include <stdlib.h>

#define _unused(x) ((void)(x))

int ElemCompare(const ElemType* e1, const ElemType* e2) {
	return strcmp(e1->name, e2->name);
}

ElemType ElemCopy(const ElemType* e) {
	ElemType ris;
	strcpy(ris.name, e->name);
	strcpy(ris.street, e->street);
	ris.number = e->number;
	strcpy(ris.city, e->city);
	strcpy(ris.province, e->province);
	strcpy(ris.postal_code, e->postal_code);
	return ris;

}

void ElemSwap(ElemType* e1, ElemType* e2) {
	ElemType tmp;
	strcpy(tmp.name, e1->name);
	strcpy(tmp.street, e1->street);
	tmp.number = e1->number;
	strcpy(tmp.city, e1->city);
	strcpy(tmp.province, e1->province);
	strcpy(tmp.postal_code, e1->postal_code);

	strcpy(e1->name, e2->name);
	strcpy(e1->street, e2->street);
	e1->number = e2->number;
	strcpy(e1->city, e2->city);
	strcpy(e1->province, e2->province);
	strcpy(e1->postal_code, e2->postal_code);

	strcpy(e2->name, tmp.name);
	strcpy(e2->street, tmp.street);
	e2->number = tmp.number;
	strcpy(e2->city, tmp.city);
	strcpy(e2->province, tmp.province);
	strcpy(e2->postal_code, tmp.postal_code);
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