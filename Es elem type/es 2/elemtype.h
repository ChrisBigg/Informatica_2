
#ifndef ELEMTYPE_INT_H_
#define ELEMTYPE_INT_H_

#define _CRT_SECURE_NO_WARNINGS
#include <stdbool.h>
#include <stdio.h>

typedef int ElemType;

int ElemCompare(const ElemType* e1, const ElemType* e2);

ElemType ElemCopy(const ElemType* e);

void ElemSwap(ElemType* e1, ElemType* e2);

void ElemDelete(ElemType* e);

int ElemRead(FILE* f, ElemType* e);

int ElemReadStdin(ElemType* e);

void ElemWrite(const ElemType* e, FILE* f);

void ElemWriteStdout(const ElemType* e);

#endif // ELEMTYPE_INT_H_
