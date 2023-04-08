#include <limits.h>
#include <math.h>

int DivisioneNegativiRec(int a, int b, int ris, int i) {
	if (ris - b < 0) {
		return i;
	}
	ris -= b;

	return DivisioneNegativiRec(a, b, ris, i + 1);

}


int DivisioneNegativi(int a, int b) {
	if (b == 0) {
		return INT_MAX;
	}
	int i = 0;

	if ((a < 0 && b > 0) || (a > 0 && b < 0)) {
		return DivisioneNegativiRec(abs(a), abs(b), abs(a), i) * (-1);
	}
	return DivisioneNegativiRec(abs(a), abs(b), abs(a), i);


}
