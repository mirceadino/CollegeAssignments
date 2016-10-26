#include "Console.h"
#include <iostream>
#include <cstdio>
#include <cmath>
#include <algorithm>

using namespace std;

Console::Console() :
		controller_(Controller()) {
}

Console::Console(const Controller& ctrl) :
		controller_(ctrl) {
}

void Console::run() {
	system("clear");

	while (true) {
		print_main_menu();

		int option = read_number("Choose mode: ");

		if (option)
			system("clear");

		if (option == 1)
			run_admin();
		else if (option == 2)
			run_user();
		else if (option == 0)
			break;
		else
			cout << "Invalid mode.\n----------\n";
	}
	cout << "----------\nBon appétit!\n";
}

int Console::read_number(std::string message) {
	int value;
	string str;
	cout << message;
	getline(cin, str);
	while (true) {
		if (sscanf(str.c_str(), "%d", &value))
			if (1 + (int) max(0.0, log10(value + 0.5)) == (int) str.size())
				break;

		cout << "Please type again: ";
		getline(cin, str);
	}
	return value;
}

string Console::read_string(std::string message) {
	string value;
	cout << message;
	getline(cin, value);
	return value;
}

void Console::print_main_menu() {
	string menu;

	menu += ":: MASTER THE ART OF COOKING ::\n";
	menu += "----------\n";
	menu += "1 - Admin mode\n";
	menu += "2 - User mode\n";
	menu += "0 - Exit\n";

	cout << menu;
}

void Console::print_admin_menu() {
	string menu;

	menu += "----------\n";
	menu += "1 - Add tutorial\n";
	menu += "2 - Remove tutorial\n";
	menu += "3 - Update tutorial\n";
	menu += "4 - Display all tutorials\n";
	menu += "0 - Back\n";

	cout << menu;
}

void Console::print_user_menu() {
	string menu;

	menu += "----------\n";
	menu += "1 - Watch tutorials by a given presenter\n";
	menu += "2 - Remove tutorial from watchlist\n";
	menu += "3 - Display all tutorials from watchlist\n";
	menu += "0 - Back\n";

	cout << menu;
}

void Console::print_playlist_menu() {
	string menu;

	menu += "----------\n";
	menu += "1 - Add to watchlist\n";
	menu += "2 - Next tutorial\n";
	menu += "0 - Exit playlist\n";

	cout << menu;
}

void Console::run_admin() {
	cout << ":: ADMIN MODE ::\n";

	while (true) {
		print_admin_menu();

		int option = read_number("Choose option: ");

		system("clear");

		if (option == 1)
			admin_add();
		else if (option == 2)
			admin_remove();
		else if (option == 3)
			admin_update();
		else if (option == 4)
			admin_display();
		else if (option == 0)
			break;
		else
			cout << "Invalid option.\n";
	}
}

void Console::run_user() {
	cout << ":: USER MODE ::\n";

	while (true) {
		print_user_menu();

		int option = read_number("Choose option: ");

		system("clear");

		if (option == 1)
			user_watch_playlist_by_presenter();
		else if (option == 2)
			user_remove_from_watchlist();
		else if (option == 3)
			user_display_watchlist();
		else if (option == 0)
			break;
		else
			cout << "Invalid option.\n";
	}
}

void Console::admin_add() {
	string title = read_string("Type title: ");
	string presenter = read_string("Type presenter: ");
	int min = read_number("Type minutes: ");
	int sec = read_number("Type seconds: ");
	int upvotes = read_number("Type upvotes: ");
	string url = read_string("Type url: ");

	if (controller_.add_tutorial_to_repository(title, presenter, Duration(min, sec), upvotes, url))
		cout << "Successfully added.\n";
	else
		cout << "Tutorial could not be added.\n";
}

void Console::admin_remove() {
	string title = read_string("Type title: ");

	if (controller_.remove_tutorial_from_repository(title))
		cout << "Successfully removed.\n";
	else
		cout << "Tutorial could not be removed.\n";
}

void Console::admin_update() {
	string title = read_string("Type title: ");
	string new_title = read_string("Type new title: ");
	string new_presenter = read_string("Type new presenter: ");
	int new_min = read_number("Type new minutes: ");
	int new_sec = read_number("Type new seconds: ");
	int new_upvotes = read_number("Type new upvotes: ");
	string new_url = read_string("Type new url: ");

	if (controller_.update_tutorial(title, new_title, new_presenter, Duration(new_min, new_sec), new_upvotes, new_url))
		cout << "Successfully updated.\n";
	else
		cout << "Tutorial could not be updated.\n";
}

void Console::admin_display() {
	DynamicVector<Tutorial> all = controller_.get_all_from_repository();

	if (all.size() == 0)
		cout << "Empty.\n";

	for (int i = 0; i < all.size(); i++)
		cout << all[i].str() << "\n";
}

void Console::user_watch_playlist_by_presenter() {
	string presenter = read_string("Type presenter: ");

	if (!this->controller_.create_playlist(presenter)) {
		cout << "Playlist could not be created. No tutorials with such presenter.\n";
		return;
	}

	this->controller_.start_playlist();

	while (true) {
		Tutorial& tuto = this->controller_.play_current_in_playlist();

		while (true) {
			cout << "Currently playing: ";
			cout << tuto.str() << "\n";

			print_playlist_menu();

			int option = read_number("Choose option: ");

			system("clear");

			if (option == 1) {
				if (this->controller_.add_tutorial_to_watchlist(tuto))
					cout << "Successfully added to watchlist.\n";
				else
					cout << "Tutorial could not be added to watchlist.\n";

			} else if (option == 2) {
				this->controller_.go_next_in_playlist();
				break;

			} else if (option == 0) {
				return;

			} else {
				cout << "Invalid option.\n";

			}
		}
	}
}

void Console::user_remove_from_watchlist() {
	string title = read_string("Type title: ");

	if (controller_.remove_tutorial_from_watchlist(title)) {

		while (true) {
			string upvotes = read_string("Do you want to upvote (Y/N)? ");

			if (upvotes == "Y" || upvotes == "y") {
				controller_.upvote_tutorial(title);
				cout << "Successfully removed from watchlist (and upvoted).\n";
				break;

			} else if (upvotes == "N" || upvotes == "n") {
				cout << "Successfully removed from watchlist.\n";
				break;
			}
		}

	} else {
		cout << "Tutorial could not be removed from watchlist.\n";
	}
}

void Console::user_display_watchlist() {
	DynamicVector<Tutorial> all = controller_.get_all_from_watchlist();

	if (all.size() == 0)
		cout << "Empty.\n";

	for (int i = 0; i < all.size(); i++)
		cout << all[i].str() << "\n";
}
