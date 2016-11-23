#include "UI.h"
#include <cstdlib>

using namespace std;

UI::UI(const Controller& ctrl) :
		ctrl_(ctrl) {
}

void UI::run() {
	system("clear");

	while (true) {
		cout << "---------\n";

		print_menu();

		int option = read_number("Type option: ");

		cout << "---------\n";

		if (option == 1)
			run_add();
		else if (option == 2)
			run_remove();
		else if (option == 3)
			run_show();
		else if (option == 4)
			run_filter();
		else if (option == 0)
			break;
		else
			cout << "Invalid option.\n";
	}

	cout << "Good bye!";
}

void UI::print_menu() {
	string menu;
	menu += "1 - Add player\n";
	menu += "2 - Remove player\n";
	menu += "3 - Show all players\n";
	menu += "4 - Show players by nationality\n";
	menu += "0 - Exit\n";
	menu += "---------\n";
	cout << menu;
}

int UI::read_number(string message) {
	int value = -1;

	cout << message;

	do {
		cin >> value;
		cin.ignore(256, '\n');
		if (value < 0)
			cout << "Number must be natural integer: ";
	} while (value < 0);

	return value;
}

std::string UI::read_string(string message) {
	string str;

	cout << message;
	getline(cin, str);

	return str;
}

void UI::run_add() {
	string name = read_string("Type name: ");
	string nationality = read_string("Type nationality: ");
	string team = read_string("Type team: ");
	int goals = read_number("Type goals: ");

	system("clear");

	if (ctrl_.add(name, nationality, team, goals))
		cout << "Successfully added.\n";
	else
		cout << "Player could not be added.\n";
}

void UI::run_remove() {
	string name = read_string("Type name: ");

	system("clear");

	if (ctrl_.remove(name))
		cout << "Successfully removed.\n";
	else
		cout << "Player could not be removed.\n";
}

void UI::run_show() {
	system("clear");

	vector<Player> all = ctrl_.getAllPlayers();

	if (all.empty())
		cout << "Empty.\n";

	for (unsigned int i = 0; i < all.size(); i++)
		cout << all[i].toString() << "\n";
}

void UI::run_filter() {
	string nationality = read_string("Type nationality: ");

	system("clear");

	vector<Player> all = ctrl_.getPlayerByNationalitySorted(nationality);

	if (all.empty())
		cout << "Empty.\n";

	for (unsigned int i = 0; i < all.size(); i++)
		cout << all[i].toString() << "\n";
}
