/*
 * File: graph.h
 * Author: Connor Stack
 */
#ifndef GRAPH_H
#define GRAPH_H

#include "data.h"
#include <iostream>
#include <vector>

using std::cout;
using std::endl;

class Graph{
public:
    Graph();
    ~Graph();
    bool addVertex(string*);
    bool addEdge(int, string*, string*);
    bool isEmpty();
    bool printVertices();
    bool printEdges();
    int getVertexCount();
    int getEdgeCount();
    string getVertexValue(int);
    bool getEdge(string*, string*, Data*);
    void clearEdges();
    void clearAllVertices();
    bool clearVertex(string*);
    void clearGraph();
    bool removeOneEdge(string*, string*); 

private:
    int vertexCount; 
    int edgeCount;
    std::vector<Node*>edgeList;
    std::vector<Node*>vertexList;
    Node *head;
    int getVertexPosition(string*); 
    bool deleteSharedEdges(int, string*, Node*);
    bool deleteNode(int delete_id);
    bool deleteEdge(int, string*);
    bool duplicateEdge(int, string*);
    void prepEdge();
    bool addNode(int, string*, int);
    void addHead(Node*, int);
    void addTail(Node*);
    bool deleteEdgeHead(int);
    
};

#endif // GRAPH_H
