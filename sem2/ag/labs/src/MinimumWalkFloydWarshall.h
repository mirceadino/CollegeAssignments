#ifndef MINIMUMWALKFLOYDWARSHALL_H_
#define MINIMUMWALKFLOYDWARSHALL_H_

#include "WeightedDigraph.h"

template<typename TProperty>
class MinimumWalkFloydWarshall {
	public:
		MinimumWalkFloydWarshall(WeightedDigraph<TProperty>& graph);

		TProperty get_cost(int x, int y);

		bool is_accessible(int x, int y);

		std::vector<int> get_walk(int x, int y);

	protected:
		WeightedDigraph<TProperty> graph_;
		std::unordered_map<int, std::unordered_map<int, TProperty> > costs_;
		std::unordered_map<int, std::unordered_map<int, bool> > isAccessible_;
};

#endif /* MINIMUMWALKFLOYDWARSHALL_H_ */

#ifndef MINIMUMWALKFLOYDWARSHALL_CPP_

#include "MinimumWalkFloydWarshall.cpp"

#endif
