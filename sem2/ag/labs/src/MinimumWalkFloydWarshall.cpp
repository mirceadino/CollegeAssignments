#ifndef MINIMUMWALKFLOYDWARSHALL_CPP_
#define MINIMUMWALKFLOYDWARSHALL_CPP_

#include "MinimumWalkFloydWarshall.h"

template<typename TProperty>
MinimumWalkFloydWarshall<TProperty>::MinimumWalkFloydWarshall(WeightedDigraph<TProperty>& graph) :
		graph_(graph) {

	for (auto x : graph.vertices()) {
		costs_[x] = std::unordered_map<int, TProperty>();
		isAccessible_[x] = std::unordered_map<int, bool>();

		for (auto y : graph.vertices()) {
			costs_[x][y] = TProperty();
			isAccessible_[x][y] = false;
		}

		for (auto y : graph.out_neighbours(x)) {
			costs_[x][y] = graph.get_cost(x, y);
			isAccessible_[x][y] = true;
		}

		isAccessible_[x][x] = true;
	}

	for (auto k : graph.vertices())
		for (auto i : graph.vertices())
			for (auto j : graph.vertices()) {
				if (i != j && i != k && j != k && isAccessible_[i][k] && isAccessible_[k][j]) {
					if (isAccessible_[i][j]) {
						costs_[i][j] = std::min(costs_[i][j], costs_[i][k] + costs_[k][j]);
					} else {
						costs_[i][j] = costs_[i][k] + costs_[k][j];
						isAccessible_[i][j] = true;
					}
				}
			}
}

template<typename TProperty>
TProperty MinimumWalkFloydWarshall<TProperty>::get_cost(int x, int y) {
	return costs_[x][y];
}

template<typename TProperty>
bool MinimumWalkFloydWarshall<TProperty>::is_accessible(int x, int y) {
	return isAccessible_[x][y];
}

template<typename TProperty>
std::vector<int> MinimumWalkFloydWarshall<TProperty>::get_walk(int x, int y) {
	std::vector<int> walk;

	if (!isAccessible_[x][y])
		return walk;

	while (x != y)
		for (auto z : graph_.out_neighbours(x))
			if (isAccessible_[z][y] && graph_.get_cost(x, z) + costs_[z][y] == costs_[x][y]) {
				walk.push_back(x);
				x = z;
				break;
			}

	walk.push_back(y);

	return walk;
}

#endif
