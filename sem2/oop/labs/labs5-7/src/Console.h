#ifndef CONSOLE_H_
#define CONSOLE_H_

#include "Controller.h"

class Console {
	public:
		Console();
		Console(const Controller& ctrl);

		void run();

	private:
		Controller controller_;

		int read_number(std::string message);
		std::string read_string(std::string message);

		void print_main_menu();
		void print_admin_menu();
		void print_user_menu();
		void print_playlist_menu();

		void run_admin();
		void run_user();

		void admin_add();
		void admin_remove();
		void admin_update();
		void admin_display();

		void user_watch_playlist_by_presenter();
		void user_remove_from_watchlist();
		void user_display_watchlist();
};

#endif /* CONSOLE_H_ */
