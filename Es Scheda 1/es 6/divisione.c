
static int DivisioneRec(int a, int b, int ris, int i) {
	if (ris - b < 0) {
		return i;
	}
	ris -= b;

	return DivisioneRec(a, b, ris, i+1);
}

int Divisione(int a, int b) {
	if (a < 0 || b <= 0) {
		return -1;
	}
	if (b == 1) {
		return a;
	}
	int i = 0;

	return DivisioneRec(a, b, a, i);

}


