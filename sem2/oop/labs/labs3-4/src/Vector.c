#include "Vector.h"
#include "Estate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Vector* create_vector() {
	Vector* V = (Vector*) malloc(sizeof(Vector));

	V->arr = (Estate**) malloc(1 * sizeof(Estate*));
	V->length = 0;
	V->capacity = 1;

	return V;
}

int destroy_vector(Vector* V) {
	int i;
	for (i = 0; i < V->length; i++)
		destroy_estate(V->arr[i]);

	free(V->arr);
	free(V);

	return 1;
}

int add_in_vector(Vector* V, Estate* O) {
	if (V->length == V->capacity)
		expand_vector(V);

	V->arr[V->length] = O;
	V->length++;

	return 1;
}

Estate* at_position(Vector* V, int pos) {
	if (pos < 0 || pos >= V->length)
		return NULL;

	return V->arr[pos];
}

int remove_from_vector_at_position(Vector* V, int pos) {
	if (pos < 0 || pos >= V->length)
		return 0;

	destroy_estate(at_position(V, pos));

	V->length--;
	int i;
	for (i = pos; i < V->length; i++)
		V->arr[i] = V->arr[i + 1];

	return 1;
}

int expand_vector(Vector* V) {
	V->capacity *= 2;
	V->arr = (Estate**) realloc(V->arr, V->capacity * sizeof(Estate*));
	return 1;
}

Vector* copy_vector(Vector* V) {
	Vector* dest = create_vector();
	int i;
	for (i = 0; i < V->length; i++)
		add_in_vector(dest, copy_estate(V->arr[i]));
	return dest;
}

Vector* sort(Vector* V, int (*cmp)(Estate* A, Estate* B)) {
	Vector* sorted = copy_vector(V);
	int i, j;

	for (i = 0; i < sorted->length; i++)
		for (j = i + 1; j < sorted->length; j++)
			if (cmp(sorted->arr[i], sorted->arr[j]) > 0) {
				Estate* aux = sorted->arr[i];
				sorted->arr[i] = sorted->arr[j];
				sorted->arr[j] = aux;
			}

	return sorted;
}

Vector* filter(Vector* V, int (*flt)(Estate* A, void* param), void* param) {
	Vector* filtered = create_vector();
	int i;

	for (i = 0; i < V->length; i++)
		if (flt(at_position(V, i), param))
			add_in_vector(filtered, copy_estate(at_position(V, i)));

	return filtered;
}
