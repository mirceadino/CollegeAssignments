// transforms input from a file from 1-indexed to 0-indexed

#include <bits/stdc++.h>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
	if(argc != 2) {
		cerr << "No arguments.\n";
		return 1;	
	}

	ifstream fin(argv[1]);

	if(!fin.is_open()) {
		cerr << "Invalid file.\n";
		return 2;
	}

	int N, M;
	vector<pair<pair<int,int>,int>> E;

	fin >> N >> M;

	for(int i = 0, x, y, z; i < M; i++) {
		fin >> x >> y >> z;
		x--, y--;
		E.push_back({ {x,y},z});
	}

	fin.close();

	ofstream fout(argv[1]);

	fout << N << " " << M << endl;
	
	for(auto edge: E) {
		int x = edge.first.first;
		int y = edge.first.second;
		int z = edge.second;
		fout << x << " " << y << " " << z << endl;
	}

	return 0;
}
