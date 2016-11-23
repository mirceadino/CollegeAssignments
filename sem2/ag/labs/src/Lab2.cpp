#include <iostream>
#include <fstream>
#include <iomanip>
#include "Digraph.h"
#include "WeightedDigraph.h"
#include "Lab2.h"

void lab2::read_digraph(Digraph &G, std::string filename) {
	double start_time;
	double end_time;
	std::ifstream fin(filename);

	if (!fin.is_open()) {
		std::cout << "Filename is invalid." << '\n';
		return;
	}

	start_time = clock();

	int N, M;
	fin >> N >> M;
	G = Digraph(N);

	for (int i = 0, x, y, z; i < M; i++) {
		fin >> x >> y >> z;
		G.add_edge(x, y);
	}

	std::cout << "Successfully read from \"" << filename << "\" a directed graph with :" << '\n';
	std::cout << "- " << G.number_of_vertices() << " vertices; " << '\n';
	std::cout << "- " << G.number_of_edges() << " edges. " << '\n';

	end_time = clock();
	fin.close();

	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time elapsed: " << (end_time - start_time) / CLOCKS_PER_SEC << '\n';
}

void lab2::read_weighted_digraph(WeightedDigraph<int> &G, std::string filename) {
	double start_time;
	double end_time;
	std::ifstream fin(filename);

	if (!fin.is_open()) {
		std::cout << "Filename is invalid." << '\n';
		return;
	}

	start_time = clock();

	int N, M;
	fin >> N >> M;
	G = WeightedDigraph<int>(N);

	for (int i = 0, x, y, z; i < M; i++) {
		fin >> x >> y >> z;
		G.add_edge(x, y, z);
	}

	std::cout << "Successfully read from \"" << filename << "\" a weighted directed graph with :" << '\n';
	std::cout << "- " << G.number_of_vertices() << " vertices; " << '\n';
	std::cout << "- " << G.number_of_edges() << " edges. " << '\n';

	end_time = clock();
	fin.close();

	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time elapsed: " << (end_time - start_time) / CLOCKS_PER_SEC << '\n';
}

void lab2::run_menu(WeightedDigraph<int> &G) {
	std::string menu;
	menu += "1 - Add edge\n";
	menu += "2 - Remove edge\n";
	menu += "3 - Add vertex\n";
	menu += "4 - Remove vertex\n";
	menu += "5 - Print graph's properties\n";
	menu += "6 - In neighbours of vertex\n";
	menu += "7 - Out neighbours of vertex\n";
	menu += "8 - Is vertex?\n";
	menu += "9 - Is edge?\n";
	menu += "10 - Set new cost of edge\n";
	menu += "0 - Exit\n";

	while (1) {
		int option;
		std::cout << "-----------\n";
		std::cout << menu;
		std::cout << "Type option : ";
		std::cin >> option;
		std::cout << "-----------\n";

		if (option)
			system("clear");

		if (option == 1) {
			int x, y, z;
			std::cout << "Type tail, head and cost: ";
			std::cin >> x >> y >> z;
			if (!G.is_vertex(x) || !G.is_vertex(y)) {
				std::cout << "Invalid vertices.\n";
				continue;
			} else if (G.is_edge(x, y)) {
				std::cout << "Edge already exists.\n";
				continue;
			}
			G.add_edge(x, y, z);
		} else if (option == 2) {
			int x, y;
			std::cout << "Type tail and head: ";
			std::cin >> x >> y;
			if (!G.is_vertex(x) || !G.is_vertex(y)) {
				std::cout << "Invalid vertices.\n";
				continue;
			} else if (!G.is_edge(x, y)) {
				std::cout << "Edge doesn't exist.\n";
				continue;
			}
			G.remove_edge(x, y);
		} else if (option == 3) {
			int x;
			std::cout << "Type vertex: ";
			std::cin >> x;
			if (G.is_vertex(x)) {
				std::cout << "Vertex already exists.\n";
				continue;
			}
			G.add_vertex(x);
		} else if (option == 4) {
			int x;
			std::cout << "Type vertex: ";
			std::cin >> x;
			if (!G.is_vertex(x)) {
				std::cout << "Vertex doesn't exist.\n";
				continue;
			}
			G.remove_vertex(x);
		} else if (option == 5) {
			std::cout << "Vertices : " << G.number_of_vertices() << "\n";
			std::cout << "Edges : " << G.number_of_edges() << "\n";
		} else if (option == 6) {
			int x;
			std::cout << "Type vertex: ";
			std::cin >> x;
			if (!G.is_vertex(x)) {
				std::cout << "Not a vertex.\n";
				continue;
			}
			std::cout << G.indegree(x) << " in neighbours : ";
			for (auto y : G.in_neighbours(x))
				std::cout << "(" << y << ", " << G.get_cost(y, x) << ") ";
			if (G.indegree(x) == 0)
				std::cout << "None";
			std::cout << "\n";
		} else if (option == 7) {
			int x;
			std::cout << "Type vertex: ";
			std::cin >> x;
			if (!G.is_vertex(x)) {
				std::cout << "Not a vertex.\n";
				continue;
			}
			std::cout << G.outdegree(x) << " out neighbours : ";
			for (auto y : G.out_neighbours(x))
				std::cout << "(" << y << ", " << G.get_cost(x, y) << ") ";
			if (G.outdegree(x) == 0)
				std::cout << "None";
			std::cout << "\n";
		} else if (option == 8) {
			int x;
			std::cout << "Type vertex: ";
			std::cin >> x;
			std::cout << (G.is_vertex(x) ? "Yes" : "No") << "\n";
		} else if (option == 9) {
			int x, y;
			std::cout << "Type tail and head: ";
			std::cin >> x >> y;
			std::cout << (G.is_edge(x, y) ? "Yes" : "No") << "\n";
		} else if (option == 10) {
			int x, y, z;
			std::cout << "Type tail, head and new cost: ";
			std::cin >> x >> y >> z;
			if (!G.is_edge(x, y)) {
				std::cout << "Not an edge.\n";
				continue;
			}
			G.set_cost(x, y, z);
		} else if (option == 0) {
			break;
		} else {
			std::cout << "Invalid option.\n";
		}
	}
}
