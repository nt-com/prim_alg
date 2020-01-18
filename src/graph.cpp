////////////////////////////////////////////////////
// Graph Data Structure - C++ file
// NOTE:		compiled with g++ under Linux
//					no memory leaks detected by valgrind
// Author:	nt-com
////////////////////////////////////////////////////

////////////////////////////////////////////////////
// LIBRARIES
////////////////////////////////////////////////////
#include "graph.h"

////////////////////////////////////////////////////
// METHODS
////////////////////////////////////////////////////

////////////////////////////////////////////////////
// PRIVATE METHODS
////////////////////////////////////////////////////

////////////////////////////////////////////////////
// PUBLIC METHODS
////////////////////////////////////////////////////
graph::graph(unsigned int size) {

	gSize = size;
	// allocate memory on heap for base pointer
	g = new unsigned int* [gSize];
	
	for(int i = 0; i < gSize; i++) {
		// allocate memory row by row
		g[i] = new unsigned int[gSize];
		for(int j = 0; j < gSize; j++) {
			g[i][j] = 0;
		}
	}

}

graph::~graph() {

	// delete the rows	
	for(int i = 0; i < gSize; i++) {
		delete [] g[i];
	}
	// delete the base pointer
	delete [] g;

}

void graph::print(void) {

	cout << "Adjacency Matrix: " << endl;	
	for(int i = 0; i < gSize; i++) {
		for(int j = 0; j < gSize; j++) {
			// print one row of the matrix
			cout << "\t" << g[i][j] << "\t";
		} // for inner (j)
		cout << endl; // linebreak after row is printed
	} // for outer (i)

}

void graph::generate() {

	for(int i = 0; i < gSize; i++) {
		for(int j = 0; j < gSize; j++) {
			if(i == j) {
				// do not create any loops in the graph
				g[i][j] = 0;
			} else {
				// always generate an edge, results in a complete graph
				g[i][j] = g[j][i] = (rand() % g_MAXIMAL_WEIGHT) + 1;
			}
		} // for inner (j)
	} // for outer (i)

}

unsigned int graph::getSize(void) {
	return gSize;
}

unsigned int graph::getWeight(unsigned int source, unsigned int destination) {
	// if destination is reachable from source, the adjacency matrix contains a weight
	// value > 0, which is also the cost/distance to reach destination from source 
	return g[source][destination];
}

////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////


