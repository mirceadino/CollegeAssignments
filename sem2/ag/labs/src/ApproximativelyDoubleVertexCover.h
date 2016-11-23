#ifndef APPROXIMATIVELYDOUBLEVERTEXCOVER_H_
#define APPROXIMATIVELYDOUBLEVERTEXCOVER_H_

#include "UndirectedGraph.h"
#include "VertexCover.h"
#include <vector>

class ApproximativelyDoubleVertexCover: public VertexCover {

	public:
		ApproximativelyDoubleVertexCover(UndirectedGraph& graph) :
				VertexCover(graph) {
			solve();
		}

	private:
		void solve();
};

#endif /* APPROXIMATIVELYDOUBLEVERTEXCOVER_H_ */
