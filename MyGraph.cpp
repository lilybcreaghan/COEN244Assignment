/*
 *  MyGraph.cpp
 *  Due on: Sunday August 7
 *  Author: Marissa Profetto, Lily Creaghan
 *  Student ID: 40113513, 40200924
 */
#include "MyGraph.h"
#include <exception>

MyGraph::MyGraph() {
    // 
}

MyGraph::~MyGraph(){
    // free memory from each of the vertex pointer
    // for ( int i=0; i<vertices.size(); i++ ) {
    //     Vertex * v = vertices[i];
    //     delete v;
    // }

    // // free memory for the edges
    // for(int i=0; i<edges.size(); i++){
    //     Edge * e = edges[i];
    //     delete e;
    // }
    
    // clear the vector
    vertices.clear();
    edges.clear();
}

MyGraph::MyGraph(const MyGraph& other){
    // clear the vertices and edges here
    vertices.clear();
    edges.clear();


    // add vertices first
    for( int i=0; i<other.vertices.size(); i++) {
        // addVertex(other.vertices[i]);
        vertices.push_back(other.vertices[i]);
    }

    // add egdes
    for( int i=0; i<other.edges.size(); i++ ){
        edges.push_back( other.edges[i] );
    }
}

bool MyGraph::addVertex(Vertex& v){
    if( searchVertex(v)) {
        return false;
    }
    vertices.push_back(v);
    return true;
} 
bool MyGraph::removeVertex(int vertexID){
    
    // iterate the set of vertices and look for the vertex with this id
    for(int i=0; i<vertices.size(); i++){
        if(vertices[i].getId() == vertexID){
            // remove the ith entry in this vector
            vertices.erase(vertices.begin()  + i);

            // remove the edges to this vertex
            //  j
            //  0 1 2  3  4 5  
            // [3,7,12,3,5,10]

            //      j
            //  0 1 2 3 4
            // [4,7,3,5,10]

            // iterate the list of edges
            for(int j=0; j<edges.size(); j++){
                // remove this edge if this has a vertex at start or end
                if(edges[j].getStart().getId() == vertexID || edges[j].getEnd().getId() == vertexID){
                    edges.erase(edges.begin() + j);
                    j--;               
                }
            }

            // return true
            return true;
        }
    }
    return false;
}  
bool MyGraph::addEdge(Edge& e){

    // 0 1 2 3 4 5 
    // 0 1 2 3 4 5 6
    // 0 1 2 3 4 5 6 7 

    // 6->7, w = 100

    // 1. make sure that both start and end vertices are ar part of the graph
    if( !searchVertex(e.getStart()) ) {
        return false;
    }
    
    if(!searchVertex(e.getEnd())){
        return false;
    }

    // 2. check if the graph already contains this edge
    if(searchEdge(e)){
        return false;
    }

    // 3. add this edge
    edges.push_back(e);

    return true;

} 
bool MyGraph::remove(Edge& e){
    // remove this edge
    for(int i=0; i < edges.size(); i++){
        if(edges[i].getStart().getId() == e.getStart().getId() && 
            edges[i].getEnd().getId() == e.getEnd().getId() &&
            edges[i].getWeight() == e.getWeight()
        ){
            edges.erase(edges.begin() + i);
            return true;
        }

    }

    return false;
}  // remove the edge
bool MyGraph::searchVertex(const Vertex& v) const{
    for(int i =0; i < vertices.size(); i++){
        if(vertices[i].getId() == v.getId()){
            return true;
        }
        
    }
    return false;

}  // return bool if a vertex exists in a graph;
bool MyGraph::searchEdge(const Edge& e) const{
    for(int i=0; i < edges.size(); i++){
        if(edges[i].getStart().getId() == e.getStart().getId() && 
            edges[i].getEnd().getId() == e.getEnd().getId() &&
            edges[i].getWeight() == e.getWeight()
        ) {
            return true;
        }
    }
    return false;
}
void MyGraph::display() const{
    // 1. Program the code that throws an exception with a message similar to “Graph is  empty” for the member function display(),when there is no vertex in the graph to  display.
    // if the graph is empty
    if( vertices.size() == 0 ){
        throw std::runtime_error("Graph is empty!");
    }

    // print this as an adjacency list
    for( int i=0; i<vertices.size(); i++ ){
        cout << vertices[i].getId() << " : ";

        //list all the nieghbors of this vertex, with their weights
        for( int j=0; j<edges.size(); j++ ){
            if( edges[j].getStart().getId() == vertices[i].getId() ){
                // print this edge
                cout << "[" << edges[j].getEnd().getId() << ",w=" << edges[j].getWeight() << "]";
            }
        }
        cout << endl;
    }
    
}  // display the whole graph with your own defined format
string MyGraph::toString() const{
    string s = "";
    for( int i=0; i<vertices.size(); i++ ){ 
        s += to_string(vertices[i].getId()) +  " : ";

        //list all the nieghbors of this vertex, with their weights
        for( int j=0; j<edges.size(); j++ ){
            if( edges[j].getStart().getId() == vertices[i].getId() ){
                // print this edge
                s += "[" + to_string(edges[j].getEnd().getId()) + 
                 ",w=" + to_string(edges[j].getWeight()) + "]";
            }
        }
        s += "\n";
    }
    return s;

}  
bool MyGraph::clean(){
    vertices.clear();
    edges.clear();
    return true;
} //remove all the vertices and edges;



//no longer virtual, so we can implement in graph.cpp

bool operator == (const MyGraph & lhs,const MyGraph & rhs){

    if (lhs.edges.size() == rhs.edges.size() && lhs.vertices.size() == rhs.vertices.size())
    {
        for(int i = 0; i < lhs.edges.size(); i++){
            Edge e = lhs.edges[i];
            if(!rhs.searchEdge(e)){
                return false;
            }
        }

        for(int i = 0; i < lhs.vertices.size(); i++){
            Vertex v = lhs.vertices[i];
            if(!rhs.searchVertex(v)){
                return false;
            }
        }

        return true;
    }

    return false;
}

MyGraph& MyGraph::operator=(const MyGraph& rhs)
{
    //clear edges and vertices
    this->vertices.clear();
    this->edges.clear();

    for(int i = 0; i<rhs.edges.size(); i++){
        this->edges.push_back(rhs.edges[i]);
    }

    for(int i = 0; i<rhs.vertices.size(); i++){
        this->vertices.push_back(rhs.vertices[i]);
    }

    return *this;
}

MyGraph& MyGraph::operator++()
{
    for(int i = 0; i < edges.size(); i++){
        int w = edges[i].getWeight();    
        this->edges[i].setWeight(w+1);
    }
  
    return *this;
}

MyGraph MyGraph::operator++(int i)
{
    // for(int i = 0; i < edges.size(); i++){
    //     int w = edges[i].getWeight();    
    //     this->edges[i].setWeight(w+1);
    // }
    MyGraph g = *this;
    ++(*this);
    return g;
}

MyGraph operator+(const MyGraph& lhs, const MyGraph& rhs)
{
    MyGraph sum;
    for(int i = 0; i < lhs.vertices.size(); i++){
        Vertex v = lhs.vertices[i];
        sum.addVertex(v);
    }

    for(int i = 0; i < rhs.vertices.size(); i++){
        Vertex v = rhs.vertices[i];
        sum.addVertex(v);
    }
    
    for(int i = 0; i < lhs.edges.size(); i++){
        Edge e = lhs.edges[i];
        sum.addEdge(e);
    }

    for(int i = 0; i < rhs.edges.size(); i++){
        Edge e = rhs.edges[i];
        sum.addEdge(e);
    }
    return sum;
}

 Vertex& MyGraph::operator [] (int index){
    return this->vertices[index];
 }

ostream& operator << (ostream & lhs, const MyGraph & rhs){
    lhs << rhs.toString();
    return lhs;
 }

MyGraph::operator string() const {
    string s = "";
    for(int i =  0; i<edges.size(); i++){
        s += to_string(edges[i].getStart().getId()) + "->" + to_string(edges[i].getEnd().getId()) + "[" + to_string(edges[i].getWeight()) + "]\n";
    }

    return s;
}
