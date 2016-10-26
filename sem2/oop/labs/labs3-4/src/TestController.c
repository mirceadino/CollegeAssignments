#include "Controller.h"
#include "Repository.h"
#include "Vector.h"
#include "Estate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

void test_controller() {
	printf("Testing controller... ");
	fflush(stdout);
	test_add_estate();
	test_remove_estate();
	test_update_estate();
	test_display_contains_str_in_address_asc_by_price();
	test_display_is_of_type_has_greater_surface_than();
	test_undo_redo();
	printf("OK!!\n");
}

void test_add_estate() {
	Repository* R = create_repository();
	Controller* C = create_controller(R);
	Estate* A = create_estate('h', "39 Teodor Mihali", 42, 44000);
	Estate* B = create_estate('h', "39 Teodor AAAAAA", 42, 44000);

	assert(add_estate(C, A->type, A->address, A->surface, A->price));
	assert(R->size == 1);
	assert(find_in_repository(R, A) == 1);
	assert(find_in_repository(R, B) == 0);

	assert(!add_estate(C, A->type, A->address, A->surface, A->price));
	assert(R->size == 1);
	assert(find_in_repository(R, A) == 1);
	assert(find_in_repository(R, B) == 0);

	assert(!add_estate(C, 'P', A->address, A->surface, A->price));
	assert(R->size == 1);
	assert(find_in_repository(R, A) == 1);
	assert(find_in_repository(R, B) == 0);

	assert(!add_estate(C, A->type, A->address, -50, A->price));
	assert(R->size == 1);
	assert(find_in_repository(R, A) == 1);
	assert(find_in_repository(R, B) == 0);

	assert(add_estate(C, B->type, B->address, B->surface, B->price));
	assert(R->size == 2);
	assert(find_in_repository(R, A) == 1);
	assert(find_in_repository(R, B) == 1);

	destroy_controller(C);
	destroy_repository(R);
	destroy_estate(A);
	destroy_estate(B);
}

void test_remove_estate() {
	Repository* R = create_repository();
	Controller* C = create_controller(R);
	Estate* A = create_estate('h', "39 Teodor Mihali", 42, 44000);
	Estate* B = create_estate('h', "39 Teodor AAAAAA", 42, 44000);
	Estate* Aclone = copy_estate(A);

	add_in_repository(R, A);
	add_in_repository(R, B);

	assert(remove_estate(C, "39 Teodor Mihali"));
	assert(find_in_repository(R, Aclone) == 0);
	assert(!remove_estate(C, "39 Teodor Mihali"));

	destroy_controller(C);
	destroy_repository(R);
	destroy_estate(Aclone);
}

void test_update_estate() {
	Repository* R = create_repository();
	Controller* C = create_controller(R);
	Estate* A = create_estate('h', "39 Teodor Mihali", 42, 44000);
	Estate* B = create_estate('h', "39 Teodor AAAAAA", 42, 44000);
	Estate* Aclone = copy_estate(A);

	add_in_repository(R, A);
	add_in_repository(R, B);

	assert(update_estate(C, "39 Teodor Mihali", 'p', "39 Teodor Mihali", 40, 40000));
	assert(find_in_repository(R, Aclone) == 0);
	destroy_estate(Aclone);
	Aclone = copy_estate(A);
	assert(find_in_repository(R, Aclone) == 1);
	assert(!update_estate(C, "39 Teodor Mihali", 'p', "39 Teodor AAAAAA", 40, 40000));
	assert(!update_estate(C, "39 fefe", 'p', "39 Teodor AAAAAA", 40, 40000));

	destroy_controller(C);
	destroy_repository(R);
	destroy_estate(Aclone);
}

void test_display_contains_str_in_address_asc_by_price() {
	Repository* R = create_repository();
	Controller* C = create_controller(R);
	add_estate(C, 'p', "30 Teodor Mihali", 56, 30000);
	add_estate(C, 'a', "29 Teodor Mihali", 16, 12000);
	add_estate(C, 'a', "17 Mihail Kogalniceanu", 20, 17500);
	add_estate(C, 'h', "16 Intre Lacuri", 46, 26000);
	add_estate(C, 'h', "17 Intre Lacuri", 40, 23000);
	add_estate(C, 'h', "18 Intre Lacuri", 48, 27000);

	Vector* V = display_contains_str_in_address_asc_by_price(C, "Miha");

	Estate* A = create_estate('a', "29 Teodor Mihali", 16, 12000);
	Estate* B = create_estate('a', "17 Mihail Kogalniceanu", 20, 17500);
	Estate* D = create_estate('p', "30 Teodor Mihali", 56, 30000);

	assert(V->length == 3);
	assert(equals_estate(V->arr[0], A));
	assert(equals_estate(V->arr[1], B));
	assert(equals_estate(V->arr[2], D));

	destroy_controller(C);
	destroy_repository(R);
	destroy_vector(V);
	destroy_estate(A);
	destroy_estate(B);
	destroy_estate(D);
}

void test_display_is_of_type_has_greater_surface_than() {
	Repository* R = create_repository();
	Controller* C = create_controller(R);
	add_estate(C, 'p', "30 Teodor Mihali", 56, 30000);
	add_estate(C, 'a', "29 Teodor Mihali", 16, 12000);
	add_estate(C, 'a', "17 Mihail Kogalniceanu", 20, 17500);
	add_estate(C, 'h', "16 Intre Lacuri", 46, 26000);
	add_estate(C, 'h', "17 Intre Lacuri", 40, 23000);
	add_estate(C, 'h', "18 Intre Lacuri", 48, 27000);

	Vector* V = display_is_of_type_has_greater_surface_than(C, 'h', 45, 1);

	Estate* A = create_estate('h', "16 Intre Lacuri", 46, 26000);
	Estate* B = create_estate('h', "18 Intre Lacuri", 48, 27000);

	assert(V->length == 2);
	assert(equals_estate(V->arr[0], A));
	assert(equals_estate(V->arr[1], B));

	destroy_controller(C);
	destroy_repository(R);
	destroy_vector(V);
	destroy_estate(A);
	destroy_estate(B);
}

void test_undo_redo() {
	Repository* R = create_repository();
	Controller* C = create_controller(R);

	assert(!redo(C));
	assert(!undo(C));

	add_estate(C, 'p', "30 Teodor Mihali", 56, 30000);
	add_estate(C, 'a', "29 Teodor Mihali", 16, 12000);

	assert(!redo(C));
	assert(undo(C));

	assert(find_in_repository_by_address(R, "29 Teodor Mihali") == NULL);
	assert(redo(C));
	assert(find_in_repository_by_address(R, "29 Teodor Mihali") != NULL);

	remove_estate(C, "29 Teodor Mihali");
	assert(!redo(C));
	add_estate(C, 'a', "31 Teodor Mihali", 16, 12000);
	assert(!redo(C));

	update_estate(C, "31 Teodor Mihali", 'h', "31 Teodor Mihali", 16, 12000);
	assert(!redo(C));
	assert(undo(C));
	Estate* O = find_in_repository_by_address(R, "31 Teodor Mihali");
	assert(O->type == 'a');
	assert(redo(C));
	assert(O->type == 'h');

	assert(undo(C));
	assert(undo(C));
	assert(undo(C));
	assert(find_in_repository_by_address(R, "29 Teodor Mihali") != NULL);
	assert(undo(C));
	assert(find_in_repository_by_address(R, "29 Teodor Mihali") == NULL);
	assert(undo(C));
	assert(find_in_repository_by_address(R, "30 Teodor Mihali") == NULL);
	assert(!undo(C));

	destroy_controller(C);
	destroy_repository(R);
}
