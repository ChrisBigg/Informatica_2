
#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>


void SottoinsiemiRec(int n, int* v, int i, int* vcurr, int* diff_min, int* ris) {

	if (i == n) {
		int somma1 = 0, somma2 = 0;

		for (int j = 0; j < n; j++) {
			if (j < (n / 2)) {
				somma1 += vcurr[j];
			}
			else {
				somma2 += vcurr[j];
			}
		}

		if (abs(somma1 - somma2) < *diff_min) {
			*diff_min = abs(somma1 - somma2);
			for (int j = 0; j < n; j++) {
				ris[j] = vcurr[j];
			}
		}

		return;
	}

	for (int j = 0; j < n; j++) {
		vcurr[i] = v[j];
		bool crt = true;

		for (int z = 0; z < i; z++) {
			if (v[j] == vcurr[z]) {
				crt = false;
				break;
			}
		}

		if (crt) {
			SottoinsiemiRec(n, v, i + 1, vcurr, diff_min, ris);
		}


	}

}


int main(int argc, char** argv) {

	if (argc <= 1) {
		return EXIT_FAILURE;
	}

	int* vcurr = malloc((argc - 1) * sizeof(int));
	int* ris = malloc((argc - 1) * sizeof(int));
	int diff_min = 999999999;

	int* v = malloc((argc - 1) * sizeof(int));
	for (int i = 1; i < argc; i++) {
		v[i - 1] = atoi(argv[i]);
	}

	SottoinsiemiRec(argc - 1, v, 0, vcurr, &diff_min, ris);
	printf("{ ");

	for (int j = 0; j < (argc - 1); j++) {

		if (j < ((argc - 1) / 2)) {
			printf("%i, ", ris[j]);
		}

		if (j == (argc - 1) / 2) {
			printf("}, {");
		}

		if (!(j < ((argc - 1) / 2))) {
			printf("%i, ", ris[j]);
		}

	}
	printf("}");


	free(v);
	free(vcurr);
	free(ris);

	return EXIT_SUCCESS;
}