
#include "torrecartoni.h"

void TorreCartoniRec(const Cartone* c, size_t n, int* ris, int* vcurr, int i, int altezza, int* top_altezza, int* elem) {


	altezza = 0;
	for (int j = 0; j < i; j++) {
		altezza += c[vcurr[j]].a;
	}

	if (altezza > *top_altezza) {
		*top_altezza = altezza;
		*elem = i;
		for (int j = 0; j < i; j++) {
			ris[j] = vcurr[j];
		}
	}

	if (i == n) {
		return;
	}

	for (int j = 0; j < n; j++) {
		vcurr[i] = j;

		bool crt = true;
		int peso = 0;

		// per i == 0 sempre ricorsione
		if (i == 0) {
			TorreCartoniRec(c, n, ris, vcurr, i + 1, altezza, top_altezza, elem);
		}
		else {

			// controllo doppioni
			for (int z = 0; z < i; z++) {

				if (j == vcurr[z]) {
					crt = false;
					break;
				}
			}

			// controllo il peso e limite
			// considero la scatola più bassa e guardo il suo limite
			if (crt) {
				for (int x = i; x >= 0; x--) {
					peso = 0;
					// calcolo il peso delle scatole sopra
					for (int z = x - 1; z >= 0; z--) {
						peso += c[vcurr[z]].p;
					}

					if (peso > c[vcurr[x]].l) {
						crt = false;
						break;
					}
				}
			}

			if (crt) {
				TorreCartoniRec(c, n, ris, vcurr, i + 1, altezza, top_altezza, elem);
			}
		}
	}

}



void TorreCartoni(const Cartone* c, size_t n) {
	int* vcurr = malloc(n * sizeof(int));
	int* ris = malloc(n * sizeof(int));
	int top_altezza = 0, elem = 0;



	TorreCartoniRec(c, n, ris, vcurr, 0, 0, &top_altezza, &elem);

	for (int j = 0; j < elem; j++) {
		printf("%i \n", ris[j]);
	}

	printf("Altezza: %i cm\n", top_altezza);

	free(vcurr);
	free(ris);


}
