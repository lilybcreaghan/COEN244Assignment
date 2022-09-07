/*
 *  Graph.h
 *  Due on: Sunday August 7
 *  Author: Marissa Profetto, Lily Creaghan
 *  Student ID: 40113513, 40200924
 */
#include "Vertex.h"
#include "Edge.h"
using namespace std;

class Graph {
public:
	Graph();
	virtual ~Graph();
	Graph(const Graph& other);
	virtual bool addVertex(Vertex& v) = 0; //add in one vertex; bool returns if it is added successfully.
	//Bonus question: add in a set of vertices; bool retruns if it is added successfully
	//virtual bool addVertices(Vertex* vArray) = 0;
	virtual bool removeVertex(int vertexID) = 0;  //the edges that has connection with this vertex need to be removed; 
	//as a result, some node may remain as orphan.
	virtual bool addEdge(Edge& e) = 0; //add an edge to the graph; if an edge already exists, return false;
	//Bonus question : remove a set of edge; as a result, some node may remain as orphan.
	//virtual bool addEdges(Edge* eArray) = 0;
	virtual bool remove(Edge& e) = 0;  // remove the edge
	virtual bool searchVertex(const Vertex& v) const = 0;  // return bool if a vertex exists in a graph;
	virtual bool searchEdge(const Edge& e) const = 0;  // return bool if a Edge exists in a graph;
	//Bonus question: display the path that contains the vertex;
	//virtual void display(Vertex& v) const = 0;
	//Bonus question: display the path that contains the edge;
	//virtual void display(Edge& e) const = 0;
	virtual void display() const = 0;  // display the whole graph with your own defined format
	virtual string toString() const = 0;  // convert the whole graph to a string such as 1-2-4-5; 1-3-5; each path is separated by ';'
	// define your own format of a string representation of the graph.
	virtual bool clean() = 0; //remove all the vertices and edges;

	vector<Vertex*> getVertices();	
	
};
