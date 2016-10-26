#include "ApproximativelyDoubleVertexCover.h"
#include <unordered_map>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void ApproximativelyDoubleVertexCover::solve() {
	UndirectedGraph G(this->graph_);

	unordered_map<int, bool> is_in_cover;
	vector<pair<int, int>> edges;

	for (auto x : G.vertices())
		for (auto y : G.neighbours(x))
			if (x < y)
				edges.emplace_back(x, y);

	srand(time(0));
	random_shuffle(edges.begin(), edges.end());

	while (!edges.empty()) {
		int x = edges.back().first;
		int y = edges.back().second;
		edges.pop_back();

		if (!G.is_edge(x, y))
			continue;

		if (!is_in_cover.count(x)) {
			this->vertex_cover_.push_back(x);
			G.remove_vertex(x);
		}

		if (!is_in_cover.count(y)) {
			this->vertex_cover_.push_back(y);
			G.remove_vertex(y);
		}
	}
}
