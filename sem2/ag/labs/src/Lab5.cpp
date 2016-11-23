#include <iostream>
#include <fstream>
#include <iomanip>
#include <queue>
#include "Lab5.h"
#include "TopologicalSortingActivityByEdge.h"

using namespace std;

void lab5::topological_sorting(WeightedDigraph<int>& G) {
	double start_time = clock();
	double end_time;

	TopologicalSortingActivityByEdge solver(G);

	if (solver.is_dag()) {
		cout << "Topological sorting, earliest starting time, latest starting time: \n";

		for (auto activity : solver.topological_sorting()) {
			int earliest = solver.earliest_starting_time(activity);
			int latest = solver.latest_starting_time(activity);
			cout << "activity " << activity.first << " " << activity.second;
			cout << ", earliest: " << earliest;
			cout << ", latest: " << latest << "\n";
		}

		cout << "-----------\n";
		cout << "Total time: " << solver.total_time() << "\n";
		cout << "-----------\n";

		cout << "Critical activities: \n";
		for (auto activity : solver.critical_activities()) {
			cout << "activity " << activity.first << " " << activity.second;
			cout << " must start on: " << solver.earliest_starting_time(activity) << "\n";
		}
		if (solver.critical_activities().empty())
			cout << "None.\n";

	} else {
		cout << "Graph is not a DAG.\n";
	}

	end_time = clock();

	std::cout << std::fixed << std::setprecision(6);
	std::cout << "Time elapsed: " << (end_time - start_time) / CLOCKS_PER_SEC << '\n';
}
