static int min(int a, int b) {
	if (a > b) {
		return b;
	}
		return a;
}

int Minimo(const int* v, int v_size) {
	// caso base
	if (v_size == 1) {
		return v[0];
	}



	return min(v[v_size-1], Minimo(v, v_size-1));
}
