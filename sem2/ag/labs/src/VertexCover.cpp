#include "VertexCover.h"
#include <unordered_map>
#include <algorithm>

using namespace std;

VertexCover::VertexCover(UndirectedGraph& graph) :
		graph_(graph) {

	solve();
}

std::vector<int> VertexCover::vertex_cover() {
	return this->vertex_cover_;
}

int VertexCover::size() {
	return this->vertex_cover_.size();
}

void VertexCover::solve() {
}
