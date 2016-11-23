#ifndef BRANCHANDBOUNDVERTEXCOVER_H_
#define BRANCHANDBOUNDVERTEXCOVER_H_

#include "UndirectedGraph.h"
#include "VertexCover.h"
#include <vector>

class BranchAndBoundVertexCover: public VertexCover {

	public:
		BranchAndBoundVertexCover(UndirectedGraph& graph) :
				VertexCover(graph) {
			solve();
		}

	private:
		std::unordered_map<int, int> vertex_to_index_;
		std::unordered_map<int, int> index_to_vertex_;

		void solve();
		void back(int mask, int last_covered, UndirectedGraph G, int& optimal_mask);
		int count_bits(int x);
};

#endif /* BRANCHANDBOUNDVERTEXCOVER_H_ */
