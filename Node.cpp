/*
 * Node.cpp
 *
 *  Created on: Jun. 27, 2022
 *      Author: liu
 */

#include "Node.h"
#include <iostream>
using namespace std;

int Node::objCount=0;

Node::Node() {

   objCount++;
   cout << "default constructor of Node is invoked" <<endl;  // probing message

}

Node::Node(short id, double value){
	this->id = id;
	this->weight = value;

	 objCount++;

	cout << "constructor with args of Node is invoked" <<endl; // probing message
}


Node::~Node(){
	objCount--;

	cout << "destructor is invoked" <<endl; // probing message
}

void Node::setId(short value){
  this->id = value;

}



Node Node::clone() {
 Node v;
 v.id = this->id;

 return v;

}

int Node::getObjCount() {
	return  objCount;
}

short Node::getId() const{
	return id;
}


double Node::getWeight() const{
	return weight;
}


void Node::setWeight(double value){
	weight = value;

}
//Node::~Node() {
//	// TODO Auto-generated destructor stub
//}
//
Node::Node(const Node& other) {

	this->id = other.id;
//	this->id = other.getId();// error!
	this->weight = other.weight;

	this->objCount++;
	cout << "copy constructor is invoked" <<endl; // probing message

}

Node& Node::operator=(const Node &other) {
	id = other.id;
	weight = other.weight;
	cout << "assignment operator is invoked" <<endl; // probing message
	return *this;

//	this->id = other.id;
//	this->weight = other.weight;

//	cout << "assignment operator is invoked" <<endl; // probing message
//	return *this;
}

