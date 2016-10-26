#include <cstdio>
#include <iostream>
#include <cstring>
#include "Lab2.h"
#include "Lab3.h"
#include "Lab4.h"
#include "Lab5.h"
#include "Lab6.h"

using namespace std;

bool parse_filename_parameter(int argc, char** argv, char* filename) {
	for (int i = 0; i < argc; i++)
		if (sscanf(argv[i], "-f=%s", filename))
			return true;

	cout << "No filename. Use \"-f=\%s\" to set the filename for input graph." << '\n';

	return false;
}

bool parse_labwork_parameter(int argc, char** argv, int &labwork) {
	for (int i = 0; i < argc; i++)
		if (sscanf(argv[i], "-l=%d", &labwork))
			return true;

	cout << "No lab. Use \"-l=\%d\" to set the lab." << '\n';

	return false;
}

int main(int argc, char** argv) {
	char filename[105];
	int labwork = 0;

	parse_filename_parameter(argc, argv, filename);
	parse_labwork_parameter(argc, argv, labwork);

	if (labwork == 2) {
		WeightedDigraph<int> G;

		lab2::read_weighted_digraph(G, string(filename));
		lab2::run_menu(G);
	}

	if (labwork == 3) {
		UndirectedGraph G1;
		Digraph G2;

		lab3::read_undirected_graph(G1, string(filename));
		cout << "-----------\n";
		lab3::find_connected_components(G1);
		cout << "-----------\n";
		lab2::read_digraph(G2, string(filename));
		cout << "-----------\n";
		lab3::find_strongly_connected_components(G2);
	}

	if (labwork == 4) {
		WeightedDigraph<int> G;

		lab2::read_weighted_digraph(G, string(filename));
		cout << "-----------\n";

		int x, y;
		cout << "Type a pair of nodes: ";
		cin >> x >> y;
		cout << "-----------\n";

		lab4::find_lowest_walk(G, x, y);
		cout << "-----------\n";
		lab4::find_number_of_minimum_walks(G, x, y);
	}

	if (labwork == 5) {
		WeightedDigraph<int> G;

		lab2::read_weighted_digraph(G, string(filename));
		cout << "-----------\n";

		lab5::topological_sorting(G);
	}

	if (labwork == 6) {
		UndirectedGraph G;

		lab3::read_undirected_graph(G, string(filename));
		cout << "-----------\n";

		lab6::approximate_vertex_cover(G);

		cout << "-----------\n";

		lab6::exact_vertex_cover(G);
	}

	return 0;
}
