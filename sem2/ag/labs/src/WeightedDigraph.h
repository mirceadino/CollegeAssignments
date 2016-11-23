#ifndef WEIGHTEDDIGRAPH_H_
#define WEIGHTEDDIGRAPH_H_

#include "Digraph.h"
#include <vector>
#include <map>
#include <unordered_set>
#include <unordered_map>

template<typename TProperty>
class WeightedDigraph: public Digraph {
	public:
		/* Default constructor. */
		WeightedDigraph();

		/* Constructor for a graph with a certain number of vertices, but no edges. */
		WeightedDigraph(int);

		/* Copy constructor. */
		WeightedDigraph(WeightedDigraph<TProperty>&);

		/* Destructor. */
		~WeightedDigraph();

		/* Assignment operator. */
		WeightedDigraph<TProperty>& operator=(const WeightedDigraph<TProperty>&);

		/* Transposes the graph i.e. switches edges' orientation. */
		void transpose();

		/* Gets the cost of an edge. */
		TProperty get_cost(int, int);

		/* Sets the cost of an edge. */
		void set_cost(int, int, TProperty);

		/* Adds a weighted edge. */
		void add_edge(int, int, TProperty);

		/* Removes an edge if it exists. */
		void remove_edge(int, int);

		/* Adds a vertex. */
		void add_vertex(int);

		/* Removes a vertex if it exists. */
		void remove_vertex(int);

	protected:
		std::map<std::pair<int, int>, TProperty> costs_;

	private:
		/* OBSOLETE : inherited addition of an unweighted edge, overriden to do nothing. */
		void add_edge(int, int) {
		} // !! OBSOLETE !!
};

#endif /* WEIGHTEDDIGRAPH_H_ */

#ifndef WEIGHTEDDIGRAPH_CPP_

#include "WeightedDigraph.cpp"

#endif
