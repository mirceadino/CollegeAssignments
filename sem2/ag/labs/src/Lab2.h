#ifndef LAB2_H_
#define LAB2_H_

#include "Digraph.h"
#include "WeightedDigraph.h"
#include <string>

namespace lab2 {
	void read_digraph(Digraph &G, std::string filename);
	void read_weighted_digraph(WeightedDigraph<int> &G, std::string filename);
	void run_menu(WeightedDigraph<int> &G);
}

#endif /* LAB2_H_ */
