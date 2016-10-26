#include "Digraph.h"

Digraph::Digraph() {
	N_ = 0;
	M_ = 0;
}

Digraph::Digraph(int N) {
	N_ = N;
	M_ = 0;

	for (int i = 0; i < N; i++) {
		vertices_.insert(i);
		in_neighbours_[i] = out_neighbours_[i] = std::vector<int>();
	}
}

Digraph::Digraph(const Digraph& that) {
	N_ = int(that.N_);
	M_ = int(that.M_);
	vertices_ = std::unordered_set<int>(that.vertices_);
	in_neighbours_ = std::unordered_map<int, std::vector<int>>(that.in_neighbours_);
	out_neighbours_ = std::unordered_map<int, std::vector<int>>(that.out_neighbours_);
}

Digraph::~Digraph() {
}

Digraph& Digraph::operator=(const Digraph& that) {
	N_ = int(that.N_);
	M_ = int(that.M_);
	vertices_ = std::unordered_set<int>(that.vertices_);
	in_neighbours_ = std::unordered_map<int, std::vector<int>>(that.in_neighbours_);
	out_neighbours_ = std::unordered_map<int, std::vector<int>>(that.out_neighbours_);

	return *this;
}

void Digraph::transpose() {
	N_ = int(N_);
	M_ = int(M_);
	vertices_ = std::unordered_set<int>(vertices_);
	swap(in_neighbours_, out_neighbours_);
}

int Digraph::number_of_vertices() {
	return N_;
}

int Digraph::number_of_edges() {
	return M_;
}

bool Digraph::is_vertex(int x) {
	return vertices_.count(x);
}

bool Digraph::is_edge(int x, int y) {
	if (!is_vertex(x) || !is_vertex(y))
		return false;

	for (auto neighbour : out_neighbours_[x])
		if (neighbour == y)
			return true;

	return false;
}

int Digraph::indegree(int x) {
	if (!is_vertex(x))
		return 0;

	return in_neighbours_[x].size();
}

int Digraph::outdegree(int x) {
	if (!is_vertex(x))
		return 0;

	return out_neighbours_[x].size();
}

std::unordered_set<int> Digraph::vertices() {
	return vertices_;
}

std::vector<int> Digraph::in_neighbours(int x) {
	if (!is_vertex(x))
		return std::vector<int>();

	return in_neighbours_[x];
}

std::vector<int> Digraph::out_neighbours(int x) {
	if (!is_vertex(x))
		return std::vector<int>();

	return out_neighbours_[x];
}

void Digraph::add_edge(int x, int y) {
	if (is_edge(x, y) || !is_vertex(x) || !is_vertex(y) || x == y)
		return;

	out_neighbours_[x].push_back(y);
	in_neighbours_[y].push_back(x);

	M_++;
}

void Digraph::remove_edge(int x, int y) {
	if (!is_edge(x, y))
		return;

	for (auto &neighbour : out_neighbours_[x])
		if (neighbour == y) {
			std::swap(neighbour, out_neighbours_[x].back());
			out_neighbours_[x].pop_back();
			break;
		}

	for (auto &neighbour : in_neighbours_[y])
		if (neighbour == x) {
			std::swap(neighbour, in_neighbours_[y].back());
			in_neighbours_[y].pop_back();
			break;
		}

	M_--;
}

void Digraph::add_vertex(int x) {
	if (is_vertex(x))
		return;

	vertices_.insert(x);
	in_neighbours_[x] = std::vector<int>();
	out_neighbours_[x] = std::vector<int>();
	N_++;
}

void Digraph::remove_vertex(int x) {
	if (!is_vertex(x))
		return;

	for (auto neighbour : in_neighbours(x))
		remove_edge(neighbour, x);

	for (auto neighbour : out_neighbours(x))
		remove_edge(x, neighbour);

	vertices_.erase(x);
	in_neighbours_.erase(x);
	out_neighbours_.erase(x);
	N_--;
}
