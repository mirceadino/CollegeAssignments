#ifndef CONNECTEDCOMPONENTSBFS_H_
#define CONNECTEDCOMPONENTSBFS_H_

#include "UndirectedGraph.h"

class ConnectedComponentsUndirectedGraphBFS {
	public:
		ConnectedComponentsUndirectedGraphBFS(UndirectedGraph& graph);
		std::vector<UndirectedGraph> get_components();
		int number();

	private:
		UndirectedGraph& graph_;
		std::vector<UndirectedGraph> connectedComponents_;

		void bfs(int x, std::unordered_map<int, bool> &visited, std::vector<int> &accessed_vertices);
		UndirectedGraph separe(std::vector<int>& vertices);
};

#endif /* CONNECTEDCOMPONENTSBFS_H_ */
