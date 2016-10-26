#ifndef CONTROLLER_H_
#define CONTROLLER_H_

#include "OperationStack.h"
#include "Repository.h"
#include "Vector.h"
#include "Estate.h"

typedef struct {
	// repository to be controlled
	Repository* repo;
	OperationStack* stack;

} Controller;

/* Creates a controller for a repository.
 * param: *R - pointer to the Repository
 * return: *pointer to the Controller */
Controller* create_controller(Repository* R);

/* Destroys a Controller.
 * param: *C - pointer to the Controller
 * return: 1 if successful, 0 otherwise */
int destroy_controller(Controller* C);

/* Controls adding an estate in the repository.
 * param: *C - pointer to the Controller
 * param: type - type of the estate ('h', 'a' or 'p')
 * param: *address - pointer to the string corresponding to the address of the estate
 * param: surface - positive integer indicating the surface of the estate
 * param: price - positive integer indicating the price of the estate
 * return: 1 if successful, 0 otherwise (if there is already an Estate with the same address or Estate is invalid)*/
int add_estate(Controller* C, char type, char* address, int surface, int price);

/* Controls removing an estate with a given address from the repository.
 * param: *C - pointer to the Controller
 * param: *address - pointer to the string corresponding to the address of the estate
 * return: 1 if successful, 0 otherwise (if there is no estate with such address) */
int remove_estate(Controller* C, char* address);

/* Controls updating information about an estate from the repository.
 * param: *C - pointer to the Controller
 * param: *address - pointer to the string corresponding to the address of the estate
 * param: new_type - new type of the estate ('h', 'a' or 'p')
 * param: *new_address - pointer to the string corresponding to the new address of the estate
 * param: new_surface - positive integer indicating the new surface of the estate
 * param: new_price - positive integer indicating the new price of the estate
 * return: 1 if successful, 0 otherwise (if address is invalid, there is already an Estate with the same new_address or attributes are invalid)*/
int update_estate(Controller* C, char* address, char new_type, char* new_address, int new_surface, int new_price);

/* Returns a Vector with estates containing a sequence as substring in address, sorted ascendingly by price.
 * param: *C - pointer to the Controller
 * param: *str - pointer to the substring
 * return: *pointer to the Vector of corresponding estates */
Vector* display_contains_str_in_address_asc_by_price(Controller* C, char* str);

Vector* display_is_not_of_type_has_price_less_than_asc_by_price(Controller* C, char not_type, int max_price);

/* Returns a Vector with estates of certain type, having surface greater than a given value.
 * param: *C - pointer to the Controller
 * param: type - char specifying the type
 * param: min_surface - minimal value of estates' surface
 * param: ascending - 1 if values should be sorted ascendingly by surface or 0 descendingly
 * return: *pointer to the Vector of corresponding estates */
Vector* display_is_of_type_has_greater_surface_than(Controller* C, char type, int min_surface, int ascending);

/* Undoes the last modification over the controller's repository.
 * param: *C - pointer to the Controller
 * return: 1 if successful, 0 otherwise */
int undo(Controller* C);

/* Redoes the last undo over the controller's repository.
 * param: *C - pointer to the Controller
 * return: 1 if successful, 0 otherwise */
int redo(Controller* C);

void test_controller();
void test_add_estate();
void test_remove_estate();
void test_update_estate();
void test_display_contains_str_in_address_asc_by_price();
void test_display_is_of_type_has_greater_surface_than();
void test_undo_redo();

#endif
