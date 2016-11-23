#ifndef LAB6_H_
#define LAB6_H_

#include "WeightedDigraph.h"
#include "UndirectedGraph.h"
#include "VertexCover.h"
#include "ApproximativelyDoubleVertexCover.h"
#include "BranchAndBoundVertexCover.h"

namespace lab6 {
	void approximate_vertex_cover(UndirectedGraph& G);
	void exact_vertex_cover(UndirectedGraph& G);
}

#endif /* LAB6_H_ */
