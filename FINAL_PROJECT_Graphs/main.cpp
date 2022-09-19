/*
 * File: main.cpp
 * Author: Connor Stack
 */

#include "main.h"


int main(){

    srand(time(NULL));
    int i, randInt, randInt2, randLetter, randLetter2;
    string s("ABCDEFGHIJKLMNOPQRSTUVWXYZ");
    string badstr("abcdefghijklmnopqrstuvwxyz");
    string randString, randString2, nonRandString;
    char p[s.length()];
    Data tmpData;

    cout << "=======================================================================================" <<endl;
    cout << "This is a graph ADT that used a vector of vertices and a parallel vector of struct edges." << endl <<endl;
    cout << "Testing methods on an empty graph." << endl;
    cout << endl;
    cout << "=======================================================================================" <<endl;
    cout << "Constructing graph object..." << endl << endl;

    Graph graph;
    cout << "Constructed" << endl << endl; 
    randInt = rand() % SIZE_ALPHABET;
    randInt2 = rand() % SIZE_ALPHABET;
    randString = s[randInt];
    randString2 = s[randInt2];

    if(graph.isEmpty()){
        cout << "Graph is empty..." << endl;
    }else{
        cout << "Graph is not empty..." << endl;
    }
    cout << endl;

    cout << "Printing empty vertices" << endl;
    graph.printVertices();
    cout << "Printing empty edges" << endl;
    graph.printEdges();
    cout << endl;

    cout << "VertexCount on empty graph: " << graph.getVertexCount() << endl;
    cout << "EdgeCount on empty graph: " << graph.getEdgeCount() << endl;
    cout << endl;

    cout << "getEdge on empty graph" << endl;
    if(graph.getEdge(&randString, &randString2, &tmpData)){
        cout << "Edge: "<< randString2 << " on vertex: " << randString << " [" << tmpData.data << " : " << tmpData.id << "]" << endl;
    }else{
        cout << "...edge not found" << endl;
    }
    cout << endl;

    cout << "getVertexValue on empty graph" << endl;
    
    if(graph.getVertexValue(randInt)==""){
        cout << "...vertex does not exist" << endl;
    }else{
        graph.getVertexValue(randInt);
    }
    cout << endl;
    cout << "Using clearVertex on empty graph" << endl;
    if(graph.clearVertex(&randString)){
        cout << "Position exists, but shouldn't" << endl;
    }else{
        cout << "...nothing to clear" << endl;
    }
    cout << endl;
    cout << "Using removeOneEdge on empty graph" << endl;
    if(graph.removeOneEdge(&randString, &randString2)){
        cout << "Position exists, but shouldn't" << endl;
    }else{
        cout <<"...nothing to remove" << endl;
    }
    cout << endl;
    
    cout << "=======================================================================================" <<endl;
    cout << "Testing Graph methods on a smaller scale..." << endl;
    cout << endl;
    cout << "=======================================================================================" <<endl;
    cout << "Adding vertex values in alphabetical order..." << endl << endl;
    for (i = 0; i < QUARTER_ALPHABET; i++){
        nonRandString = s[i];
        graph.addVertex(&nonRandString);
    }
    cout << "Printing filled vertices..."<< endl << endl;
    graph.printVertices();
    cout << endl;
    cout << "=================================================================" << endl;
    cout << "Bad data testing" << endl;
    
    int badInt = (rand () % (NUMBERSET)) * -1;
    randLetter = rand() % QUARTER_ALPHABET;
    randLetter2 = rand() % QUARTER_ALPHABET;
    randString = s[randLetter];
    randString2 = s[randLetter2];

    cout << "Vertex: " << randString << " Edge: " << randString2 << " Weight: " << badInt << endl;
    cout << "Adding edge with bad weight value "<< endl;
    if(graph.addEdge(badInt, &randString, &randString2)){
        cout << "success" << endl;
    }else{
        cout << "failed" << endl;
    }

    randInt = rand() % NUMBERSET;
    randString = "";
    cout << "Adding edge with empty vertex value." << endl;
    if(graph.addEdge(randInt, &randString, &randString2)){
        cout << "success" << endl;
    }else{
        cout << "failed" << endl;
    }
    

    randLetter = rand() % QUARTER_ALPHABET;
    randString = s[randLetter];
    randString2 = "";
    cout << "Adding edge with empty edge value." << endl;
    if(graph.addEdge(randInt, &randString, &randString2)){
        cout << "success" << endl;
    }else{
        cout << "failed" << endl;
    }

    randString = "";
    randString2 = "";
    cout << "Adding edge with empty edge AND empty vertex value." << endl;
    if(graph.addEdge(randInt, &randString, &randString2)){
        cout << "success" << endl;
    }else{
        cout << "failed" << endl;
    }

    randString = badstr[randLetter];
    cout << "Adding edge with bad data: "<< randString << endl;
    if(graph.addEdge(randInt, &randString, &randString2)){
        cout << "success" << endl;
    }else{
        cout << "failed" << endl;
    }

    randString2 = badstr[randLetter2];
    cout << "Adding edge with bad vertex value data: " << randString2 << endl;
    if(graph.addEdge(randInt, &randString, &randString2)){
        cout << "success" << endl;
    }else{
        cout << "failed" << endl;
    }
    cout << "=================================================================" << endl;
   

    cout << "Printing edges on vertex with no edges..." << endl;
    graph.printEdges();
    cout << "Edgecount: " << graph.getEdgeCount() << endl;
    cout << endl;
    cout << "INPUT DATA: " << endl;
    cout << "Duplicate vertecies will fail, and edges already shared will fail" << endl;
    for(i=0; i < HALFSIZE; i++){ 
        randInt = rand () % NUMBERSET;
        randLetter = rand() % QUARTER_ALPHABET;
        randLetter2 = rand() % QUARTER_ALPHABET;
        randString = s[randLetter];
        randString2 = s[randLetter2];
        cout << "Vertex: " << randString << " Edge: " << randString2 << "...";

        if(graph.addEdge(randInt, &randString, &randString2)){
            cout << "success" << endl;
        }else{
            cout << "failed" << endl;
        }
    }

    cout << endl;
    cout << "Printing filled graph" << endl;
    cout << "Edgecount: " << graph.getEdgeCount() << endl;

    cout << endl;
    graph.printEdges();
    cout << endl;

    cout << "Randomly checking getEdge on filled graph, and then testing removeOneEdge on that edge. " << endl;
    cout << "If found, the edge and its bidirectional counterpart will be removed. " << endl;
    cout << endl;
    for(i=0; i < QUARTER_ALPHABET; i++){
        randLetter = rand() % QUARTER_ALPHABET;
        randLetter2 = rand() % QUARTER_ALPHABET;
        randString = s[randLetter];
        randString2 = s[randLetter2];
        cout << "Searching vertex: " << randString << " for: " << randString2 << "...";

        if(graph.getEdge(&randString, &randString2, &tmpData)){
            cout << "Found : [" << tmpData.data << " : " << tmpData.id << "]" << endl;
            if(graph.removeOneEdge(&randString, &randString2)){
                cout << "...removing " << randString2 << " : " << randString << " bidirectionally" << endl;
            }else{
                cout << "remove edge failed." <<endl;
            }
        }else{
            cout << "edge not found" << endl;
        }
    }
    cout << endl;
    cout << "Graph after removals" << endl;
    cout << "Edgecount: " << graph.getEdgeCount() << endl;
    cout << endl;
    graph.printEdges();
    cout << endl;

    cout << "Testing isEmpty on a filled graph" <<endl;
    if(graph.isEmpty()){
        cout << "Graph is empty..." << endl;
    }else{
        cout << "Graph is not empty..." << endl;
    }
   
    cout << "Edgecount: " << graph.getEdgeCount() << endl;

    cout << "Removing SINGLE vertex ";
    randLetter = rand() % QUARTER_ALPHABET;
    randString = s[randLetter];
    cout << " : " << randString << endl;
    graph.clearVertex(&randString);
    cout << "Printing graph after vertex removal. " << endl;
    cout << endl;
    graph.printEdges();
    cout << endl;

    cout << "Edgecount: " << graph.getEdgeCount() << endl;
    
    cout << "Clearing multiple vertices." <<endl;
    for (i = 0; i < QUARTER_ALPHABET; i++){
        randString = s[i];
        cout << "Removing vertex: " << randString << "...";
        if(graph.clearVertex(&randString)){
            cout << "success" << endl;
        }else{
            cout << "failed" << endl;
        }
        graph.printEdges();
        cout << endl;
    }
    
    cout << "VertexCount: " << graph.getVertexCount() << endl;
    cout << "EdgeCount: " << graph.getEdgeCount() << endl;
    cout << endl;
    graph.clearGraph();
    cout << "Using clearGraph to clear graph" << endl;
    cout << "VertexCount: " << graph.getVertexCount() << endl;
    cout << "EdgeCount: " << graph.getEdgeCount() << endl;
    cout << endl;
    graph.printEdges();
    


    for (i = 0; i < QUARTER_ALPHABET; i++){
        nonRandString = s[i];
        graph.addVertex(&nonRandString);
    }

    for(i=0; i < QUARTER_ALPHABET; i++){ 
        randInt = rand () % NUMBERSET;
        randString = s[i];
        for(int j = 0; j < QUARTER_ALPHABET; j++){
            randString2 = s[j];
            graph.addEdge(randInt, &randString, &randString2);
        }
    }
    cout << "Printing fully filled vertices..."<< endl << endl;
    graph.printEdges();

    cout << "Attempting to add all duplicate vertices" << endl;
    for (i = 0; i < QUARTER_ALPHABET; i++){
        nonRandString = s[i];
        if(graph.addVertex(&nonRandString)){
            cout << "success" << endl;
        }else{
            cout << "failed"  << endl;
        }
    }

    cout << "Attempting to add edges on filled graph " << endl;
    for(i=0; i < QUARTER_ALPHABET; i++){ 
        randInt = rand () % NUMBERSET;
        randLetter = rand() % QUARTER_ALPHABET;
        randLetter2 = rand() % QUARTER_ALPHABET;
        randString = s[randLetter];
        randString2 = s[randLetter2];
        cout << "Vertex: " << randString << " Edge: " << randString2 << "...";

        if(graph.addEdge(randInt, &randString, &randString2)){
            cout << "success" << endl;
        }else{
            cout << "failed" << endl;
        }
    }
    cout << "Clearing vertices and edges" << endl;
    graph.clearGraph();
    cout << endl;
    cout << "=======================================================================================" <<endl;
    cout << "Testing Graph methods mid-scale in random order..." << endl;
    cout << endl;
    cout << "=======================================================================================" <<endl;
    cout << "Adding vertex values in NON-alphabetical order..." << endl << endl;
    

    for (i = 0; i < SIZE; i++){
        randLetter = rand() % HALF_ALPHABET;
        randString = s[randLetter];
        graph.addVertex(&randString);
    }
    cout << endl;
    cout << "VertexCount: " << graph.getVertexCount() << endl;
    cout << "Adding edge values in random order..." << endl << endl;
    for(i=0; i < NUMBERSET; i++){ 
        randInt = rand () % NUMBERSET;
        randLetter = rand() % HALF_ALPHABET;
        randLetter2 = rand() % HALF_ALPHABET;
        randString = s[randLetter];
        randString2 = s[randLetter2];
        cout << "Vertex: " << randString << " Edge: " << randString2 << "...";

        if(graph.addEdge(randInt, &randString, &randString2)){
            cout << "success" << endl;
        }else{
            cout << "failed" << endl;
        }
    }
    cout << endl;
    cout << "EdgeCount on graph: " << graph.getEdgeCount() << endl;
    graph.printEdges();
    cout << endl;

    for(i=0; i < HALF_ALPHABET; i++){
        randLetter = rand() % HALF_ALPHABET;
        randLetter2 = rand() % HALF_ALPHABET;
        randString = s[randLetter];
        randString2 = s[randLetter2];
        cout << "Searching vertex: " << randString << " for edge: " << randString2 << "...";

        if(graph.getEdge(&randString, &randString2, &tmpData)){
            cout << "Found : [" << tmpData.data << " : " << tmpData.id << "]" << endl;
            if(graph.removeOneEdge(&randString, &randString2)){
                cout << "...removing " << randString2 << " : " << randString << " bidrectionally" << endl;
            }else{
                cout << "remove edge failed." <<endl;
            }
        }else{
            cout << "edge not found" << endl;
        }
    }

    cout << endl;
    cout << "EdgeCount on graph: " << graph.getEdgeCount() << endl;
    graph.printEdges();
    cout << endl;

    cout << "Removing SINGLE vertex ";
    randLetter = rand() % SIZE_ALPHABET;
    randString = s[randLetter];
    cout << ": " << randString << endl;
    graph.clearVertex(&randString);

    cout << endl;
    cout << "EdgeCount on graph: " << graph.getEdgeCount() << endl;
    graph.printEdges();
    cout << endl;
    cout << endl;
    cout << "Removing random vertices..." << endl;
    for (i = 0; i < QUARTER_ALPHABET; i++){
        randLetter = rand() % SIZE_ALPHABET;
        randString = s[randLetter];
        cout << "Removing vertex: " << randString << "...";
        if(graph.clearVertex(&randString)){
            cout << "success" << endl;
        }else{
            cout << "failed" << endl;
        }
        cout << endl;
    }
    cout << "graph after multiple vertex removals" << endl;
    cout << "EdgeCount on graph: " << graph.getEdgeCount() << endl;
    graph.printEdges();
    cout << endl;
    cout << "Clearing graph" << endl;
    graph.clearGraph();
    cout << endl;
    cout << "=======================================================================================" <<endl;
    cout << "Testing empty methods again after clearing graph ..." << endl;
    cout << endl;
    cout << "=======================================================================================" <<endl;

   if(graph.isEmpty()){
        cout << "Graph is empty..." << endl;
    }else{
        cout << "Graph is not empty..." << endl;
    }
    cout << endl;

    cout << "Printing empty vertices" << endl;
    graph.printVertices();
    cout << "Printing empty edges" << endl;
    graph.printEdges();
    cout << endl;

    cout << "VertexCount on empty graph: " << graph.getVertexCount() << endl;
    cout << "EdgeCount on empty graph: " << graph.getEdgeCount() << endl;
    cout << endl;

    cout << "getEdge on empty graph" << endl;
    if(graph.getEdge(&randString, &randString2, &tmpData)){
        cout << "Edge: "<< randString2 << " on vertex: " << randString << " [" << tmpData.data << " : " << tmpData.id << "]" << endl;
    }else{
        cout << "...edge not found" << endl;
    }
    cout << endl;

    cout << "getVertexValue on empty graph" << endl;
    
    if(graph.getVertexValue(randInt)==""){
        cout << "...vertex does not exist" << endl;
    }else{
        graph.getVertexValue(randInt);
    }
    cout << endl;
    cout << "Using clearVertex on empty graph" << endl;
    if(graph.clearVertex(&randString)){
        cout << "Position exists, but shouldn't" << endl;
    }else{
        cout << "...nothing to clear" << endl;
    }
    cout << endl;
    cout << "Using removeOneEdge on empty graph" << endl;
    if(graph.removeOneEdge(&randString, &randString2)){
        cout << "Position exists, but shouldn't" << endl;
    }else{
        cout <<"...nothing to remove" << endl;
    }
    cout << endl;
    return 0;   
}

