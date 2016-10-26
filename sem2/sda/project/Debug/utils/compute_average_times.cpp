#include <bits/stdc++.h>

using namespace std;

int main(int argc, char** argv) {
	if(argc != 2)
		return 1;
	freopen(argv[1], "r", stdin);
	char header[300];	
	char junk1[300];	
	char junk2[300];	
	char file[300];
	map<string, double> A, B;
	while(cin.getline(header, 300)) {
		sscanf(header, "%s %s %s", junk1,junk2,file);
		cin.getline(header, 300);
		double time;
		sscanf(header, "%lf", &time);
		A[string(file)] += time;
		cin.getline(header, 300);
		sscanf(header, "%lf", &time);
		B[string(file)] += time;
	}
	for(auto x: A){
		cout << setprecision(5) << fixed;
		cerr << x.first << endl;
		cout << "Building: " << x.second/8.0 << endl;
		cout << "Printing: " << B[x.first] << endl;
	}
	return 0;
}
