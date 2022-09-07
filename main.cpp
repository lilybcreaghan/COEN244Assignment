/*
 *  main.cpp
 *  Due on: Sunday August 7
 *  Author: Marissa Profetto, Lily Creaghan
 *  Student ID: 40113513, 40200924
 */
#include "MyGraph.h"
#include "Vertex.h"
#include "Edge.h"
#include <vector>
#include <iostream>
#include <cassert>
using namespace std;

void testVertex(){

    // 1. check default constructor
    Vertex v;
    assert(v.getId() == -1);
    assert(v.getValue() == -1);

    // 2. Check for parameterized constructor
    Vertex v2(0,1.5);
    assert(v2.getId() == 0);
    assert(v2.getValue() == 1.5);

    // 3. Copy constructor
    Vertex v3(v2);
    assert(v3.getId() == 0);
    assert(v3.getValue() == 1.5);

    // 4. = operator
    Vertex v4(1,2.25);
    Vertex v5 = v4;
    assert(v5.getId() == 1);
    assert(v5.getValue() == 2.25);


    // 5. get and set
    Vertex v6;
    v6.setId(2);
    v6.setValue(6.25);
    assert(v6.getId() == 2);
    assert(v6.getValue() == 6.25);

}


void testEdge(){
    Vertex v1(0,1.5);
    Vertex v2(1,2.25);
    Vertex v3(2,6.25);
    Vertex v4(3,12.75);

    // 1. default constructor
    Edge e1;
    assert(e1.getWeight() == 0);
    assert(e1.getStart().getId() == -1);
    assert(e1.getEnd().getId() == -1);

    // 2. parameterized constructor
    Edge e2(20, v1, v2);
    assert(e2.getWeight() == 20);
    assert(e2.getStart().getId() == v1.getId());
    assert(e2.getEnd().getId() == v2.getId());

    // 3. copy constructor
    Edge e3(e2);
    assert(e3.getWeight() == 20);
    assert(e3.getStart().getId() == e2.getStart().getId());
    assert(e3.getEnd().getId() == e2.getEnd().getId());

    // 4. = operatopr
    Edge e4(30, v3, v4);
    Edge e5 = e4;
    assert(e5.getWeight() == 30);
    assert(e5.getStart().getId() == e4.getStart().getId());
    assert(e5.getEnd().getId() == e4.getEnd().getId());

    //5. get and set
    Edge e6;
    e6.setWeight(15);
    e6.setStart(v3);
    e6.setEnd(v4);
    assert(e6.getWeight() == 15);
    assert(e6.getStart().getId() == v3.getId());
    assert(e6.getEnd().getId() == v4.getId());

}

void testMyGraph(){
    // graph
    Vertex v1(0,1.5);
    Vertex v2(1,2.25);
    Vertex v3(2,6.25);
    Vertex v4(3,12.75);
    Vertex v5(4,11.5);
    Vertex v6(5,8.75);

    // add vertices to this graph
    // Graph : [v1, v2, v3, v4], []
    MyGraph graph;
    graph.addVertex(v1);
    graph.addVertex(v2);
    graph.addVertex(v3);
    graph.addVertex(v4);

    // 1. Add vertex
    assert(graph.searchVertex(v1));
    assert(graph.searchVertex(v2));
    assert(graph.searchVertex(v3));
    assert(graph.searchVertex(v4));

    // 2. Add edges
    // 2. add edges with vertices present in the graph
    Edge e1(10, v1, v2);
    Edge e2(15, v3, v4);
    Edge e3(5, v1, v3);
    Edge e4(5, v2, v4);

    assert(graph.addEdge(e1));
    assert(graph.addEdge(e2));
    assert(graph.addEdge(e3));
    assert(graph.addEdge(e4));

    // 3. try to add duplicate edgs
    assert(!graph.addEdge(e1));
    assert(!graph.addEdge(e2));
    assert(!graph.addEdge(e3));
    assert(!graph.addEdge(e4));

    // 4. Try to add edges with vertices not present in the graph
    Edge e5(5, v5, v6);
    Edge e6(5, v6, v4);
    Edge e7(5, v4, v5);

    assert(!graph.addEdge(e5));
    assert(!graph.addEdge(e6));
    assert(!graph.addEdge(e7));
    
    //5. search edge present int the graph
    assert(graph.searchEdge(e1));
    assert(graph.searchEdge(e2));
    assert(graph.searchEdge(e3));
    assert(graph.searchEdge(e4));

    // 6. Search for edges ot present in the graph
    assert(!graph.searchEdge(e5));
    assert(!graph.searchEdge(e6));
    assert(!graph.searchEdge(e7));

    // 7. remove a vertex not present in the graph
    assert(!graph.removeVertex(v5.getId()));
    assert(!graph.removeVertex(v6.getId()));
    assert(!graph.removeVertex(1000));

    // 8. remove a vertex present in the graph
    // remove vertex v1 should also remove edge e1 and edge e3
    assert(graph.removeVertex(v1.getId()));
    assert(!graph.searchEdge(e1));
    assert(!graph.searchEdge(e3));
    assert(!graph.searchVertex(v1));
    // try to remove vertex again - should be false
    assert(!graph.removeVertex(v1.getId()));

    // 9. removing an edge which is present
    assert(graph.remove(e2));
    assert(!graph.searchEdge(e2));
    assert(graph.searchVertex(v3));
    assert(graph.searchVertex(v4));

    // 10. removing an edge which is not present
    assert(!graph.remove(e2));
    assert(!graph.remove(e5));

    // 1. check to strig
    graph.addVertex(v1);
    graph.addVertex(v2);
    graph.addVertex(v3);
    graph.addVertex(v4);
    graph.addEdge(e1);
    graph.addEdge(e2);
    graph.addEdge(e3);
    graph.addEdge(e4);
    //graph.display();

    string g = "1 : [3,w=5]\n2 : [3,w=15]\n3 : \n0 : [1,w=10][2,w=5]\n";
    assert(g == graph.toString());

}

void testException(){
    MyGraph graph1;
    Vertex v1 = Vertex(1,10.0);
    //graph1.addVertex(v1);
    try {
        graph1.display();
    }
    catch(std::runtime_error & re){
        cout << re.what() << endl;
    }
}

void testEquals(){
    Vertex v1(0,1.5);
    Vertex v2(1,2.25);
    Vertex v3(2,6.25);
    Vertex v4(3,12.75);

    Edge e1(10, v1, v2);
    Edge e2(15, v3, v4);
    Edge e3(5, v1, v3);
    Edge e4(5, v2, v4);

    // add vertices to this graph
    // Graph : [v1, v2, v3, v4], []
    MyGraph graph1;
    graph1.addVertex(v1);
    graph1.addVertex(v2);
    graph1.addVertex(v3);
    graph1.addVertex(v4);

    graph1.addEdge(e1);
    graph1.addEdge(e2);
    graph1.addEdge(e3);
    graph1.addEdge(e4);

    MyGraph graph2(graph1);

    assert(graph1 == graph2);
}

void testAssign(){
    Vertex v1(0,1.5);
    Vertex v2(1,2.25);
    Vertex v3(2,6.25);
    Vertex v4(3,12.75);

    Edge e1(10, v1, v2);
    Edge e2(15, v3, v4);
    Edge e3(5, v1, v3);
    Edge e4(5, v2, v4);

    // add vertices to this graph
    // Graph : [v1, v2, v3, v4], []
    MyGraph graph1;
    graph1.addVertex(v1);
    graph1.addVertex(v2);
    graph1.addVertex(v3);
    graph1.addVertex(v4);

    graph1.addEdge(e1);
    graph1.addEdge(e2);
    graph1.addEdge(e3);
    graph1.addEdge(e4);

    MyGraph graph2 = graph1;
    assert(graph1 == graph2);

    MyGraph emptyGraph;
    graph1.clean();
    assert(graph1 == emptyGraph);
}

void testIncrement(){
    Vertex v1(0,1.5);
    Vertex v2(1,2.25);
    Vertex v3(2,6.25);
    Vertex v4(3,12.75);

    Edge e1(10, v1, v2);
    Edge e2(15, v3, v4);
    Edge e3(5, v1, v3);
    Edge e4(5, v2, v4);

    // add vertices to this graph
    // Graph : [v1, v2, v3, v4], []
    MyGraph graph1;
    graph1.addVertex(v1);
    graph1.addVertex(v2);
    graph1.addVertex(v3);
    graph1.addVertex(v4);

    graph1.addEdge(e1);
    graph1.addEdge(e2);
    graph1.addEdge(e3);
    graph1.addEdge(e4);

    // check pre increment
    MyGraph temp = graph1;
    MyGraph graph2 = ++graph1;
    
    Edge e1_i = e1;
    ++e1_i;
    Edge e2_i = e2;
    ++e2_i;
    Edge e3_i = e3;
    ++e3_i;
    Edge e4_i = e4;
    ++e4_i;

    assert(graph1.searchEdge(e1_i));
    assert(graph1.searchEdge(e2_i));
    assert(graph1.searchEdge(e3_i));
    assert(graph1.searchEdge(e4_i));
    assert(!graph1.searchEdge(e1));
    assert(!graph1.searchEdge(e2));
    assert(!graph1.searchEdge(e3));
    assert(!graph1.searchEdge(e4));

    assert(graph2.searchEdge(e1_i));
    assert(graph2.searchEdge(e2_i));
    assert(graph2.searchEdge(e3_i));
    assert(graph2.searchEdge(e4_i));
    assert(!graph2.searchEdge(e1));
    assert(!graph2.searchEdge(e2));
    assert(!graph2.searchEdge(e3));
    assert(!graph2.searchEdge(e4));

    graph1 = temp;
    MyGraph graph3 = graph1++;

    assert(temp == graph3);
    assert(graph1 == graph2);
}

void testAdd(){
    Vertex v1(0,1.5);
    Vertex v2(1,2.25);
    Vertex v3(2,6.25);
    Vertex v4(3,12.75);

    Edge e1(10, v1, v2);
    Edge e2(15, v3, v4);
    Edge e3(5, v1, v3);
    Edge e4(5, v2, v4);

    // add vertices to this graph
    // Graph : [v1, v2, v3, v4], []
    MyGraph graph1;
    graph1.addVertex(v1);
    graph1.addVertex(v2);
    graph1.addVertex(v3);
    graph1.addVertex(v4);

    graph1.addEdge(e1);
    graph1.addEdge(e2);
    graph1.addEdge(e3);
    graph1.addEdge(e4);

    Vertex v5(4,1.5);
    Vertex v6(5,2.25);
    Vertex v7(6,6.25);
    Vertex v8(7,12.75);

    Edge e5(10, v5, v7);
    Edge e6(15, v6, v8);
    Edge e7(5, v7, v8);
    Edge e8(5, v5, v6);

    MyGraph graph2;
    graph2.addVertex(v5);
    graph2.addVertex(v6);
    graph2.addVertex(v7);
    graph2.addVertex(v8);

    graph2.addEdge(e5);
    graph2.addEdge(e6);
    graph2.addEdge(e7);
    graph2.addEdge(e8);

    MyGraph graph3 = graph1 + graph2;

    assert(graph3.searchVertex(v1));
    assert(graph3.searchVertex(v2));
    assert(graph3.searchVertex(v3));
    assert(graph3.searchVertex(v4));
    assert(graph3.searchVertex(v5));
    assert(graph3.searchVertex(v6));
    assert(graph3.searchVertex(v7));
    assert(graph3.searchVertex(v8));

    assert(graph3.searchEdge(e1));
    assert(graph3.searchEdge(e2));
    assert(graph3.searchEdge(e3));
    assert(graph3.searchEdge(e4));
    assert(graph3.searchEdge(e5));
    assert(graph3.searchEdge(e6));
    assert(graph3.searchEdge(e7));
    assert(graph3.searchEdge(e8));
}

void testIndex(){
    Vertex v1(0,1.5);
    Vertex v2(1,2.25);
    Vertex v3(2,6.25);
    Vertex v4(3,12.75);

    Edge e1(10, v1, v2);
    Edge e2(15, v3, v4);
    Edge e3(5, v1, v3);
    Edge e4(5, v2, v4);

    // add vertices to this graph
    // Graph : [v1, v2, v3, v4], []
    MyGraph graph1;
    graph1.addVertex(v1);
    graph1.addVertex(v2);
    graph1.addVertex(v3);
    graph1.addVertex(v4);

    graph1.addEdge(e1);
    graph1.addEdge(e2);
    graph1.addEdge(e3);
    graph1.addEdge(e4);

    assert(graph1[0] == v1);
    assert(graph1[1] == v2);
    assert(graph1[2] == v3);
    assert(graph1[3] == v4);

}

void testOutput(){
    Vertex v1(0,1.5);
    Vertex v2(1,2.25);
    Vertex v3(2,6.25);
    Vertex v4(3,12.75);

    Edge e1(10, v1, v2);
    Edge e2(15, v3, v4);
    Edge e3(5, v1, v3);
    Edge e4(5, v2, v4);

    // add vertices to this graph
    // Graph : [v1, v2, v3, v4], []
    MyGraph graph1;
    graph1.addVertex(v1);
    graph1.addVertex(v2);
    graph1.addVertex(v3);
    graph1.addVertex(v4);

    graph1.addEdge(e1);
    graph1.addEdge(e2);
    graph1.addEdge(e3);
    graph1.addEdge(e4);

    cout << graph1 << endl;

}

void testCastString(){
    Vertex v1(0,1.5);
    Vertex v2(1,2.25);
    Vertex v3(2,6.25);
    Vertex v4(3,12.75);

    Edge e1(10, v1, v2);
    Edge e2(15, v3, v4);
    Edge e3(5, v1, v3);
    Edge e4(5, v2, v4);

    // add vertices to this graph
    // Graph : [v1, v2, v3, v4], []
    MyGraph graph1;
    graph1.addVertex(v1);
    graph1.addVertex(v2);
    graph1.addVertex(v3);
    graph1.addVertex(v4);

    graph1.addEdge(e1);
    graph1.addEdge(e2);
    graph1.addEdge(e3);
    graph1.addEdge(e4);

    string s =(string)graph1;
    cout << s << endl;
}
int main() {

    // Vertex c;
    testVertex();
    testEdge();
    testMyGraph();
    testException();
    testEquals();
    testAssign();
    testIncrement();
    testAdd();
    testIndex();
    testOutput();
    testCastString();
    

    //cout << "hello world!" << endl;
    return 0;
}