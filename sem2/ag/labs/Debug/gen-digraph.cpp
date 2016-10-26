#include <set>
#include <vector>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

using namespace std;

int urandom(int limit)
{
	int val = random() / (RAND_MAX/limit);
	if (val >= limit) val = limit-1;
	return val;
}

void add_edges(int m, vector<set<int> >& graph)
{
	int const n = graph.size();
	for(int k=0 ; k<m ; ++k){
		while(true){
			int const i = urandom(n);
			int const j = urandom(n);
			if(i!=j && graph[i].find(j) == graph[i].end()){
				graph[i].insert(j);
				break;
			}
		}
		
	}
}

void generate(int n, int &m, vector<set<int> >& graph)
{
	srand(clock());
	graph.clear();
	graph.resize(n);
	long long n_long = n;
	long long m_long = m;
	long long n2 = n_long * n_long;
	if (2*m_long < n2){
		add_edges(m, graph);
	} else {
		if(m>n2) m=n2;
		add_edges(n*n-m, graph);
		for(int i=0 ; i<n ; ++i){
			set<int> s;
			for(int j=0 ; j<n ; ++j){
				if(graph[i].find(j) == graph[i].end()){
					s.insert(j);
				}
			}
			std::swap(graph[i], s);
		}
	}

	// recount edges
	for(int i=0, m=0 ; i<n ; i++)
		m += graph[i].size(); 
}


int main(int argc, char** argv)
{
	int m, n;
	if(argc!=3 || 1!=sscanf(argv[1], "%d", &n) ||
		1!=sscanf(argv[2], "%d", &m) ){
		fprintf(stderr,
			"Utilizare: gen-digraph nr-vertices nr-edges\n");
		return 1;
	}
	vector<set<int> > graph;
	generate(n, m, graph);
	printf("%d %d\n", n, m);
	for(int i=0 ; i<n ; ++i){
		set<int> const& s(graph[i]);
		for(set<int>::iterator it=s.begin() ; it!=s.end() ; ++it){
			printf("%d %d %d\n", i, *it, urandom(100)+1);
		}
	}
	return 0;
}
