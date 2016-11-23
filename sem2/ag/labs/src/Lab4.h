#ifndef LAB4_H_
#define LAB4_H_

#include "WeightedDigraph.h"
#include "MinimumWalkFloydWarshall.h"
#include "NumberOfMinimumWalks.h"
#include <string>

namespace lab4 {
	void find_lowest_walk(WeightedDigraph<int>& G, int x, int y);
	void find_number_of_minimum_walks(WeightedDigraph<int>& G, int x, int y);
}

#endif /* LAB4_H_ */
