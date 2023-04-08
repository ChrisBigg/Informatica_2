#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

void BabboNataleRec(const int* pacchi, size_t pacchi_size, int p, bool* vcurr, int i, int* nelem, bool* ris) {

	if (i == pacchi_size) {
		int peso = 0;
		int elem = 0;
		for (int j = 0; j < pacchi_size; j++) {
			if (vcurr[j]) {
				peso += pacchi[j];
				elem++;
			}
		}
		// ho il peso più grande
		if (elem > *nelem && peso < p) {
			*nelem = elem;

			for (int j = 0; j < pacchi_size; j++) {
				ris[j] = vcurr[j];
			}
		}


		return;
	}


	vcurr[i] = 0;
	BabboNataleRec(pacchi, pacchi_size, p, vcurr, i + 1, nelem,  ris);

	vcurr[i] = 1;
	BabboNataleRec(pacchi, pacchi_size, p, vcurr, i + 1, nelem, ris);
}




void BabboNatale(const int* pacchi, size_t pacchi_size, int p) {
	if (p < 0) {
		return;
	}
	bool* vcurr = calloc(pacchi_size, sizeof(bool));
	bool* ris = calloc(pacchi_size, sizeof(bool));
	int max = 0, nelem = 0;


	BabboNataleRec(pacchi, pacchi_size, p, vcurr, 0, &nelem, ris);

	for (int j = 0; j < pacchi_size; j++) {
		printf("%i ", ris[j]);

	}
	printf("\n");


	free(ris);
	free(vcurr);
	return;
}
