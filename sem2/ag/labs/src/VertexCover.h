#ifndef VERTEXCOVER_H_
#define VERTEXCOVER_H_

#include "UndirectedGraph.h"
#include <vector>

class VertexCover {

	public:
		VertexCover(UndirectedGraph& graph);
		std::vector<int> vertex_cover();
		int size();

	protected:
		UndirectedGraph& graph_;
		std::vector<int> vertex_cover_;
		void solve();
};

#endif /* VERTEXCOVER_H_ */
