#include "Estate.h"
#include "Vector.h"
#include "Repository.h"
#include "Controller.h"
#include "UI.h"
#include <stdio.h>

void example(Controller* C) {
	add_estate(C, 'p', "30 Teodor Mihali", 56, 30000);
	add_estate(C, 'a', "29 Teodor Mihali", 16, 12000);
	add_estate(C, 'a', "17 Mihail Kogalniceanu", 20, 17500);
	add_estate(C, 'h', "16 Intre Lacuri", 46, 26000);
	add_estate(C, 'h', "17 Intre Lacuri", 40, 23000);
	add_estate(C, 'h', "18 Intre Lacuri", 48, 27000);
	add_estate(C, 'a', "17 Memorandumului", 20, 23000);
	add_estate(C, 'a', "18 Nicolae Titulescu", 38, 26000);
	add_estate(C, 'p', "29 Nicolae Titulescu", 68, 60000);
}

int main() {
	system("clear");

	test_estate();
	test_vector();
	test_repository();
	test_controller();

	Repository* R = create_repository();
	Controller* C = create_controller(R);
	UI* U = create_ui(C);

	example(C);

	run(U);

	destroy_ui(U);
	destroy_controller(C);
	destroy_repository(R);

	return 0;
}
