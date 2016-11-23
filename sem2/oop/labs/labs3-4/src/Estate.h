#ifndef ESTATE_H_
#define ESTATE_H_

typedef struct {
	// type can be 'h' for house, 'a' for apartment, 'p' for penthouse
	char type;

	// address of the estate
	char* address;

	// surface of the estate
	int surface;

	// price of the estate
	int price;
} Estate;

/* Creates an Estate.
 * param: type - type of the estate
 * param: *address - pointer to the string corresponding to the address of the estate
 * param: surface - positive integer indicating the surface of the estate
 * param: price - positive integer indicating the price of the estate
 * return: *pointer to the Estate */
Estate* create_estate(char type, char* address, int surface, int price);

/* Destroys an Estate.
 * param: *E - pointer to the new Estate
 * return: 1 if successful, 0 otherwise */
int destroy_estate(Estate* E);

/* Copies an Estate.
 * param: *E - pointer to the Estate
 * return: *pointer to the copied Estate */
Estate* copy_estate(Estate* E);

/* Checks if an Estate has valid attributes.
 * param: *E - pointer to the Estate
 * return: 1 if valid, 0 otherwise */
int is_valid_estate(Estate* E);

/* Sets a new type to the estate.
 * param: *E - pointer to the Estate
 * param: new_type - type of the estate ('h', 'a' or 'p')
 * return: 1 if successful, 0 otherwise */
int set_estate_type(Estate* E, char new_type);

/* Sets a new address to the estate.
 * param: *E - pointer to the Estate
 * param: *new_address - pointer to the string corresponding to the address of the estate
 * return: 1 if successful, 0 otherwise */
int set_estate_address(Estate* E, char* new_address);

/* Sets a new surface to the estate.
 * param: *E - pointer to the Estate
 * param: new_surface - positive integer indicating the surface of the estate
 * return: 1 if successful, 0 otherwise */
int set_estate_surface(Estate* E, int new_surface);

/* Sets a new price to the estate.
 * param: *E - pointer to the Estate
 * param: new_price - positive integer indicating the price of the estate
 * return: 1 if successful, 0 otherwise */
int set_estate_price(Estate* E, int new_price);

/* Checks whether two Estates are "equal" i.e. have the same attributes.
 * param: *A - pointer to an Estate
 * param: *B - pointer to an Estate
 * return: 1 if equal, 0 otherwise */
int equals_estate(Estate* A, Estate* B);

/* Represents an Estate as a string.
 * param: *E - pointer to the Estate
 * param: *str - *pointer to the string */
void estate_to_string(Estate* E, char* str);

/* Returns the full name of a type given by its first character.
 * param: c - char which is 'h', 'p' or 'a'
 * return: *pointer to the string or NULL if c is invalid */
char* type_from_char(char c);

int cmp_asc_by_price(Estate* A, Estate* B);
int cmp_desc_by_price(Estate* A, Estate* B);
int cmp_asc_by_surface(Estate* A, Estate* B);
int cmp_desc_by_surface(Estate* A, Estate* B);
int flt_contains_str_in_address(Estate* A, void* str);
int flt_is_of_type(Estate* A, void* type);
int flt_is_not_of_type(Estate* A, void* not_type); //!!!
int flt_has_surface_greater_than(Estate* A, void* min_surface);
int flt_has_price_less_than(Estate* A, void* max_price); //!!!

void test_estate();
void test_create_estate();
void test_is_valid_estate();
void test_setters_estate();
void test_equals_estate();

#endif
