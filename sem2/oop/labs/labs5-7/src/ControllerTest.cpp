#include <cassert>
#include "Controller.h"

void testController() {
	Tutorial A("a", "a", Duration(3, 3), 30, "ha");
	Tutorial B("b", "b", Duration(3, 3), 30, "hb");
	Tutorial C("c", "c", Duration(3, 3), 30, "hc");
	Tutorial F("f", "f", Duration(4, 4), 40, "hf");
	Tutorial H("f", "h", Duration(4, 4), 40, "hf");
	Controller ctrl;

	// add_tutorial
	assert(ctrl.add_tutorial_to_repository("a", "a", Duration(3, 3), 30, "ha"));
	assert(!ctrl.add_tutorial_to_repository("a", "b", Duration(3, 3), 30, "hb"));
	assert(ctrl.get_all_from_repository().size() == 1);
	assert(ctrl.add_tutorial_to_repository("b", "b", Duration(3, 3), 30, "hb"));
	assert(ctrl.add_tutorial_to_repository("c", "c", Duration(3, 3), 30, "hc"));
	assert(ctrl.get_all_from_repository().size() == 3);
	assert(ctrl.get_all_from_repository()[0] == A);
	assert(ctrl.get_all_from_repository()[1] == B);
	assert(ctrl.get_all_from_repository()[2] == C);

	Tutorial J("j", "", Duration(3, 3), 30, "");
	assert(!J.is_valid());
	assert(!ctrl.add_tutorial_to_repository("j", "", Duration(3, 3), 30, ""));
	assert(!ctrl.add_tutorial_to_repository("j", "", Duration(3, 300), 30, ""));
	assert(!ctrl.add_tutorial_to_repository("j", "", Duration(0, 0), 30, ""));

	// update_tutorial
	assert(!ctrl.update_tutorial("d", "f", "f", Duration(4, 4), 40, "hf"));
	assert(ctrl.update_tutorial("a", "f", "f", Duration(4, 4), 40, "hf"));
	assert(ctrl.get_all_from_repository()[0] == F);
	assert(!ctrl.update_tutorial("b", "f", "f", Duration(4, 4), 40, "hf"));
	assert(ctrl.update_tutorial("f", "", "h", Duration(4, 4), 40, ""));
	assert(ctrl.get_all_from_repository()[0] == H);
	assert(ctrl.get_all_from_repository().size() == 3);

	// remove_tutorial
	assert(ctrl.remove_tutorial_from_repository("b"));
	assert(ctrl.get_all_from_repository().size() == 2);
	assert(ctrl.get_all_from_repository()[0] == H);
	assert(ctrl.get_all_from_repository()[1] == C);
	assert(!ctrl.remove_tutorial_from_repository("b"));
	assert(ctrl.get_all_from_repository().size() == 2);
	assert(!ctrl.remove_tutorial_from_repository("g"));
	assert(ctrl.get_all_from_repository().size() == 2);
	assert(ctrl.remove_tutorial_from_repository("f"));
	assert(ctrl.get_all_from_repository()[0] == C);
	assert(ctrl.get_all_from_repository().size() == 1);
	assert(ctrl.remove_tutorial_from_repository("c"));
	assert(ctrl.get_all_from_repository().size() == 0);
}
