#include "UndirectedGraph.h"

UndirectedGraph::UndirectedGraph() {
	N_ = 0;
	M_ = 0;
}

UndirectedGraph::UndirectedGraph(int N) {
	N_ = N;
	M_ = 0;

	for (int i = 0; i < N; i++) {
		vertices_.insert(i);
		neighbours_[i] = std::vector<int>();
	}
}

UndirectedGraph::UndirectedGraph(const UndirectedGraph& that) {
	N_ = int(that.N_);
	M_ = int(that.M_);
	vertices_ = std::unordered_set<int>(that.vertices_);
	neighbours_ = std::unordered_map<int, std::vector<int>>(that.neighbours_);
}

UndirectedGraph::~UndirectedGraph() {
}

UndirectedGraph& UndirectedGraph::operator=(const UndirectedGraph& that) {
	N_ = int(that.N_);
	M_ = int(that.M_);
	vertices_ = std::unordered_set<int>(that.vertices_);
	neighbours_ = std::unordered_map<int, std::vector<int>>(that.neighbours_);

	return *this;
}

int UndirectedGraph::number_of_vertices() {
	return N_;
}

int UndirectedGraph::number_of_edges() {
	return M_;
}

bool UndirectedGraph::is_vertex(int x) {
	return vertices_.count(x);
}

bool UndirectedGraph::is_edge(int x, int y) {
	if (!is_vertex(x) || !is_vertex(y))
		return false;

	for (auto neighbour : neighbours_[x])
		if (neighbour == y)
			return true;

	return false;
}

int UndirectedGraph::degree(int x) {
	if (!is_vertex(x))
		return 0;

	return neighbours_[x].size();
}

std::unordered_set<int> UndirectedGraph::vertices() {
	return vertices_;
}

std::vector<int> UndirectedGraph::neighbours(int x) {
	if (!is_vertex(x))
		return std::vector<int>();

	return neighbours_[x];
}

void UndirectedGraph::add_edge(int x, int y) {
	if (is_edge(x, y) || !is_vertex(x) || !is_vertex(y) || x == y)
		return;

	neighbours_[x].push_back(y);
	neighbours_[y].push_back(x);

	M_++;
}

void UndirectedGraph::remove_edge(int x, int y) {
	if (!is_edge(x, y))
		return;

	for (auto &neighbour : neighbours_[x])
		if (neighbour == y) {
			std::swap(neighbour, neighbours_[x].back());
			neighbours_[x].pop_back();
			break;
		}

	for (auto &neighbour : neighbours_[y])
		if (neighbour == x) {
			std::swap(neighbour, neighbours_[y].back());
			neighbours_[y].pop_back();
			break;
		}

	M_--;
}

void UndirectedGraph::add_vertex(int x) {
	if (is_vertex(x))
		return;

	vertices_.insert(x);
	neighbours_[x] = std::vector<int>();
	N_++;
}

void UndirectedGraph::remove_vertex(int x) {
	if (!is_vertex(x))
		return;

	for (auto neighbour : neighbours(x))
		remove_edge(neighbour, x);

	vertices_.erase(x);
	neighbours_.erase(x);
	N_--;
}
