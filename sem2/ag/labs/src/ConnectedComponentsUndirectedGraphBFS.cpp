#include "ConnectedComponentsUndirectedGraphBFS.h"
#include <queue>

ConnectedComponentsUndirectedGraphBFS::ConnectedComponentsUndirectedGraphBFS(UndirectedGraph& graph) :
		graph_(graph) {

	std::unordered_map<int, bool> visited;

	for (auto x : this->graph_.vertices())
		if (!visited[x]) {
			std::vector<int> component;
			this->bfs(x, visited, component);
			this->connectedComponents_.push_back(this->separe(component));
		}
}

std::vector<UndirectedGraph> ConnectedComponentsUndirectedGraphBFS::get_components() {
	return this->connectedComponents_;
}

int ConnectedComponentsUndirectedGraphBFS::number() {
	return this->connectedComponents_.size();
}

void ConnectedComponentsUndirectedGraphBFS::bfs(int x, std::unordered_map<int, bool> &visited, std::vector<int> &accessed_vertices) {
	std::queue<int> Q;

	Q.push(x);
	visited[x] = true;

	while (!Q.empty()) {
		x = Q.front();
		Q.pop();
		accessed_vertices.push_back(x);

		for (auto y : this->graph_.neighbours(x))
			if (!visited[y]) {
				Q.push(y);
				visited[y] = true;
			}
	}
}

UndirectedGraph ConnectedComponentsUndirectedGraphBFS::separe(std::vector<int>& vertices) {
	UndirectedGraph G;

	for (auto x : vertices)
		G.add_vertex(x);

	for (auto x : vertices)
		for (auto y : this->graph_.neighbours(x))
			G.add_edge(x, y);

	return G;
}
