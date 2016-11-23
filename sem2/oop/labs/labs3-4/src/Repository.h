#ifndef REPOSITORY_H_
#define REPOSITORY_H_

#include "Vector.h"
#include "Estate.h"

typedef struct {
	// storage for the estates
	Vector* estates;

	// number of estates in the Repository
	int size;
} Repository;

/* Creates an empty repository.
 * return: *pointer to the Repository */
Repository* create_repository();

/* Destroys a Repository and recursively all the Estates it holds.
 * param: *R - pointer to the Repository
 * return: 1 if successful, 0 otherwise */
int destroy_repository(Repository* R);

/* Adds an Estate to a Repository.
 * param: *R - pointer to the Repository
 * param: *O - pointer to the Estate to be added
 * return: 1 if successful, 0 otherwise (if there is already an Estate with the same address) */
int add_in_repository(Repository* R, Estate* O);

/* Removes from a Repository an Estate given by its address.
 * param: *R - pointer to the Repository
 * param: *address - pointer to the string corresponding to the address of the estate
 * return: 1 if successful, 0 otherwise (if there is no estate with such address) */
int remove_from_repository_at_address(Repository* R, char* address);

/* Checks whether an Estate exists or not in a Repository.
 * param: *R - pointer to the Repository
 * param: *O - pointer to the Estate
 * return: 1 if it exists, 0 otherwise*/
int find_in_repository(Repository* R, Estate* O);

/* Checks whether it exists an Estate with a certain address in a Repository.
 * param: *R - pointer to the Repository
 * param: *address - pointer to the string corresponding to the address
 * return: *pointer to Estate in the Repository with corresponding address, NULL if it doesn't exist*/
Estate* find_in_repository_by_address(Repository* R, char* address);

/* Returns a vector with all estates.
 * param: *R - pointer to the Repository
 * return: *pointer to the Vector with all estates */
Vector* get_all_estates(Repository* R);

void test_repository();
void test_add_in_repository();
void test_remove_from_repository_at_address();
void test_find_in_repository();
void test_find_in_repository_by_address();

#endif
