#include <stdlib.h>
#include <stdio.h>

void StazioniRec(int* d, int* p, int tot, int* vcurr, int n, int i, double* soldi, double* soldimax, int* ris, double* vserb) {

	// controllo benzina e consumo
	if (i == 0) {
		//consumo gratis
		vserb[i] = 30 - d[i] * 0.05;
	}
	else {
		if (vcurr[i - 1] == 1) {
			// faccio riformineto
			vserb[i] = 30 - d[i] * 0.05;
		}
		else {
			vserb[i] = vserb[i - 1] - d[i] * 0.05;
		}
	}

	if (vserb[i] < 0) {
		*soldi = 0;
		return;
	}

	if (i == n) {

		// se è negativo esco
		for (int j = 0; j < 5; j++) {
			if (vcurr[j] == 1) {
				*soldi += (30 - vserb[j]) * p[j];
			}
		}

		if (*soldi < *soldimax) {
			*soldimax = *soldi;
			for (int j = 0; j < 5; j++) {
				ris[j] = vcurr[j];
			}
		}
		else {
			return;
		}

		*soldi = 0;
		return;
	}


	vcurr[i] = 0;
	StazioniRec(d, p, tot, vcurr, n, i + 1, soldi, soldimax, ris, vserb);

	vcurr[i] = 1;
	StazioniRec(d, p, tot, vcurr, n, i + 1, soldi, soldimax, ris, vserb);
}




int main(void) {
	int d[5] = { 260,284,308,332,356 };
	int p[5] = { 35,35,33,29,23 };
	int disttot = 1540;
	int* vcurr = malloc(5 * sizeof(int));
	int* ris = calloc(5, sizeof(int));
	double* vserb = calloc(5, sizeof(double));
	double soldi = 0, soldimax = 999999999;


	StazioniRec(d, p, 1540, vcurr, 5, 0, &soldi, &soldimax, ris, vserb);

	// stampo
	printf("ris:\n");
	for (int j = 0; j < 5; j++) {
		printf("%i ", ris[j]);
	}
	printf("soldi: %.1f\n", soldimax);


	return EXIT_SUCCESS;
}