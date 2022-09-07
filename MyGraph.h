/*
 *  MyGraph.h
 *  Due on: Sunday August 7
 *  Author: Marissa Profetto, Lily Creaghan
 *  Student ID: 40113513, 40200924
 */
#ifndef MYGRAPH_H
#define MYGRAPH_H

#include <iostream>
#include <vector>
using namespace std;

#include "Graph.h"

class MyGraph : public Graph {      //"public graph" make sure that all the access modifiers are implemented and are the same in MyGraph

public:
    MyGraph();
    ~MyGraph();
    MyGraph(const MyGraph& other);
    bool addVertex(Vertex& v); //add in one vertex; bool returns if it is added successfully.
    //Bonus question: add in a set of vertices; bool retruns if it is added successfully
    //virtual bool addVertices(Vertex* vArray) = 0;
    bool removeVertex(int vertexID);  //the edges that has connection with this vertex need to be removed; 
    //as a result, some node may remain as orphan.
    bool addEdge(Edge& e); //add an edge to the graph; if an edge already exists, return false;
    //Bonus question : remove a set of edge; as a result, some node may remain as orphan.
    //virtual bool addEdges(Edge* eArray) = 0;
    bool remove(Edge& e);  // remove the edge
    bool searchVertex(const Vertex& v) const;  // return bool if a vertex exists in a graph;
    bool searchEdge(const Edge& e) const;  // return bool if a Edge exists in a graph;
    //Bonus question: display the path that contains the vertex;
    //virtual void display(Vertex& v) const = 0;
    //Bonus question: display the path that contains the edge;
    //virtual void display(Edge& e) const = 0;
    void display() const;  // display the whole graph with your own defined format
    string toString() const;  // convert the whole graph to a string such as 1-2-4-5; 1-3-5; each path is separated by ';'
    // define your own format of a string representation of the graph.
    bool clean(); //remove all the vertices and edges;

    //no longer virtual, so we can implement in graph.cpp

    // operator overloads
    friend bool operator == (const MyGraph & lhs,const MyGraph & rhs); //friend (access to private members) when there is lhs and rhs 
    MyGraph& operator = (const MyGraph & rhs);  //operator overload, no need for friend
    MyGraph& operator ++ ();    // pre increment
    MyGraph operator ++ (int); // post increment
    friend MyGraph operator + (const MyGraph & lhs, const MyGraph & rhs);
    Vertex& operator [] (int index);
    friend ostream& operator << (ostream & lhs, const MyGraph & rhs);
    operator string() const;


private:
    // vector <Vertex*> vertices;
    // vector <Edge*> edges;

    vector <Vertex> vertices;
    vector <Edge> edges;
};

#endif