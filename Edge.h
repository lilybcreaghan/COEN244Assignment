/*
 *  Edge.h
 *  Due on: Sunday August 7
 *  Author: Marissa Profetto, Lily Creaghan
 *  Student ID: 40113513, 40200924
 */
#ifndef EDGE_H
#define EDGE_H

#include <iostream>
#include "Vertex.h" 

class Edge {
public:
    Edge();
    Edge(const Edge& e);
    Edge(int w, Vertex& s, Vertex& e);

    Edge& operator=(const Edge &other);
    bool operator==(const Edge& other);

    Edge& operator++();
    Edge operator++(int);

    int getWeight() const;
    Vertex getStart() const;
    Vertex getEnd() const;

    void setWeight(int);
    void setStart(Vertex);
    void setEnd(Vertex);

    void print();

private:
    int weight;
    Vertex start;
    Vertex end;

};

#endif
