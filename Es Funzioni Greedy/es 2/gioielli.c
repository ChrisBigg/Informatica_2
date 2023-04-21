

#include "gioielli.h"

Gioiello* CompraGioielli(const char* filename, float budget, size_t* ret_size) {
	if (budget <= 0 || filename == NULL) {
		return NULL;

	}

	FILE* f = fopen(filename, "r");

	if (f == NULL) {
		return NULL;
	}

	int dim_ap = 1, size_ap = 0;
	float* ap_gioielli = malloc(dim_ap * sizeof(float));
	int dim_gio = 1, size_gio = 0;
	Gioiello* gioielli = malloc(dim_gio * sizeof(Gioiello));

	int crt;

	crt = fscanf(f, "%i %f %f\n", &gioielli[size_gio].codice, &gioielli[size_gio].peso, &gioielli[size_gio].prezzo);

	while (crt == 3) {
		size_gio++;

		if (dim_ap <= size_ap) {
			dim_ap *= 2;
			ap_gioielli = realloc(ap_gioielli, dim_ap * sizeof(float));
		}

		ap_gioielli[size_ap] = gioielli[size_ap].peso / gioielli[size_ap].prezzo;
		size_ap++;

		if (dim_gio <= size_gio) {
			dim_gio *= 2;
			gioielli = realloc(gioielli, dim_gio * sizeof(Gioiello));
		}
		crt = fscanf(f, "%i %f %f\n", &gioielli[size_gio].codice, &gioielli[size_gio].peso, &gioielli[size_gio].prezzo);
	}
	ap_gioielli = realloc(ap_gioielli, size_ap * sizeof(float));
	gioielli = realloc(gioielli, size_gio * sizeof(Gioiello));

	Gioiello* ret = malloc(size_ap * sizeof(Gioiello));
	int i_ret = 0;

	int* indici = calloc(size_ap, sizeof(int));
	int i_indici = 0;

	for (int j = 0; j < size_ap; j++) {
		if (ap_gioielli[indici[i_indici]] > ap_gioielli[j]) {
			indici[i_indici] = j;
		}
	}

	for (int j = 0; j < size_ap; j++) {
		if()

	}


	for (int i = 0; i < size_gio; i++) {

		// trovo la migliore
		int best_j = 0;


		for (int j = 0; j < size_ap; j++) {
			if (gioielli[best_j].peso == -1) {
				best_j = j
			}
			if (ap_gioielli[best_j] > ap_gioielli[j] && gioielli[j].peso != -1) {
				best_j = j;
			}

		}

		if (budget >= gioielli[best_j].prezzo) {
			budget -= gioielli[best_j].prezzo;
			ret[i_ret].codice = gioielli[best_j].codice;
			ret[i_ret].prezzo = gioielli[best_j].prezzo;
			ret[i_ret].peso = gioielli[best_j].peso;
			gioielli[best_j].peso = -1;

			i_ret++;
		}

	}

	return ret;


}
