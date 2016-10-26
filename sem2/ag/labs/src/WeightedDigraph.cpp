#ifndef WEIGHTEDDIGRAPH_CPP_
#define WEIGHTEDDIGRAPH_CPP_

#include "WeightedDigraph.h"

template<typename TProperty>
WeightedDigraph<TProperty>::WeightedDigraph() :
		Digraph() {
}

template<typename TProperty>
WeightedDigraph<TProperty>::WeightedDigraph(int N) :
		Digraph(N) {
}

template<typename TProperty>
WeightedDigraph<TProperty>::WeightedDigraph(WeightedDigraph<TProperty>& that) :
		Digraph(that) {
	costs_ = std::map<std::pair<int, int>, TProperty>(that.costs_);
}

template<typename TProperty>
WeightedDigraph<TProperty>::~WeightedDigraph() {
}

template<typename TProperty>
WeightedDigraph<TProperty>& WeightedDigraph<TProperty>::operator=(
		const WeightedDigraph<TProperty>& that) {
	N_ = int(that.N_);
	M_ = int(that.M_);
	vertices_ = std::unordered_set<int>(that.vertices_);
	in_neighbours_ = std::unordered_map<int, std::vector<int>>(
			that.in_neighbours_);
	out_neighbours_ = std::unordered_map<int, std::vector<int>>(
			that.out_neighbours_);
	costs_ = std::map<std::pair<int, int>, TProperty>(that.costs_);

	return *this;
}

template<typename TProperty>
void WeightedDigraph<TProperty>::transpose() {
	this->transpose();

	std::map<std::pair<int, int>, TProperty> costs = costs_;
	costs_.clear();

	for (auto edge : costs) {
		auto head = edge.first.first;
		auto tail = edge.first.second;
		auto cost = edge.second;
		costs_[ { tail, head }] = cost;
	}
}

template<typename TProperty>
TProperty WeightedDigraph<TProperty>::get_cost(int x, int y) {
	if (!is_edge(x, y))
		return TProperty();

	return costs_[ { x, y }];
}

template<typename TProperty>
void WeightedDigraph<TProperty>::set_cost(int x, int y, TProperty z) {
	if (!is_edge(x, y))
		return;

	costs_[ { x, y }] = z;
}

template<typename TProperty>
void WeightedDigraph<TProperty>::add_edge(int x, int y, TProperty z) {
	if (is_edge(x, y) || !is_vertex(x) || !is_vertex(y) || x == y)
		return;

	out_neighbours_[x].push_back(y);
	in_neighbours_[y].push_back(x);
	costs_[ { x, y }] = z;

	M_++;
}

template<typename TProperty>
void WeightedDigraph<TProperty>::remove_edge(int x, int y) {
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

	costs_.erase( { x, y });

	M_--;
}

template<typename TProperty>
void WeightedDigraph<TProperty>::add_vertex(int x) {
	if (is_vertex(x))
		return;

	vertices_.insert(x);
	in_neighbours_[x] = std::vector<int>();
	out_neighbours_[x] = std::vector<int>();
	N_++;
}

template<typename TProperty>
void WeightedDigraph<TProperty>::remove_vertex(int x) {
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

#endif
