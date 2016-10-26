#include "UI.h"
#include "Controller.h"
#include "Repository.h"
#include "Vector.h"
#include "Estate.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

UI* create_ui(Controller* C) {
	UI* U = (UI*) malloc(sizeof(UI));
	U->ctrl = C;
	return U;
}

int destroy_ui(UI* U) {
	free(U);
	return 1;
}

void print_menu(UI* U) {
	printf(":: REAL ESTATE AGENCY ::\n");
	printf("1 - Add estate\n");
	printf("2 - Remove estate\n");
	printf("3 - Update estate\n");
	printf("4 - Display estates containing address, ascendingly by price\n");
	printf("5 - Display estates not of type, cheaper than a value, ascendingly by price \n");
	printf("6 - Display estates of type, larger than a value, ascendingly by surface\n");
	printf("7 - Display estates of type, larger than a value, descendingly by surface\n");
	printf("8 - Undo last change\n");
	printf("9 - Redo last undo\n");
	printf("0 - Exit\n");
}

void run(UI* U) {
	int option;

	system("clear");

	while (1) {
		printf("----------\n");

		print_menu(U);
		printf("$ Write option: ");
		scanf("%d", &option);

		printf("----------\n");

		if (option)
			system("clear");

		if (option == 1)
			run_add(U);
		else if (option == 2)
			run_remove(U);
		else if (option == 3)
			run_update(U);
		else if (option == 4)
			run_display_contains_str_in_address_asc_by_price(U);
		else if (option == 5)
			run_display_is_not_of_type_has_price_less_than_asc_by_price(U);
		else if (option == 6)
			run_display_is_of_type_has_greater_surface_than(U, 1);
		else if (option == 7)
			run_display_is_of_type_has_greater_surface_than(U, 0);
		else if (option == 8)
			run_undo(U);
		else if (option == 9)
			run_redo(U);
		else if (option == 0)
			break;
		else
			printf("Invalid option.\n");
	}

	printf("Good bye!\n");
}

void run_add(UI *U) {
	char type;
	char address[50];
	int surface;
	int price;

	printf("You are adding an estate.\n");
	printf("Type must be a character: 'h' for house, 'a' for apartment, 'p' for penthouse.\n");
	printf("All estates must have unique addresses.\n");
	printf("Surface and price must be positive integers.\n");

	printf("$ Write type: ");
	scanf("\n%c", &type);

	printf("$ Write address: ");
	scanf("\n");
	fgets(address, sizeof(address), stdin);
	address[strlen(address) - 1] = 0;

	printf("$ Write surface: ");
	scanf("%d", &surface);

	printf("$ Write price: ");
	scanf("%d", &price);

	if (add_estate(U->ctrl, type, address, surface, price))
		printf("Estate was successfully added!\n");
	else
		printf("Estate is invalid or there's already an estate with the same address!\n");
}

void run_remove(UI *U) {
	char address[50];

	printf("You are removing an estate.\n");

	printf("$ Write address: ");
	scanf("\n");
	fgets(address, sizeof(address), stdin);
	address[strlen(address) - 1] = 0;

	if (remove_estate(U->ctrl, address))
		printf("Estate was successfully removed!\n");
	else
		printf("Estate was not found!\n");
}

void run_update(UI *U) {
	char address[50];
	char new_type;
	char new_address[50];
	int new_surface;
	int new_price;

	printf("You are updating an estate.\n");

	printf("$ Write address: ");
	scanf("\n");
	fgets(address, sizeof(address), stdin);
	address[strlen(address) - 1] = 0;

	printf("Type must be a character: 'h' for house, 'a' for apartment, 'p' for penthouse.\n");
	printf("All estates must have unique addresses.\n");
	printf("Surface and price must be positive integers.\n");

	printf("$ Write new type: ");
	scanf("\n%c", &new_type);

	printf("$ Write new address: ");
	scanf("\n");
	fgets(new_address, sizeof(new_address), stdin);
	new_address[strlen(new_address) - 1] = 0;

	printf("$ Write new surface: ");
	scanf("%d", &new_surface);

	printf("$ Write new price: ");
	scanf("%d", &new_price);

	if (update_estate(U->ctrl, address, new_type, new_address, new_surface, new_price))
		printf("Estate was successfully updated!\n");
	else
		printf("Estate was not found, parameters are invalid or there is already an estate at that address!\n");
}

void run_display_contains_str_in_address_asc_by_price(UI *U) {
	char address[50];
	int i;

	printf("You are displaying estates that contain a certain substring in address, in ascending order by price.\n");

	fgets(address, sizeof(address), stdin);
	printf("$ Write address: ");
	fgets(address, sizeof(address), stdin);
	address[strlen(address) - 1] = 0;

	Vector* estates = display_contains_str_in_address_asc_by_price(U->ctrl, address);
	char output_buffer[100];

	printf("Estates containing \"%s\" in addresses:\n", address);

	if (!estates->length)
		printf("Empty.\n");

	for (i = 0; i < estates->length; i++) {
		estate_to_string(at_position(estates, i), output_buffer);
		printf("- %s\n", output_buffer);
	}

	destroy_vector(estates);
}

void run_display_is_not_of_type_has_price_less_than_asc_by_price(UI *U) {
	int i;
	char not_type;
	int max_price;

	printf("You are displaying estates not of a certain type, having price less than a given value, in ascending order by price.\n");

	printf("$ Write dispreffered type: ");
	scanf("\n%c", &not_type);

	printf("$ Write maximal price: ");
	scanf("%d", &max_price);

	Estate* aux = create_estate(not_type, "", 1, max_price);

	if (!is_valid_estate(aux)) {
		destroy_estate(aux);
		printf("Invalid type or price.\n");
		return;
	}

	destroy_estate(aux);

	Vector* estates = display_is_not_of_type_has_price_less_than_asc_by_price(U->ctrl, not_type, max_price);
	char output_buffer[100];
	char* type_buffer = type_from_char(not_type);

	printf("Estates which are not %ss with price less than %d:\n", type_buffer, max_price);

	free(type_buffer);

	if (!estates->length)
		printf("Empty.\n");

	for (i = 0; i < estates->length; i++) {
		estate_to_string(at_position(estates, i), output_buffer);
		printf("- %s\n", output_buffer);
	}

	destroy_vector(estates);
}

void run_display_is_of_type_has_greater_surface_than(UI *U, int ascending) {
	char type;
	int min_surface;
	int i;

	printf("You are displaying estates of a certain type, having surface greater than a given value, in %s order by surface.\n", ascending ? "ascending" : "descending");

	printf("$ Write type: ");
	scanf("\n%c", &type);

	printf("$ Write minimal surface: ");
	scanf("%d", &min_surface);

	Estate* aux = create_estate(type, "", min_surface + 1, 1);

	if (!is_valid_estate(aux)) {
		destroy_estate(aux);
		printf("Invalid type or surface.\n");
		return;
	}

	destroy_estate(aux);

	Vector* estates = display_is_of_type_has_greater_surface_than(U->ctrl, type, min_surface, ascending);
	char output_buffer[100];
	char* type_buffer = type_from_char(type);

	printf("%ss greater than %d m^2:\n", type_buffer, min_surface);

	free(type_buffer);

	if (!estates->length)
		printf("Empty.\n");

	for (i = 0; i < estates->length; i++) {
		estate_to_string(at_position(estates, i), output_buffer);
		printf("- %s\n", output_buffer);
	}

	destroy_vector(estates);
}

void run_undo(UI *U) {
	if (undo(U->ctrl))
		printf("Successful undo!\n");
	else
		printf("There's nothing to undo.\n");
}

void run_redo(UI *U) {
	if (redo(U->ctrl))
		printf("Successful redo!\n");
	else
		printf("There's nothing to redo.\n");
}
