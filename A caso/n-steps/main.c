
#include <stdlib.h>
#include <stdio.h>


void StepsRec(int n, int i, int* vcurr, int* steps_done) {

	if (*steps_done == n) {
		printf("[");
		for (int x = 0; x < i; x++) {
			printf("%i", vcurr[x]);
			if (x != (i - 1)) {
				printf(", ");
			}
		}
		printf("]\n");


		return;
	}

	if (i == n) {

		return;
	}


	for (int j = 1; j <= 3; j++) {

		vcurr[i] = j;
		*steps_done = 0;

		for (int z = 0; z < i; z++) {
			*steps_done += vcurr[z];
		}
		*steps_done += j;


		if (*steps_done <= n) {
			StepsRec(n, i + 1, vcurr, steps_done);
		}

	}

}


void Steps(int n) {
	if (n < 0) {
		return;
	}

	int* vcurr = malloc(n * sizeof(int));
	int steps_done = 0;

	StepsRec(n, 0, vcurr, &steps_done);
}



int main(void) {

	Steps(3);

	return EXIT_SUCCESS;
}

