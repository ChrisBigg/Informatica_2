#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

void OmbrelloniRec(int k, int n, bool* vcurr, int i, int* nsol, int nelem) {
	if (nelem == k) {
		for (int j = 0; j < n - 1; j++) {
			if (vcurr[j]) {
				if (vcurr[j + 1]) {
					// sbagliata
					return;
				}
			}
		}
		// giusta
		(*nsol)++;
		printf("%i) ", *nsol);
		for (int z = 0; z < n; z++) {
			printf("%i ", vcurr[z]);
		}
		printf("\n");


		return;
	}

	if (i == n) {
		return;
	}


	vcurr[i] = 0;
	OmbrelloniRec(k, n, vcurr, i + 1, nsol, nelem);

	vcurr[i] = 1;
	OmbrelloniRec(k, n, vcurr, i + 1, nsol, nelem + 1);
	vcurr[i] = 0;

}


int Ombrelloni(int k, int n) {
	int nsol = 0;
	bool* vcurr = calloc(n, sizeof(bool));

	if (k < 0 || n < 0 || (n - k < k)) {
		return 0;
	}

	OmbrelloniRec(k, n, vcurr, 0, &nsol, 0);

	free(vcurr);
	return nsol;
}
