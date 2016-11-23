#include "StronglyConnectedComponentsKosaraju.h"
#include <algorithm>

StronglyConnectedComponentsKosaraju::StronglyConnectedComponentsKosaraju(Digraph& graph) :
		graph_(graph) {

	std::unordered_map<int, bool> visited;
	std::vector<int> topological_ordering;

	for (auto x : this->graph_.vertices())
		if (!visited[x])
			this->dfs(this->graph_, x, visited, topological_ordering);

	reverse(topological_ordering.begin(), topological_ordering.end());

	Digraph GT = this->graph_;
	GT.transpose();

	visited.clear();

	for (auto x : topological_ordering)
		if (!visited[x]) {
			std::vector<int> component;
			this->dfs(GT, x, visited, component);
			this->stronglyConnectedComponents_.push_back(this->separe(component));
		}
}

std::vector<Digraph> StronglyConnectedComponentsKosaraju::get_components() {
	return this->stronglyConnectedComponents_;
}

int StronglyConnectedComponentsKosaraju::number() {
	return this->stronglyConnectedComponents_.size();
}

void StronglyConnectedComponentsKosaraju::dfs(Digraph &G, int x, std::unordered_map<int, bool>& visited, std::vector<int>& accessed_vertices) {
	visited[x] = true;

	for (auto y : G.out_neighbours(x))
		if (!visited[y])
			dfs(G, y, visited, accessed_vertices);

	accessed_vertices.push_back(x);
}

Digraph StronglyConnectedComponentsKosaraju::separe(std::vector<int>& vertices) {
	Digraph G;

	for (auto x : vertices)
		G.add_vertex(x);

	for (auto x : vertices)
		for (auto y : this->graph_.out_neighbours(x))
			G.add_edge(x, y);

	return G;
}
