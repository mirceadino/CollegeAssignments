#include "UI.h"
#include "Tests.h"

void init(Controller& ctrl) {
	ctrl.add("Nora Mork", "NOR", "Larvik", 83);
	ctrl.add("Isabelle Gullden", "SWE", "CSM Bucuresti", 80);
	ctrl.add("Cristina Neagu", "ROU", "Buducnost", 63);
	ctrl.add("Allison Pineau", "FRA", "HCM Baia Mare", 82);
	ctrl.add("Ilina Ekaterina", "RUS", "Rostov-Don", 80);
	ctrl.add("Nerea Pena", "FRA", "FTC-Rail Cargo Hungaria", 59);
}

int main() {
	test_add();
	test_filter();

	Repository repo;
	Controller ctrl(repo);
	init(ctrl);
	UI ui(ctrl);

	ui.run();

	return 0;
}
