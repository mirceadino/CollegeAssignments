#include <iostream>
#include <fstream>
#include <iomanip>
#include "Lab6.h"

using namespace std;

void lab6::approximate_vertex_cover(UndirectedGraph& G) {
	double start_time = clock();
	double end_time;

	ApproximativelyDoubleVertexCover solver(G);

	cout << "Applied algorithm: approximation algorithm\n";
	cout << "Found vertex cover has size: " << solver.size() << '\n';
	cout << "Vertex cover contains:\n";

	for (auto x : solver.vertex_cover()) {
		cout << "vertex " << x;
		cout << " which is incident with edges: ";
		for (auto y : G.neighbours(x))
			cout << "(" << x << ", " << y << ") ";
		cout << "\n";
	}

	end_time = clock();

	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time elapsed: " << (end_time - start_time) / CLOCKS_PER_SEC << '\n';
}

void lab6::exact_vertex_cover(UndirectedGraph& G) {
	double start_time = clock();
	double end_time;

	BranchAndBoundVertexCover solver(G);

	cout << "Applied algorithm: branch-and-bound algorithm\n";
	cout << "Found vertex cover has size: " << solver.size() << '\n';
	cout << "Vertex cover contains:\n";

	for (auto x : solver.vertex_cover()) {
		cout << "vertex " << x;
		cout << " which is incident with edges: ";
		for (auto y : G.neighbours(x))
			cout << "(" << x << ", " << y << ") ";
		cout << "\n";
	}

	end_time = clock();

	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time elapsed: " << (end_time - start_time) / CLOCKS_PER_SEC << '\n';
}
