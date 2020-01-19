////////////////////////////////////////////////////
// PrimType - Header File
// NOTE:		compiled with g++ under Linux
//					no memory leaks detected by valgrind
// Author:	nt-com
////////////////////////////////////////////////////

/// @file prim.h
/// @brief contains the prim's algorithm data structure and operations

#ifndef _PRIM_H_
#define _PRIM_H_

////////////////////////////////////////////////////
// LIBRARIES
////////////////////////////////////////////////////
#include <iostream>
#include "prim_cfg.h"
#include "graph.h"

// NAMESPACE
using namespace std;

////////////////////////////////////////////////////
// CLASSES
////////////////////////////////////////////////////

// PRIM CLASS
// contains data for prims's algorithm and functions
// to operate on the data. 
class prim {
	
	private:
		/// @brief parent nodes of a node
		int *parent;
		/// @brief values to pick values put in the spanning tree 
		int *keyValue;
		/// @brief values not yet included in the spanning tree
		bool *spTree;
		/// @brief size of the underlying graph
		unsigned int primSize;

	public:

		/// @brief constructor
		/// @param size size of the underlying graph, number of nodes
		prim(unsigned int size);
		/// destructor
		~prim();

		// accessor methods
		/// @brief get the parent of a node
		/// @param index index of the node to get parent for
		/// @return parent value of node index
		int getParent(unsigned int index);

		/// @brief get the key value of a node
		/// @param index index of the node to get key value for
		/// @return the key value of the node index	
		int getKeyValue(unsigned int index);

		/// @brief check if a node is in the spanning tree
		/// @param index index of the node to check
		/// @return true if in spanning tree, false otherwise
		bool getSpTree(unsigned int index);

		// mutator methods
		/// @brief sets the parent value for a node
		/// @param index node to set parent value for
		/// @param value the value to set
		/// @return void
		void setParent(unsigned int index, unsigned int value);

		/// @brief sets the key value for a node
		/// @param index node to set parent value for
		/// @param value the value to set
		/// @return void
		void setKeyValue(unsigned int index, unsigned int value);
		
		/// @brief put node in spanning tree
		/// @param index node to put in spanning tree
		/// @return void
		void setSpTree(unsigned int index);

		/// @brief get the node with the minimal key value
		/// @return node with the minimal key value
		int getMinKey(void);
	
		/// @brief prints the calculated minimal spanning tree
		void print(void);

		/// @brief Prim's Algorithm
		/// @param g a connected graph to apply the algorithm to
		/// @return void
		void primsAlgorithm(graph &g); 

};


////////////////////////////////////////////////////
// EOF
////////////////////////////////////////////////////
#endif
