#include "OperationStack.h"
#include "Estate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Operation* create_operation(Estate* initial, Estate* final) {
	Operation* O = (Operation*) malloc(sizeof(Operation));
	O->initial = copy_estate(initial);
	O->final = copy_estate(final);
	return O;
}

int destroy_operation(Operation* O) {
	destroy_estate(O->initial);
	destroy_estate(O->final);
	free(O);
	return 1;
}

/***************************************/

OperationStack* create_operation_stack() {
	OperationStack* S = (OperationStack*) malloc(sizeof(OperationStack));
	S->operations = (Operation**) malloc(100 * sizeof(Operation*));
	S->size = 0;
	S->current = -1;
	return S;
}

int destroy_operation_stack(OperationStack* S) {
	int i;
	for (i = 0; i < S->size; i++)
		destroy_operation(S->operations[i]);
	free(S->operations);
	free(S);
	return 1;
}

int add_operation(OperationStack* S, Operation* O) {
	int i;
	for (i = S->current + 1; i < S->size; i++)
		destroy_operation(S->operations[i]);
	S->current += 1;
	S->size = S->current + 1;
	S->operations[S->current] = O;
	return 1;
}

Operation* prev_operation(OperationStack* S) {
	if (S->current == -1)
		return NULL;
	return S->operations[S->current--];
}

Operation* next_operation(OperationStack* S) {
	if (S->current + 1 == S->size)
		return NULL;
	return S->operations[++S->current];
}
