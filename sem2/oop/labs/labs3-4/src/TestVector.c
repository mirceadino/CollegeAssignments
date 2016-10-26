#include "Vector.h"
#include "Estate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void test_vector() {
	printf("Testing vector... ");
	fflush(stdout);
	test_create_vector();
	test_add_in_vector();
	test_remove_from_vector_at_position();
	test_expand_vector();
	test_copy_vector();
	test_sort_ascendingly_by_price();
	test_filter_contains_str_in_address();
	printf("OK!!\n");
}

void test_create_vector() {
	Vector* V = create_vector();
	assert(V->length == 0);
	assert(V->capacity == 1);
	destroy_vector(V);
}

void test_add_in_vector() {
	Vector* V = create_vector();
	Estate* A = create_estate('h', "39 Teodor Mihali", 42, 44000);
	Estate* B = create_estate('h', "39 Teodor AAAAAA", 42, 44000);
	Estate* C = create_estate('h', "39 Teodor BBBBBB", 42, 44000);

	assert(add_in_vector(V, A));
	assert(equals_estate(V->arr[0], A) == 1);
	assert(V->length == 1);

	assert(add_in_vector(V, B));
	assert(equals_estate(V->arr[0], A) == 1);
	assert(equals_estate(V->arr[1], B) == 1);
	assert(V->length == 2);

	assert(add_in_vector(V, C));
	assert(equals_estate(V->arr[0], A) == 1);
	assert(equals_estate(V->arr[1], B) == 1);
	assert(equals_estate(V->arr[2], C) == 1);
	assert(V->length == 3);

	destroy_vector(V);
}

void test_remove_from_vector_at_position() {
	Vector* V = create_vector();
	Estate* A = create_estate('h', "39 Teodor Mihali", 42, 44000);
	Estate* B = create_estate('h', "39 Teodor AAAAAA", 42, 44000);
	Estate* C = create_estate('h', "39 Teodor BBBBBB", 42, 44000);
	Estate* Aclone = copy_estate(A);
	Estate* Bclone = copy_estate(B);
	Estate* Cclone = copy_estate(C);

	add_in_vector(V, A);
	add_in_vector(V, B);
	add_in_vector(V, C);
	assert(V->length == 3);

	assert(remove_from_vector_at_position(V, 0) == 1);
	assert(equals_estate(V->arr[0], Bclone) == 1);
	assert(equals_estate(V->arr[1], Cclone) == 1);
	assert(V->length == 2);

	assert(remove_from_vector_at_position(V, 2) == 0);

	assert(remove_from_vector_at_position(V, 1) == 1);
	assert(equals_estate(V->arr[0], Bclone) == 1);
	assert(V->length == 1);

	assert(remove_from_vector_at_position(V, 0) == 1);
	assert(V->length == 0);

	assert(remove_from_vector_at_position(V, 0) == 0);

	destroy_vector(V);
	destroy_estate(Aclone);
	destroy_estate(Bclone);
	destroy_estate(Cclone);
}

void test_expand_vector() {
	Vector* V = create_vector();

	assert(expand_vector(V));
	assert(V->capacity == 2);
	assert(expand_vector(V));
	assert(V->capacity == 4);

	destroy_vector(V);
}

void test_copy_vector() {
	Vector* V = create_vector();
	Estate* A = create_estate('h', "39 Teodor Mihali", 42, 44000);
	Estate* B = create_estate('h', "39 Teodor AAAAAA", 42, 44000);
	Estate* C = create_estate('h', "39 Teodor BBBBBB", 42, 44000);

	add_in_vector(V, A);
	add_in_vector(V, B);
	add_in_vector(V, C);

	Vector* newV = copy_vector(V);
	assert(equals_estate(newV->arr[0], A) == 1);
	assert(equals_estate(newV->arr[1], B) == 1);
	assert(equals_estate(newV->arr[2], C) == 1);
	assert(newV->length == 3);

	destroy_vector(V);
	destroy_vector(newV);
}

void test_sort_ascendingly_by_price() {
	Vector* V = create_vector();
	Estate* A = create_estate('p', "30 Teodor Mihali", 56, 30000);
	Estate* B = create_estate('a', "29 Teodor Mihali", 16, 12000);
	Estate* C = create_estate('a', "17 Mihail Kogalniceanu", 20, 17500);
	Estate* D = create_estate('h', "16 Intre Lacuri", 46, 26000);
	Estate* E = create_estate('h', "17 Intre Lacuri", 40, 23000);

	add_in_vector(V, A);
	add_in_vector(V, B);
	add_in_vector(V, C);
	add_in_vector(V, D);
	add_in_vector(V, E);

	Vector* sorted = sort(V, cmp_asc_by_price);

	assert(equals_estate(sorted->arr[0], B) == 1);
	assert(equals_estate(sorted->arr[1], C) == 1);
	assert(equals_estate(sorted->arr[2], E) == 1);
	assert(equals_estate(sorted->arr[3], D) == 1);
	assert(equals_estate(sorted->arr[4], A) == 1);

	destroy_vector(V);
	destroy_vector(sorted);
}

void test_filter_contains_str_in_address() {
	Vector* V = create_vector();
	Estate* A = create_estate('p', "30 Teodor Mihali", 56, 30000);
	Estate* B = create_estate('a', "29 Teodor Mihali", 16, 12000);
	Estate* C = create_estate('a', "17 Mihail Kogalniceanu", 20, 17500);
	Estate* D = create_estate('h', "16 Intre Lacuri", 46, 26000);
	Estate* E = create_estate('h', "17 Intre Lacuri", 40, 23000);

	add_in_vector(V, A);
	add_in_vector(V, B);
	add_in_vector(V, C);
	add_in_vector(V, D);
	add_in_vector(V, E);

	char str[] = "Teodor Mihali";
	Vector* filtered = filter(V, flt_contains_str_in_address, (void*) str);

	assert(equals_estate(filtered->arr[0], A) == 1);
	assert(equals_estate(filtered->arr[1], B) == 1);
	assert(filtered->length == 2);

	destroy_vector(V);
	destroy_vector(filtered);
}
