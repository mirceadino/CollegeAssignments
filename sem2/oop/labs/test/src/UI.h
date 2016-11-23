#ifndef UI_H_
#define UI_H_

#include "Controller.h"
#include <iostream>

class UI {
	public:
		UI(const Controller& ctrl);
		void run();

	private:
		Controller ctrl_;

		void print_menu();
		int read_number(std::string message = "");
		std::string read_string(std::string message = "");
		void run_add();
		void run_remove();
		void run_show();
		void run_filter();
};

#endif /* UI_H_ */
