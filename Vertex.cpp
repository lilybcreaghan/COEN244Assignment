/*
 *  Vertex.cpp
 *  Due on: Sunday August 7
 *  Author: Marissa Profetto, Lily Creaghan
 *  Student ID: 40113513, 40200924
 */
#include <iostream>
#include "Vertex.h"

using namespace std;

Vertex::Vertex() {
   // cout << "default constructor of Node is invoked" <<endl;  // probing message
   // setting default values to id and value
   id = -1;
   value = -1;
}

Vertex::Vertex(short id, double value){
	this->id = id;
	this->value = value;

	// cout << "constructor with args of Node is invoked" <<endl; // probing message
}


Vertex::~Vertex(){
	// cout << "destructor is invoked" <<endl; // probing message
}

void Vertex::setId(short value){
  this->id = value;

}


short Vertex::getId() const{
	return id;
}


double Vertex::getValue() const{
	return value;
}


void Vertex::setValue(double value){
	this->value = value;

}

Vertex::Vertex(const Vertex& other) {
	this->id = other.id;
	this->value = other.value;
	// cout << "copy constructor is invoked" <<endl; // probing message
}

Vertex& Vertex::operator=(const Vertex &other) {
	id = other.id;
	value = other.value;
	// cout << "assignment operator is invoked" <<endl; // probing message
	return *this;
}

bool Vertex::operator==(const Vertex& other)
{
	return this->id == other.id && this->value == other.value;
}

