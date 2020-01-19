////////////////////////////////////////////////////
// Prim's Algorithm - C++ file
// NOTE:		compiled with g++ under Linux
//					no memory leaks detected by valgrind
// Author:	nt-com
////////////////////////////////////////////////////

////////////////////////////////////////////////////
// LIBRARIES
////////////////////////////////////////////////////
#include "prim.h"

////////////////////////////////////////////////////
// METHODS
////////////////////////////////////////////////////

////////////////////////////////////////////////////
// PRIVATE METHODS
////////////////////////////////////////////////////

////////////////////////////////////////////////////
// PUBLIC METHODS
////////////////////////////////////////////////////

prim::prim(unsigned int size) {

	primSize = size;
	parent = new int[primSize];
	keyValue = new int[primSize];
	spTree = new bool[primSize];		

	for(int i = 0; i < primSize; i++) {
		parent[i] = g_UNDEFINED;
		keyValue[i] = g_INFINITY;
		spTree[i] = false;
	}
	
}

prim::~prim() {

	delete [] parent;
	delete [] keyValue;
	delete [] spTree;

}

int prim::getParent(unsigned int index) {
	return parent[index];
}

int prim::getKeyValue(unsigned int index) {
	return keyValue[index];
}

bool prim::getSpTree(unsigned int index) {
	return spTree[index];
}

void prim::setParent(unsigned int index, unsigned int value) {
	parent[index] = value;
}

void prim::setKeyValue(unsigned int index, unsigned int value) {
	keyValue[index] = value;
}

void prim::setSpTree(unsigned int index) {
	spTree[index] = true;
}

int prim::getMinKey(void) {

	int minValue = g_INFINITY;
	int minIndex = g_UNDEFINED;

	for(int v = 0; v < primSize; v++) {
		if( (spTree[v] == false) && (keyValue[v] < minValue) ) {
			minValue = keyValue[v];
			minIndex = v;
		}
	}	

	return minIndex;

}

void prim::print(void) {
		
	cout << "Minimal Spanning Tree:" << endl;
	for(int i = 1; i < primSize; i++) {
		if(parent[i] != g_UNDEFINED) {
			cout << parent[i] << " -> " << i << endl;
		}
	}

}

void prim::primsAlgorithm(graph &g) {

	int currentNode = g_UNDEFINED;
	unsigned int edgeValue = g_INFINITY;

	// change one key value so the node gets picked
	setKeyValue(0,0);	
	setParent(0, g_UNDEFINED);

	cout << "Starting Prim's Algorithm" << endl;

	for(int v = 0; v < g.getSize() - 1; v++) {

		// get the node with the minimum key value
		currentNode = getMinKey();

		// set node as included in spanning tree
		setSpTree(currentNode);

		// update adjacent vertices
		for(int n = 0; n < g.getSize(); n++) {

			edgeValue = g.getWeight(currentNode, n);
			// if there is an edge between the current node and another node
			if( edgeValue ) {
				// if a node is not yet included in spanning tree 
				// if the edge value is smaller than the key value update
				if( (getSpTree(n) == false) && (edgeValue < getKeyValue(n)) ) {
					setParent(n, currentNode);
					setKeyValue(n, edgeValue);
				}
			} // if edgeValue

		} // for inner (n)
			
	} // for outer (v)	

}


////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////


