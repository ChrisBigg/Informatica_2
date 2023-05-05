#define _CRT_SECURE_NO_WARNINGS 
#include <stdlib.h>
#include <stdio.h>
#include "list.h"

Item* ListLoad(const char* filename) {
	Item* list;
	list = ListCreateEmpty();

	if (filename == NULL) {
		return list;
	}

	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return list;
	}

	int crt_read, elem;
	crt_read = fscanf(f, "%i", &elem);

	while (crt_read == 1) {
		list = ListInsertHead(&elem, list);

		crt_read = fscanf(f, "%i", &elem);
	}


	return list;
}




//int main(void) {
//	ListLoad("data_00.txt");
//
//
//	return EXIT_SUCCESS;
//}