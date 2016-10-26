#ifndef UNDIRECTEDGRAPH_H_
#define UNDIRECTEDGRAPH_H_

#include <vector>
#include <unordered_set>
#include <unordered_map>

class UndirectedGraph {
	public:
		/* Default constructor. */
		UndirectedGraph();

		/* Constructor for a graph with a certain number of vertices, but no edges. */
		UndirectedGraph(int);

		/* Copy constructor. */
		UndirectedGraph(const UndirectedGraph&);

		/* Destructor. */
		~UndirectedGraph();

		/* Assignment operator. */
		UndirectedGraph& operator=(const UndirectedGraph&);

		/* Returns the number of vertices. */
		int number_of_vertices();

		/* Returns the number of edges. */
		int number_of_edges();

		/* Checks if a vertex exists. */
		bool is_vertex(int);

		/* Checks if an edge exists. */
		bool is_edge(int, int);

		/* Returns the degree of a vertex. */
		int degree(int);

		/* Gets all vertices. */
		std::unordered_set<int> vertices();

		/* Gets the neighbours of a vertex. */
		std::vector<int> neighbours(int);

		/* Adds an edge. */
		void add_edge(int, int);

		/* Removes an edge if it exists. */
		void remove_edge(int, int);

		/* Adds a vertex. */
		void add_vertex(int);

		/* Removes a vertex if it exists. */
		void remove_vertex(int);

	protected:
		int N_, M_;
		std::unordered_set<int> vertices_;
		std::unordered_map<int, std::vector<int> > neighbours_;
};

#endif /* UNDIRECTEDGRAPH_H_ */
