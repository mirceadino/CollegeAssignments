#include <iostream>
#include "Console.h"
#include "Playlist.h"

using namespace std;

void tests() {
	cout << "Testing DynamicVector... ";
	testDynamicVector();
	cout << "OK!\n";

	cout << "Testing Repository... ";
	testRepository();
	cout << "OK!\n";

	cout << "Testing Controller... ";
	testController();
	cout << "OK!\n";
}

void init(Controller &ctrl) {
	ctrl.add_tutorial_to_repository("Bacon and Eggs", "Greg's Kitchen", Duration(5, 12), 44, "https://www.youtube.com/watch?v=_yDLYnOd2q8");
	ctrl.add_tutorial_to_repository("KFC Chicken", "HowToBasic", Duration(2, 48), 51, "https://www.youtube.com/watch?v=t9YRD4KrIqQ");
	ctrl.add_tutorial_to_repository("Turkey", "HowToBasic", Duration(3, 13), 41, "https://www.youtube.com/watch?v=qMbF2kA5WAI");
	ctrl.add_tutorial_to_repository("Chicken Parmigiana", "HowToBasic", Duration(2, 48), 43, "https://www.youtube.com/watch?v=xjQDCrNdsVU");
	ctrl.add_tutorial_to_repository("Salami Pasta", "Greg's Kitchen", Duration(5, 0), 53, "https://www.youtube.com/watch?v=xMpYqIFthjg");
	ctrl.add_tutorial_to_repository("Pizza", "Funnyplox", Duration(3, 27), 23, "https://www.youtube.com/watch?v=owjuZW4EDlE");
}

int main() {
	tests();

	Repository repo;
	Controller ctrl(repo);
	init(ctrl);
	Console ui(ctrl);

	ui.run();

	return 0;
}
