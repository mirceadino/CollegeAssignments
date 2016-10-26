#include "Repository.h"
#include "Vector.h"
#include "Estate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Repository* create_repository() {
	Repository* R = (Repository*) malloc(sizeof(Repository));
	R->estates = create_vector();
	R->size = 0;
	return R;
}

int destroy_repository(Repository* R) {
	destroy_vector(R->estates);
	free(R);
	return 1;
}

int add_in_repository(Repository* R, Estate* O) {
	if (find_in_repository_by_address(R, O->address) == NULL) {
		add_in_vector(R->estates, O);
		R->size++;
		return 1;
	}
	return 0;
}

int remove_from_repository_at_address(Repository* R, char* address) {
	int i;
	for (i = 0; i < R->estates->length; i++)
		if (strcmp(at_position(R->estates, i)->address, address) == 0) {
			remove_from_vector_at_position(R->estates, i);
			return 1;
		}
	return 0;
}

int find_in_repository(Repository* R, Estate* O) {
	int i;
	for (i = 0; i < R->estates->length; i++)
		if (equals_estate(at_position(R->estates, i), O) == 1)
			return 1;
	return 0;
}

Estate* find_in_repository_by_address(Repository* R, char* address) {
	int i;
	for (i = 0; i < R->estates->length; i++)
		if (strcmp(at_position(R->estates, i)->address, address) == 0)
			return at_position(R->estates, i);
	return NULL;
}

Vector* get_all_estates(Repository* R) {
	return copy_vector(R->estates);
}
