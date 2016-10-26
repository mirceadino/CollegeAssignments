#include "Controller.h"
#include "OperationStack.h"
#include "Repository.h"
#include "Vector.h"
#include "Estate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Controller* create_controller(Repository* R) {
	Controller* C = (Controller*) malloc(sizeof(Controller));
	C->repo = R;
	C->stack = create_operation_stack();
	return C;
}

int destroy_controller(Controller* C) {
	destroy_operation_stack(C->stack);
	free(C);
	return 1;
}

int add_estate(Controller* C, char type, char* address, int surface, int price) {
	Estate* O = create_estate(type, address, surface, price);
	if (is_valid_estate(O))
		if (add_in_repository(C->repo, O)) {
			add_operation(C->stack, create_operation(NULL, O));
			return 1;
		}
	destroy_estate(O);
	return 0;
}

int remove_estate(Controller* C, char* addr) {
	Estate* O = find_in_repository_by_address(C->repo, addr);
	if (O != NULL)
		add_operation(C->stack, create_operation(O, NULL));
	return remove_from_repository_at_address(C->repo, addr);
}

int update_estate(Controller* C, char* address, char new_type, char* new_address, int new_surface, int new_price) {
	Estate* O = find_in_repository_by_address(C->repo, address);

	if (O == NULL)
		return 0;

	Estate* aux = create_estate(new_type, new_address, new_surface, new_price);
	if (!is_valid_estate(aux)) {
		destroy_estate(aux);
		return 0;
	}
	destroy_estate(aux);

	aux = find_in_repository_by_address(C->repo, new_address);
	if (aux != NULL && aux != O)
		return 0;

	Estate* old = copy_estate(O);

	set_estate_type(O, new_type);
	set_estate_address(O, new_address);
	set_estate_surface(O, new_surface);
	set_estate_price(O, new_price);

	add_operation(C->stack, create_operation(old, O));

	destroy_estate(old);

	return 1;
}

Vector* display_contains_str_in_address_asc_by_price(Controller* C, char* str) {
	Vector* all = get_all_estates(C->repo);
	Vector* filtered = filter(all, flt_contains_str_in_address, (void*) str);
	Vector* sol = sort(filtered, cmp_asc_by_price);
	destroy_vector(all);
	destroy_vector(filtered);
	return sol;
}

Vector* display_is_not_of_type_has_price_less_than_asc_by_price(Controller* C, char not_type, int max_price) {
	Vector* all = get_all_estates(C->repo);
	Vector* filtered = filter(all, flt_is_not_of_type, (void*) (&not_type));
	Vector* cheap = filter(filtered, flt_has_price_less_than, (void*) (&max_price));
	Vector* sol = sort(cheap, cmp_asc_by_price);
	destroy_vector(all);
	destroy_vector(filtered);
	destroy_vector(cheap);
	return sol;
}

Vector* display_is_of_type_has_greater_surface_than(Controller* C, char type, int min_surface, int ascending) {
	Vector* all = get_all_estates(C->repo);
	Vector* sorted;

	if (ascending)
		sorted = sort(all, cmp_asc_by_surface);
	else
		sorted = sort(all, cmp_desc_by_surface);

	Vector* filtered = filter(sorted, flt_is_of_type, (void*) (&type));
	Vector* sol = filter(filtered, flt_has_surface_greater_than, (void*) (&min_surface));
	destroy_vector(all);
	destroy_vector(sorted);
	destroy_vector(filtered);
	return sol;
}

int undo(Controller* C) {
	Operation* O = prev_operation(C->stack);

	if (O == NULL)
		return 0;

	/*char buffer[40];
	 estate_to_string(O->initial, buffer);
	 printf("%s -> ", buffer);
	 estate_to_string(O->final, buffer);
	 printf("%s\n", buffer);*/

	if (O->initial == NULL) {
		remove_from_repository_at_address(C->repo, O->final->address);
		return 1;
	} else if (O->final == NULL) {
		add_in_repository(C->repo, copy_estate(O->initial));
		return 1;
	} else {
		Estate* A = find_in_repository_by_address(C->repo, O->final->address);
		set_estate_type(A, O->initial->type);
		set_estate_address(A, O->initial->address);
		set_estate_surface(A, O->initial->surface);
		set_estate_price(A, O->initial->price);
		return 1;
	}
}

int redo(Controller* C) {
	Operation* O = next_operation(C->stack);

	if (O == NULL)
		return 0;

	if (O->initial == NULL) {
		add_in_repository(C->repo, copy_estate(O->final));
		return 1;
	} else if (O->final == NULL) {
		remove_from_repository_at_address(C->repo, O->initial->address);
		return 1;
	} else {
		Estate* A = find_in_repository_by_address(C->repo, O->initial->address);
		set_estate_type(A, O->final->type);
		set_estate_address(A, O->final->address);
		set_estate_surface(A, O->final->surface);
		set_estate_price(A, O->final->price);
		return 1;
	}
}
