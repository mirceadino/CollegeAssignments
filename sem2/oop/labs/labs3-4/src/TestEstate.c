#include "Estate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void test_estate() {
	printf("Testing estate... ");
	fflush(stdout);
	test_create_estate();
	test_is_valid_estate();
	test_setters_estate();
	test_equals_estate();
	printf("OK!!\n");
}

void test_create_estate() {
	Estate* E = create_estate('h', "39 Teodor Mihali", 42, 44000);

	assert(E->type == 'h');
	assert(strcmp(E->address, "39 Teodor Mihali") == 0);
	assert(E->surface == 42);
	assert(E->price == 44000);

	destroy_estate(E);
}

void test_is_valid_estate() {
	Estate* A = create_estate('h', "39 Teodor Mihali", 42, 44000);
	Estate* B = create_estate('t', "39 Teodor Mihali", 42, 44000);
	Estate* C = create_estate('h', "39 Teodor Mihali", -42, 44000);
	Estate* D = create_estate('h', "39 Teodor Mihali", -42, 0);

	assert(is_valid_estate(A));
	assert(!is_valid_estate(B));
	assert(!is_valid_estate(C));
	assert(!is_valid_estate(D));

	destroy_estate(A);
	destroy_estate(B);
	destroy_estate(C);
	destroy_estate(D);
}

void test_setters_estate() {
	Estate* E = create_estate('h', "39 Teodor Mihali", 42, 44000);

	assert(set_estate_type(E, 'p'));
	assert(E->type == 'p');
	assert(!set_estate_type(E, 'm'));
	assert(!set_estate_type(E, '1'));
	assert(!set_estate_type(E, 'H'));

	assert(set_estate_address(E, "9 Ion Pillat"));
	assert(strcmp(E->address, "9 Ion Pillat") == 0);

	assert(set_estate_surface(E, 30));
	assert(E->surface == 30);
	assert(!set_estate_surface(E, 0));
	assert(!set_estate_surface(E, -50));

	assert(set_estate_price(E, 30000));
	assert(E->price == 30000);
	assert(!set_estate_price(E, 0));
	assert(!set_estate_price(E, -30000));

	destroy_estate(E);
}

void test_equals_estate() {
	Estate* A = create_estate('h', "39 Teodor Mihali", 42, 44000);
	Estate* B = create_estate('h', "39 Teodor Mihali", 42, 44000);
	Estate* C = create_estate('p', "1 Mihail Kogalniceanu", 5542, 44000);

	assert(equals_estate(A, A) == 1);
	assert(equals_estate(A, B) == 1);
	assert(equals_estate(A, C) == 0);
	assert(equals_estate(B, A) == 1);
	assert(equals_estate(B, B) == 1);
	assert(equals_estate(B, C) == 0);
	assert(equals_estate(C, A) == 0);
	assert(equals_estate(C, B) == 0);
	assert(equals_estate(C, C) == 1);

	destroy_estate(A);
	destroy_estate(B);
	destroy_estate(C);
}
