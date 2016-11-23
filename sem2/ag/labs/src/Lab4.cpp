#include <iostream>
#include <fstream>
#include <iomanip>
#include "Lab4.h"

void lab4::find_lowest_walk(WeightedDigraph<int>& G, int x, int y) {
	double start_time = clock();
	double end_time;

	MinimumWalkFloydWarshall<int> solver(G);

	if (solver.is_accessible(x, y)) {
		std::vector<int> walk = solver.get_walk(x, y);
		std::cout << "Walk of length: " << solver.get_cost(x, y) << "\n";
		std::cout << "Walk: ";
		for (auto x : walk)
			std::cout << x << " ";
		std::cout << "\n";

	} else {
		std::cout << "No walk available.\n";
	}

	end_time = clock();
	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time elapsed: " << (end_time - start_time) / CLOCKS_PER_SEC << '\n';
}

void lab4::find_number_of_minimum_walks(WeightedDigraph<int>& G, int x, int y) {
	double start_time = clock();
	double end_time;

	NumberOfMinimumWalks<int> solver(G);

	if (solver.is_accessible(x, y)) {
		std::cout << "Walk of length: " << solver.get_cost(x, y) << "\n";
		std::cout << "Number of minimum walks: " << solver.get_number_of_walks(x, y) << "\n";

	} else {
		std::cout << "No walk available.\n";
	}

	end_time = clock();
	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time elapsed: " << (end_time - start_time) / CLOCKS_PER_SEC << '\n';
}
