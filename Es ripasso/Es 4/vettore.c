
#include "vettore.h"


void Push(struct vettore* v, int d) {
	v->data = realloc(v->data, (v->size + 1) * sizeof(int));
	v->data[v->size] = d;
	v->size++;
}
int Pop(struct vettore* v){
	int elem = v->data[0];

	for (int i = 0; i < (v->size) - 1; ++i) {
		v->data[i] = v->data[i + 1];
	}
	v->data = realloc(v->data, --(v->size) * sizeof(int));
	return elem;

}