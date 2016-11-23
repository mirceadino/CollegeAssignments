#ifndef TOPOLOGICALSORTINGACTIVITYBYEDGE_H_
#define TOPOLOGICALSORTINGACTIVITYBYEDGE_H_

#include "WeightedDigraph.h"

class TopologicalSortingActivityByEdge {
	public:
		TopologicalSortingActivityByEdge(WeightedDigraph<int>& graph);
		bool is_dag();
		std::vector<std::pair<int, int>> topological_sorting();
		std::vector<std::pair<int, int>> critical_activities();
		int earliest_starting_time(int x, int y);
		int latest_starting_time(int x, int y);
		int earliest_starting_time(std::pair<int, int> activity);
		int latest_starting_time(std::pair<int, int> activity);
		int total_time();

	private:
		WeightedDigraph<int>& graph_;
		bool is_dag_ = false;
		std::vector<std::pair<int, int>> topological_sorting_;
		std::vector<std::pair<int, int>> critical_activities_;
		std::unordered_map<int, std::unordered_map<int, std::pair<int, int>>>starting_times_;
		int total_time_ = 0;

		void check_if_dag();
		void sort_topologically();
		bool is_critical(std::pair<int,int> activity);
		void compute_starting_times();
	};

#endif /* TOPOLOGICALSORTINGACTIVITYBYEDGE_H_ */
