#include "Estate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

Estate* create_estate(char type, char* address, int surface, int price) {
	// Allocate memory for the Estate.
	Estate* E = (Estate*) malloc(sizeof(Estate));

	// Pass attributes to the newly created Estate.
	E->type = type;
	E->address = (char*) malloc(strlen(address) * sizeof(char));
	strcpy(E->address, address);
	E->surface = surface;
	E->price = price;

	// Return the pointer to the Estate.
	return E;
}

int destroy_estate(Estate* E) {
	if (E == NULL)
		return 0;

	free(E->address); // Free the memory of the address.
	free(E);          // Free the Estate.
	return 1;         // Return 1 for success.
}

Estate* copy_estate(Estate* E) {
	if (E == NULL)
		return E;

	// Create an identical Estate and return a pointer to it.
	return create_estate(E->type, E->address, E->surface, E->price);
}

int is_valid_estate(Estate* E) {
	// Check if type is all right.
	if (E->type != 'h' && E->type != 'a' && E->type != 'p')
		return 0;

	// Check if surface is all right.
	if (E->surface <= 0)
		return 0;

	// Check if price is all right.
	if (E->price <= 0)
		return 0;

	// Return 1 for success.
	return 1;
}

int set_estate_type(Estate* E, char new_type) {
	// If type is all right, set it and return 1 for success.
	if (new_type == 'h' || new_type == 'a' || new_type == 'p') {
		E->type = new_type;
		return 1;
	}

	// Return 0 for failure.
	return 0;
}

int set_estate_address(Estate* E, char* new_address) {
	// Rellocate appropriate memory for the new address, set it and return 1 for success.
	E->address = (char*) realloc(E->address, strlen(new_address) * sizeof(char));
	strcpy(E->address, new_address);
	return 1;
}

int set_estate_surface(Estate* E, int new_surface) {
	// If surface is all right, set it and return 1 for success.
	if (new_surface > 0) {
		E->surface = new_surface;
		return 1;
	}

	// Return 0 for failure.
	return 0;
}

int set_estate_price(Estate* E, int new_price) {
	// If price is all right, set it and return 1 for success.
	if (new_price > 0) {
		E->price = new_price;
		return 1;
	}

	// Return 0 for failure.
	return 0;
}

int equals_estate(Estate* A, Estate* B) {
	// Compare every attribute.
	int ok = 1;
	ok &= (A->type == B->type);
	ok &= (strcmp(A->address, B->address) == 0);
	ok &= (A->surface == B->surface);
	ok &= (A->price == B->price);
	return ok;
}

void estate_to_string(Estate* E, char* str) {
	if (E == NULL) {
		strcpy(str, "NULL");
		return;
	}

	char* type = type_from_char(E->type);
	sprintf(str, "%s on %s of %d m^2 at %d EUR.", type, E->address, E->surface, E->price);
	free(type);
}

char* type_from_char(char c) {
	char* type = malloc(10 * sizeof(char));

	switch (c) {
	case 'h':
		strcpy(type, "House");
		break;
	case 'a':
		strcpy(type, "Apartment");
		break;
	case 'p':
		strcpy(type, "Penthouse");
		break;
	default:
		return NULL;
	}

	return type;
}

int cmp_asc_by_price(Estate* A, Estate* B) {
	if (A->price < B->price)
		return -1;
	if (A->price > B->price)
		return +1;
	return 0;
}

int cmp_desc_by_price(Estate* A, Estate* B) {
	if (A->price > B->price)
		return -1;
	if (A->price < B->price)
		return +1;
	return 0;
}

int cmp_asc_by_surface(Estate* A, Estate* B) {
	if (A->surface < B->surface)
		return -1;
	if (A->surface > B->surface)
		return +1;
	return 0;
}

int cmp_desc_by_surface(Estate* A, Estate* B) {
	if (A->surface > B->surface)
		return -1;
	if (A->surface < B->surface)
		return +1;
	return 0;
}

int flt_contains_str_in_address(Estate* A, void* str) {
	return strstr(A->address, (char*) str) != NULL;
}

int flt_is_of_type(Estate* A, void* type) {
	return A->type == *((char*) type);
}

int flt_is_not_of_type(Estate* A, void* not_type) {
	return A->type != *((char*) not_type);
}

int flt_has_surface_greater_than(Estate* A, void* min_surface) {
	return A->surface >= *((int*) min_surface);
}

int flt_has_price_less_than(Estate* A, void* max_price) {
	return A->price <= *((int*) max_price);
}
