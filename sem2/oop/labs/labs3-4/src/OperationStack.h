#ifndef OPERATIONSTACK_H_
#define OPERATIONSTACK_H_

#include "Estate.h"

typedef struct {
	Estate* initial;
	Estate* final;
} Operation;

Operation* create_operation(Estate* initial, Estate* final);
int destroy_operation(Operation* O);

/***************************************/

typedef struct {
	Operation** operations;
	int size;
	int current;
} OperationStack;

OperationStack* create_operation_stack();
int destroy_operation_stack(OperationStack* S);
int add_operation(OperationStack* S, Operation* O);
Operation* prev_operation(OperationStack* S);
Operation* next_operation(OperationStack* S);

#endif
