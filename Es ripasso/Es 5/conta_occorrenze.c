#define	_CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int ContaOccorrenze(const char* filename, const char* str) {
	if (filename == NULL || str == NULL) {
		return 0;
	}
	FILE* f = fopen(filename, "r");
	if (f == NULL) {
		return 0;
	}
	char parola[99];
	int crt, count = 0;

	crt = fscanf(f, "%s", parola);
	while (crt == 1) {
		if (strcmp(parola, str) == 0) {
			count++;
		}

		crt = fscanf(f, "%s", parola);

	}

	fclose(f);

	return count;
}
