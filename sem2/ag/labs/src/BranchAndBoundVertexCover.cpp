#include "BranchAndBoundVertexCover.h"
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

void BranchAndBoundVertexCover::solve() {
	if (graph_.number_of_vertices() >= 18)
		return;

	int N = 0;

	for (auto x : graph_.vertices()) {
		vertex_to_index_[x] = N;
		index_to_vertex_[N] = x;
		N++;
	}

	int optimal_mask = (1 << N) - 1;

	back(0, -1, graph_, optimal_mask);

	for (int i = 0; i < N; i++)
		if (optimal_mask & (1 << i))
			vertex_cover_.push_back(index_to_vertex_[i]);
}

void BranchAndBoundVertexCover::back(int mask, int last_covered,
		UndirectedGraph G, int& optimal_mask) {
	if (__builtin_popcount(mask) >= __builtin_popcount(optimal_mask))
		return;

	G.remove_vertex(last_covered);

	if (G.number_of_edges() == 0) {
		if (__builtin_popcount(mask) < __builtin_popcount(optimal_mask))
			optimal_mask = mask;
		return;
	}

	for (auto x : graph_.vertices()) {
		int i = vertex_to_index_[x];
		if (!(mask & (1 << i)))
			back(mask ^ (1 << i), x, G, optimal_mask);
	}
}
