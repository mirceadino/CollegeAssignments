#ifndef STRONGLYCONNECTEDCOMPONENTSKOSARAJU_H_
#define STRONGLYCONNECTEDCOMPONENTSKOSARAJU_H_

#include "Digraph.h"

class StronglyConnectedComponentsKosaraju {
	public:
		StronglyConnectedComponentsKosaraju(Digraph& graph);
		std::vector<Digraph> get_components();
		int number();

	private:
		Digraph& graph_;
		std::vector<Digraph> stronglyConnectedComponents_;

		void dfs(Digraph& G, int x, std::unordered_map<int, bool> &visited, std::vector<int> &accessed_vertices);
		Digraph separe(std::vector<int>& vertices);
};

#endif /* STRONGLYCONNECTEDCOMPONENTSKOSARAJU_H_ */
