#include "Repository.h"
#include "Vector.h"
#include "Estate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void test_repository() {
	printf("Testing repository... ");
	fflush(stdout);
	test_add_in_repository();
	test_remove_from_repository_at_address();
	test_find_in_repository();
	test_find_in_repository_by_address();
	printf("OK!!\n");
}

void test_add_in_repository() {
	Repository* R = create_repository();
	Estate* A = create_estate('h', "39 Teodor Mihali", 42, 44000);
	Estate* B = create_estate('h', "39 Teodor AAAAAA", 42, 44000);
	Estate* C = create_estate('h', "39 Teodor BBBBBB", 42, 44000);

	assert(add_in_repository(R, A));
	assert(R->size == 1);
	assert(find_in_repository(R, A) == 1);
	assert(find_in_repository(R, B) == 0);
	assert(find_in_repository(R, C) == 0);

	assert(!add_in_repository(R, A));
	assert(R->size == 1);
	assert(find_in_repository(R, A) == 1);
	assert(find_in_repository(R, B) == 0);
	assert(find_in_repository(R, C) == 0);

	assert(add_in_repository(R, B));
	assert(R->size == 2);
	assert(find_in_repository(R, A) == 1);
	assert(find_in_repository(R, B) == 1);
	assert(find_in_repository(R, C) == 0);

	assert(add_in_repository(R, C));
	assert(R->size == 3);
	assert(find_in_repository(R, A) == 1);
	assert(find_in_repository(R, B) == 1);
	assert(find_in_repository(R, C) == 1);

	assert(!add_in_repository(R, C));
	assert(R->size == 3);
	assert(find_in_repository(R, A) == 1);
	assert(find_in_repository(R, B) == 1);
	assert(find_in_repository(R, C) == 1);

	destroy_repository(R);
}

void test_remove_from_repository_at_address() {
	Repository* R = create_repository();
	Estate* A = create_estate('h', "39 Teodor Mihali", 42, 44000);
	Estate* B = create_estate('h', "39 Teodor AAAAAA", 42, 44000);
	Estate* C = create_estate('h', "39 Teodor BBBBBB", 42, 44000);
	Estate* Aclone = copy_estate(A);

	add_in_repository(R, A);
	add_in_repository(R, B);
	add_in_repository(R, C);
	assert(remove_from_repository_at_address(R, "39 Teodor Mihali"));
	assert(find_in_repository(R, Aclone) == 0);
	assert(!remove_from_repository_at_address(R, "39 Teodor Mihali"));

	destroy_repository(R);
	destroy_estate(Aclone);
}

void test_find_in_repository() {
	Repository* R = create_repository();
	Estate* A = create_estate('h', "39 Teodor Mihali", 42, 44000);
	Estate* B = create_estate('h', "39 Teodor AAAAAA", 42, 44000);
	Estate* C = create_estate('h', "39 Teodor BBBBBB", 42, 44000);

	add_in_repository(R, A);
	assert(find_in_repository(R, A) == 1);
	add_in_repository(R, B);
	assert(find_in_repository(R, B) == 1);
	assert(find_in_repository(R, C) == 0);
	add_in_repository(R, C);
	assert(find_in_repository(R, A) == 1);
	assert(find_in_repository(R, B) == 1);
	assert(find_in_repository(R, C) == 1);

	destroy_repository(R);
}

void test_find_in_repository_by_address() {
	Repository* R = create_repository();
	Estate* A = create_estate('h', "39 Teodor Mihali", 42, 44000);
	Estate* B = create_estate('h', "39 Teodor AAAAAA", 42, 44000);
	Estate* C = create_estate('h', "39 Teodor BBBBBB", 42, 44000);

	add_in_repository(R, A);
	assert(equals_estate(find_in_repository_by_address(R, "39 Teodor Mihali"), A) == 1);
	add_in_repository(R, B);
	assert(equals_estate(find_in_repository_by_address(R, "39 Teodor AAAAAA"), B) == 1);
	assert(find_in_repository_by_address(R, "39 Teodor BBBBBB") == NULL);
	add_in_repository(R, C);
	assert(equals_estate(find_in_repository_by_address(R, "39 Teodor Mihali"), A) == 1);
	assert(equals_estate(find_in_repository_by_address(R, "39 Teodor AAAAAA"), B) == 1);
	assert(equals_estate(find_in_repository_by_address(R, "39 Teodor BBBBBB"), C) == 1);

	destroy_repository(R);
}
