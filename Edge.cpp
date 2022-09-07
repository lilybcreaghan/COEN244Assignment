/*
 *  Edge.cpp
 *  Due on: Sunday August 7
 *  Author: Marissa Profetto, Lily Creaghan
 *  Student ID: 40113513, 40200924
 */
#include <iostream>
#include "Vertex.h"
#include "Edge.h"

using namespace std;

Edge::Edge() {
    weight = 0;
    start = Vertex();
    end = Vertex();
}

Edge::Edge(int w, Vertex& s, Vertex& e) {
    weight = w;
    start = s;
    end = e;
}


Edge::Edge(const Edge& e)
{
    this->weight = e.weight;
    this->start = e.start;
    this->end = e.end;

}

Edge& Edge::operator=(const Edge &e) {
    this->weight = e.weight;
    this->start = e.start;
    this->end = e.end;
    return *this;
}



int Edge::getWeight() const {
    return weight;
}

Vertex Edge::getStart() const {
    return start;
}

Vertex Edge::getEnd() const {
    return end;
}


void Edge::setWeight(int w) {
    weight = w;
}

void Edge::setStart(Vertex s) {
    start = s;
}

void Edge::setEnd(Vertex e) {
    end = e;
}

bool Edge::operator==(const Edge& other)
{
    return this->weight == other.weight && this->start == other.start && this->end == other.end;
}

Edge& Edge::operator++()
{
    ++this->weight;

    return *this;
}

Edge Edge::operator++(int)
{
    Edge temp = *this;
     
    ++(*this);

    return temp;
}