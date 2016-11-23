#ifndef NUMBEROFMINIMUMWALKS_CPP_
#define NUMBEROFMINIMUMWALKS_CPP_

#include "NumberOfMinimumWalks.h"
#include <iostream>

template<typename TProperty>
NumberOfMinimumWalks<TProperty>::NumberOfMinimumWalks(WeightedDigraph<TProperty>& graph) :
		MinimumWalkFloydWarshall<TProperty>(graph) {

	for (auto x : graph.vertices()) {
		this->costs_[x] = std::unordered_map<int, TProperty>();
		this->isAccessible_[x] = std::unordered_map<int, bool>();
		dp_[x] = std::unordered_map<int, int>();

		for (auto y : graph.vertices()) {
			this->costs_[x][y] = TProperty();
			this->isAccessible_[x][y] = false;
			dp_[x][y] = 0;
		}

		for (auto y : graph.out_neighbours(x)) {
			this->costs_[x][y] = graph.get_cost(x, y);
			this->isAccessible_[x][y] = true;
			dp_[x][y] = 1;
		}

		this->isAccessible_[x][x] = true;
		dp_[x][x] = 1;
	}

	for (auto k : graph.vertices())
		for (auto i : graph.vertices())
			for (auto j : graph.vertices()) {
				if (i != j && i != k && j != k && this->isAccessible_[i][k] && this->isAccessible_[k][j]) {
					if (this->isAccessible_[i][j]) {
						if (this->costs_[i][k] + this->costs_[k][j] < this->costs_[i][j]) {
							dp_[i][j] = 0;
							this->costs_[i][j] = this->costs_[k][j] < this->costs_[i][j];
						}

						if (this->costs_[i][k] + this->costs_[k][j] == this->costs_[i][j])
							dp_[i][j] += dp_[i][k] * dp_[k][j];

					} else {
						this->costs_[i][j] = this->costs_[i][k] + this->costs_[k][j];
						this->isAccessible_[i][j] = true;
						dp_[i][j] = 1;
					}
				}
			}

//	for (auto i : graph.vertices()) {
//		std::cout << i << ": ";
//		for (auto j : graph.vertices())
//			std::cout << j << ":" << dp_[i][j] << " ";
//		std::cout << std::endl;
//	}
}

template<typename TProperty>
int NumberOfMinimumWalks<TProperty>::get_number_of_walks(int x, int y) {
	return dp_[x][y];
}

#endif
