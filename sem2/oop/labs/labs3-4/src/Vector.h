#ifndef VECTOR_H_
#define VECTOR_H_

#include "Estate.h"

typedef struct {
	// effective storage for Estates
	Estate** arr;

	// length of the vector
	int length;

	// capacity of the vector
	int capacity;
} Vector;

/* Creates an empty vector.
 * return: *pointer to the Vector */
Vector* create_vector();

/* Destroys a Vector.
 * param: *V - pointer to the Vector
 * return: 1 if successful, 0 otherwise */
int destroy_vector(Vector* V);

/* Adds an Estate in a Vector.
 * param: *V - pointer to the Vector
 * param: *O - pointed to the Estate to be added
 * return: 1 if successful, 0 otherwise */
int add_in_vector(Vector* V, Estate* O);

/* Returns the Estate from a certain position in a Vector.
 * param: *V - pointer to the Vector
 * param: pos - positive integer indicating the position
 * return: *pointer to the Estate or NULL if position doesn't exist */
Estate* at_position(Vector* V, int pos);

/* Removes an Estate from a certain position in a Vector.
 * param: *V - pointer to the Vector
 * param: pos - positive integer indicating the position
 * return: 1 if successful, 0 otherwise (if position does not exist) */
int remove_from_vector_at_position(Vector* V, int pos);

/* Expands a Vector's capacity.
 * param: *V - pointer to the Vector
 * return: 1 if successful, 0 otherwise */
int expand_vector(Vector* V);

/* Copies the content of a Vector in a new one.
 * param: *V - pointer to the source Vector
 * return: *pointer to the Vector that is identical to the destination*/
Vector* copy_vector(Vector* V);

/* Sort a Vector with respect to some criteria.
 * param: *V - pointer to the Vector
 * param: *cmp - pointer to the comparison function
 * return: *pointer to the Vector that is sorted */
Vector* sort(Vector* V, int (*cmp)(Estate* A, Estate* B));

/* Filter a Vector with respect to some criteria.
 * param: *V - pointer to the Vector
 * param: *flt - pointer to the filtering function
 * return: *pointer to the Vector that is filtered */
Vector* filter(Vector* V, int (*flt)(Estate* A, void* param), void* param);

void test_vector();
void test_create_vector();
void test_add_in_vector();
void test_remove_from_vector_at_position();
void test_expand_vector();
void test_copy_vector();
void test_sort_ascendingly_by_price();
void test_filter_contains_str_in_address();

#endif
