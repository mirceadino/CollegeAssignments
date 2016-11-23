#ifndef UI_H_
#define UI_H_

#include "Controller.h"
#include "Repository.h"
#include "Vector.h"
#include "Estate.h"

typedef struct {
	Controller* ctrl;
} UI;

UI* create_ui(Controller* C);
int destroy_ui(UI* U);
void print_menu(UI* U);
void run(UI* U);
void run_add(UI *U);
void run_remove(UI *U);
void run_update(UI *U);
void run_display_contains_str_in_address_asc_by_price(UI *U);
void run_display_is_not_of_type_has_price_less_than_asc_by_price(UI *U);
void run_display_is_of_type_has_greater_surface_than(UI *U, int ascending);
void run_undo(UI *U);
void run_redo(UI *U);

#endif
