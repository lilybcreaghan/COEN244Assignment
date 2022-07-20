/*
 * NodeList.cpp
 *
 *  Created on: Jun. 29, 2022
 *      Author: liu
 */

#include "NodeList.h"

NodeList::NodeList() {
	items = new Node[LIST_SIZE];  // initialize the array as a number of nodes;


}

NodeList::~NodeList() {
	delete[] items;  // clean up and release the memory space created!
}

NodeList::NodeList(const NodeList &other) {

	init(other);
//
//	items = new Node[LIST_SIZE]; //make the initialization of the array;
//
//	//element wise one-by-one copy;
//	this->numItems = other.numItems;
//
//	for (int i=0;i<numItems;i++){
//		items[i] = other.items[i];
//	}

}

void NodeList::addNode(Node& n){
	if(numItems<LIST_SIZE){
		items[numItems] = n;
		numItems++;
	}


}

void NodeList::init(const NodeList &other){

	items = new Node[LIST_SIZE];

		this->numItems = other.numItems;
		for (int i=0;i<numItems;i++){
			items[i] = other.items[i];
		}


}

NodeList& NodeList::operator=(const NodeList &other) {
	init(other);

	return *this;


}

int NodeList::getNumItems() const{
	return this->numItems;
}
