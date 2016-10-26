#ifndef LAB3_H_
#define LAB3_H_

#include "Digraph.h"
#include "UndirectedGraph.h"
#include "WeightedDigraph.h"
#include "ConnectedComponentsUndirectedGraphBFS.h"
#include "StronglyConnectedComponentsKosaraju.h"
#include <string>

#define WeightedUndirectedGraph WeightedDigraph

namespace lab3 {
	void read_undirected_graph(UndirectedGraph &G, std::string filename);
	void read_weighted_undirected_graph(WeightedUndirectedGraph<int> &G, std::string filename);
	void find_connected_components(UndirectedGraph &G);
	void find_strongly_connected_components(Digraph &G);
}

#endif /* LAB3_H_ */
