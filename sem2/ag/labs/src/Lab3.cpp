#include <iostream>
#include <fstream>
#include <iomanip>
#include "Lab3.h"

#define WeightedUndirectedGraph WeightedDigraph

void lab3::read_undirected_graph(UndirectedGraph &G, std::string filename) {
	double start_time = clock();
	double end_time;
	std::ifstream fin(filename);

	if (!fin.is_open()) {
		std::cout << "Filename is invalid." << '\n';
		return;
	}

	int N, M;
	fin >> N >> M;
	G = UndirectedGraph(N);

	for (int i = 0, x, y, z; i < M; i++) {
		fin >> x >> y >> z;
		G.add_edge(x, y);
		G.add_edge(y, x);
	}

	std::cout << "Successfully read from \"" << filename << "\" an undirected graph with :" << '\n';
	std::cout << "- " << G.number_of_vertices() << " vertices; " << '\n';
	std::cout << "- " << G.number_of_edges() << " edges. " << '\n';

	fin.close();

	end_time = clock();
	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time elapsed: " << (end_time - start_time) / CLOCKS_PER_SEC << '\n';
}

void lab3::read_weighted_undirected_graph(WeightedUndirectedGraph<int> &G, std::string filename) {
	double start_time = clock();
	double end_time;
	std::ifstream fin(filename);

	if (!fin.is_open()) {
		std::cout << "Filename is invalid." << '\n';
		return;
	}

	int N, M;
	fin >> N >> M;
	G = WeightedUndirectedGraph<int>(N);

	for (int i = 0, x, y, z; i < M; i++) {
		fin >> x >> y >> z;
		G.add_edge(x, y, z);
		G.add_edge(y, x, z);
	}

	std::cout << "Successfully read from \"" << filename << "\" a weighted undirected graph with :" << '\n';
	std::cout << "- " << G.number_of_vertices() << " vertices; " << '\n';
	std::cout << "- " << G.number_of_edges() << " edges. " << '\n';

	fin.close();

	end_time = clock();
	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time elapsed: " << (end_time - start_time) / CLOCKS_PER_SEC << '\n';
}

void lab3::find_connected_components(UndirectedGraph &G) {
	double start_time = clock();
	double end_time;

	std::ofstream fout("lab3-connected.txt");
	ConnectedComponentsUndirectedGraphBFS solveComponents(G);
	std::vector<UndirectedGraph> components = solveComponents.get_components();

	for (auto component : components) {
		for (auto x : component.vertices())
			fout << x << " ";
		fout << "\n";
	}

	std::cout << solveComponents.number() << " connected components.\n";
	fout << solveComponents.number() << " connected components.\n";

	fout.close();

	end_time = clock();
	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time elapsed: " << (end_time - start_time) / CLOCKS_PER_SEC << '\n';
}

void lab3::find_strongly_connected_components(Digraph &G) {
	double start_time = clock();
	double end_time;

	std::ofstream fout("lab3-strongly-connected.txt");
	StronglyConnectedComponentsKosaraju solveComponents(G);
	std::vector<Digraph> components = solveComponents.get_components();

	for (auto component : components) {
		for (auto x : component.vertices())
			fout << x << " ";
		fout << "\n";
	}

	std::cout << solveComponents.number() << " strongly-connected components.\n";
	fout << solveComponents.number() << " strongly-connected components.\n";

	fout.close();

	end_time = clock();
	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time elapsed: " << (end_time - start_time) / CLOCKS_PER_SEC << '\n';
}
