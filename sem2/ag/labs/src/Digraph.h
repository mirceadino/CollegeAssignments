#ifndef DIGRAPH_H_
#define DIGRAPH_H_

#include <vector>
#include <unordered_set>
#include <unordered_map>

class Digraph {
	public:
		/* Default constructor. */
		Digraph();

		/* Constructor for a graph with a certain number of vertices, but no edges. */
		Digraph(int);

		/* Copy constructor. */
		Digraph(const Digraph&);

		/* Destructor. */
		~Digraph();

		/* Assignment operator. */
		Digraph& operator=(const Digraph&);

		/* Transposes the graph i.e. switches edges' orientation. */
		void transpose();

		/* Returns the number of vertices. */
		int number_of_vertices();

		/* Returns the number of edges. */
		int number_of_edges();

		/* Checks if a vertex exists. */
		bool is_vertex(int);

		/* Checks if an edge exists. */
		bool is_edge(int, int);

		/* Returns the in-degree of a vertex. */
		int indegree(int);

		/* Returns the out-degree of a vertex. */
		int outdegree(int);

		/* Gets all vertices. */
		std::unordered_set<int> vertices();

		/* Gets the in-neighbours of a vertex. */
		std::vector<int> in_neighbours(int);

		/* Gets the out-neighbours of a vertex. */
		std::vector<int> out_neighbours(int);

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
		std::unordered_map<int, std::vector<int> > in_neighbours_;
		std::unordered_map<int, std::vector<int> > out_neighbours_;
};

#endif /* DIGRAPH_H_ */
