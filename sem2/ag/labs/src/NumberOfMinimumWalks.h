#ifndef NUMBEROFMINIMUMWALKS_H_
#define NUMBEROFMINIMUMWALKS_H_

#include "MinimumWalkFloydWarshall.h"

template<typename TProperty>
class NumberOfMinimumWalks: public MinimumWalkFloydWarshall<TProperty> {
	public:
		NumberOfMinimumWalks(WeightedDigraph<TProperty>& graph);

		int get_number_of_walks(int x, int y);

	private:
		std::unordered_map<int, std::unordered_map<int, int>> dp_;
};

#endif /* NUMBEROFMINIMUMWALKS_H_ */

#ifndef NUMBEROFMINIMUMWALKS_CPP_

#include "NumberOfMinimumWalks.cpp"

#endif
