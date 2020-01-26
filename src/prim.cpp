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
	parent = new vector<int>(primSize);
	keyValue = new vector<int>(primSize); 
	spTree = new vector<bool>(primSize);

	for(int i = 0; i < primSize; i++) {
		parent->at(i) = g_UNDEFINED;
		keyValue->at(i) = g_INFINITY;
		spTree->at(i) = false;
	}
	
}

prim::~prim() {

	delete parent;
	delete keyValue;
	delete spTree;

}

int prim::getParent(unsigned int index) {
	return parent->at(index);
}

int prim::getKeyValue(unsigned int index) {
	return keyValue->at(index);
}

bool prim::getSpTree(unsigned int index) {
	return spTree->at(index);
}

void prim::setParent(unsigned int index, unsigned int value) {
	parent->at(index) = value;
}

void prim::setKeyValue(unsigned int index, unsigned int value) {
	keyValue->at(index) = value;
}

void prim::setSpTree(unsigned int index) {
	spTree->at(index) = true;
}

int prim::getMinKey(void) {

	int minValue = g_INFINITY;
	int minIndex = g_UNDEFINED;

	for(int v = 0; v < primSize; v++) {
		// if a node is not in the spanning tree and it has the minimal
		// edge value among all the other nodes not in the tree, pick it
		if( (spTree->at(v) == false) && (keyValue->at(v) < minValue) ) {
			minValue = keyValue->at(v);
			minIndex = v;
		}
	}	

	return minIndex;

}

void prim::print(void) {

	unsigned int totalCost = 0;
		
	cout << "Minimal Spanning Tree:" << endl;
	for(int i = 1; i < primSize; i++) {
		if(parent->at(i) != g_UNDEFINED) {
			cout << parent->at(i) << " -> " << i << " | cost: " << keyValue->at(i) << endl;
			totalCost += keyValue->at(i);
		}
	}

	cout << "-------------------------" << endl;	
	cout << "Total Cost: " << totalCost << endl;

}

void prim::primsAlgorithm(graph &g) {

	int currentNode = g_UNDEFINED;
	unsigned int edgeValue = g_INFINITY;

	// change one key value so the node gets picked
	setKeyValue(0,0);	
	// the source node has no parent - already done in constructor
	// but if you want to run the algorithm more than one time, for example
	// on multiple graphs, you would need to re-init here.
	// setParent(0, g_UNDEFINED);

	cout << "Starting Prim's Algorithm" << endl;

	for(int v = 0; v < primSize - 1; v++) {

		// get the node with the minimum key value
		currentNode = getMinKey();

		// set node as included in spanning tree
		setSpTree(currentNode);

		// update adjacent vertices
		for(int n = 0; n < g.getSize(); n++) {
			// get the weight value of the edge connecting the current node to it's neighbors
			edgeValue = g.getWeight(currentNode, n);
			// if there is an edge between the current node and another node
			if( edgeValue ) {
				// if a node is not yet included in spanning tree 
				// if the edge value is smaller than the key value update it
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


