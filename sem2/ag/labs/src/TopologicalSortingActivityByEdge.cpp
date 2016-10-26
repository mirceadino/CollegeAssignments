#include "TopologicalSortingActivityByEdge.h"
#include "StronglyConnectedComponentsKosaraju.h"
#include "MinimumWalkFloydWarshall.h"
#include <queue>
#include <algorithm>

using namespace std;

TopologicalSortingActivityByEdge::TopologicalSortingActivityByEdge(WeightedDigraph<int>& graph) :
		graph_(graph) {

	check_if_dag();
	sort_topologically();
	compute_starting_times();

	for (auto activity : this->topological_sorting_)
		if (is_critical(activity))
			this->critical_activities_.push_back(activity);
}

bool TopologicalSortingActivityByEdge::is_dag() {
	return this->is_dag_;
}

std::vector<std::pair<int, int> > TopologicalSortingActivityByEdge::topological_sorting() {
	return this->topological_sorting_;
}

std::vector<std::pair<int, int> > TopologicalSortingActivityByEdge::critical_activities() {
	return this->critical_activities_;
}

int TopologicalSortingActivityByEdge::earliest_starting_time(int x, int y) {
	return this->starting_times_[x][y].first;
}

int TopologicalSortingActivityByEdge::latest_starting_time(int x, int y) {
	return this->starting_times_[x][y].second;
}

int TopologicalSortingActivityByEdge::earliest_starting_time(pair<int, int> activity) {
	return earliest_starting_time(activity.first, activity.second);
}

int TopologicalSortingActivityByEdge::latest_starting_time(pair<int, int> activity) {
	return latest_starting_time(activity.first, activity.second);
}

int TopologicalSortingActivityByEdge::total_time() {
	return this->total_time_;
}

void TopologicalSortingActivityByEdge::check_if_dag() {
	StronglyConnectedComponentsKosaraju solver(this->graph_);
	this->is_dag_ = (solver.number() == this->graph_.number_of_vertices());
}

void TopologicalSortingActivityByEdge::sort_topologically() {
	queue<int> Q;
	WeightedDigraph<int> G(this->graph_);

	for (auto x : G.vertices())
		if (G.indegree(x) == 0)
			Q.push(x);

	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();

		for (auto y : G.out_neighbours(x)) {
			topological_sorting_.emplace_back(x, y);
			G.remove_edge(x, y);
			if (G.indegree(y) == 0)
				Q.push(y);
		}
	}
}

bool TopologicalSortingActivityByEdge::is_critical(std::pair<int, int> activity) {
	return (earliest_starting_time(activity) == latest_starting_time(activity));
}

void TopologicalSortingActivityByEdge::compute_starting_times() {
	this->total_time_ = 0;

	for (auto activity : this->topological_sorting_) {
		int y = activity.first;
		int earliest = 0;

		for (auto x : this->graph_.in_neighbours(y))
			earliest = max(earliest, this->starting_times_[x][y].first + this->graph_.get_cost(x, y));

		this->starting_times_[activity.first][activity.second].first = earliest;

		this->total_time_ = max(this->total_time_, earliest + this->graph_.get_cost(activity.first, activity.second));
	}

	auto reversed_topological_sorting = this->topological_sorting_;
	reverse(reversed_topological_sorting.begin(), reversed_topological_sorting.end());

	for (auto activity : reversed_topological_sorting) {
		int x = activity.second;
		int latest = this->total_time_;

		for (auto y : this->graph_.out_neighbours(x))
			latest = min(latest, this->starting_times_[x][y].second);

		latest -= this->graph_.get_cost(activity.first, activity.second);
		this->starting_times_[activity.first][activity.second].second = latest;
	}
}
