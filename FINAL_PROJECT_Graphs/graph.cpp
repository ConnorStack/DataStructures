/*
 * File: graph.cpp
 * Author: Connor Stack
 */
#include "graph.h"

Graph::Graph(){
    vertexCount = 0;
    edgeCount = 0;
    head = NULL;
}

Graph::~Graph(){
    clearGraph();
}

//If there is nothing on the vertex then there are also no edges.
bool Graph::isEmpty(){
    bool exists = false;
    if(vertexCount == 0){
        exists = true;
    }
    return exists;
}

//Calls clear edges and clearAllVertices to completely delete all allocated memory and set pointers to null
void Graph::clearGraph(){
    clearEdges();
    clearAllVertices();
}

//While a valid value exists in edgeList, deleteEdgeHead will be called. 
void Graph::clearEdges(){
    for(int i = 0; i < edgeList.size(); i++){
        Node* current = edgeList[i];
        while(current){
            deleteEdgeHead(i);
            current = current->next;
        }
    }
    edgeList.clear();
    edgeCount=0;
}

//Deletes all nodes in the vector, sets them to null, and clears the vector.
void Graph::clearAllVertices(){

    for(int i = 0; i < vertexList.size(); i++){
        delete vertexList[i];
        vertexList[i] = nullptr;
    }
    vertexList.clear();
    vertexCount = 0;
}

//Deletes elements in the head position of a linked list
bool Graph::deleteEdgeHead(int i){
    bool head_exist;
    if(edgeList[i] == nullptr){
        head_exist = false;
    }
    else{ 
        head_exist = true;
        if(edgeList[i]->next == nullptr){
            edgeList[i] = nullptr;
            }
        else {  
            Node *temp;
            temp = edgeList[i];
            edgeList[i] = edgeList[i]->next;
            delete temp;
            edgeList[i]->prev = nullptr;
        }
    }
    return head_exist;
    
}

//Takes the letter to be stored as a Vertex. Must be capital letter A-Z
bool Graph::addVertex(string* nodeLetter){
    bool duplicate, valid = false;
    for(int i = 0; i < vertexList.size(); i++){
        if (vertexList[i]->data.data == *nodeLetter){
            duplicate = true;
        }
    }
    if(!duplicate){
        if(*nodeLetter >= "A" && *nodeLetter <= "Z"){
            valid = true;
            Node * node = new Node;
            node->data.data = *nodeLetter;
            node->data.id = -1;
            vertexList.push_back(node);
            vertexCount++;
        }  
    }
    return valid;
 }


//Clears a single vertex of all edges
bool Graph::clearVertex(string* vertex){ 
    bool valid = false;
    int position = getVertexPosition(vertex); 
    Node* current = nullptr;
    if(position >= 0){
        current = edgeList[position];
    }
    if(position >= 0 && current){ 
        valid = true;
        deleteSharedEdges(position, vertex, current);
        current = edgeList[position]; 
        while(current){
            deleteEdgeHead(position);
            edgeCount--;
            current  = current->next;
        }
    }

    return valid;
}
//Searches a vector for a given edge and calls delete edge
bool Graph::deleteSharedEdges(int vertPosition, string* edge, Node* current){  
    bool valid = false;
    string edgeval = current->data.data;
    int edgePosition;
    int preCount = edgeCount;
    
    while(current){
        edgeval = current->data.data;
        edgePosition = getVertexPosition(&edgeval); 
        if(deleteEdge(edgePosition, edge)){
            valid = true;
        }
        current = current->next;
    }
   
    return valid;

}
//Given a Vertex and Edge, the vertex is searched for the edge, if it is found delete edge is called
//Then the edges determines what position to search for the bidirectional edge
bool Graph::removeOneEdge(string* vertex, string*edge){
    bool valid = false;
    int vertexPosition = getVertexPosition(vertex);
    int sharedEdge = getVertexPosition(edge);
    if((edgeCount > 0)){ //&& (vertexPosition > 0)){ 
        if(vertexPosition >= 0 && sharedEdge >= 0){
            deleteEdge(vertexPosition, edge);
            deleteEdge(sharedEdge, vertex);
            valid = true;
        }
    }
    return valid;
}
//Given a position and vertex, edgeList is searched for the desired edge value
bool Graph::deleteEdge(int position, string* edge){ 
    
    bool found =false;
    Node * current = edgeList[position]; 
    while(current && !found){ 
        if(current->data.data == *edge){
            if(current->prev == nullptr){
                deleteEdgeHead(position);
            }
            else if(current->next == nullptr){
                current->prev->next = NULL;
                current->prev = NULL;
                delete current;
                current  = nullptr; 
            }
            else{ 
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
                current = nullptr; 
            } 
            found = true;
            edgeCount--;
        }
        else{
            current = current->next;
        }
    }
    return found;
}

//Returns the position of the desired vertex value in vertexList vector
int Graph::getVertexPosition(string* vertexValue){
    int position = -1;
    for(int i = 0; i < vertexList.size(); i++){
        if(vertexList[i]->data.data == *vertexValue){
            position = i;
        }
     }
     return position;
 }
void Graph::prepEdge(){
    while(vertexCount > edgeList.size()){
        edgeList.push_back(nullptr);
    }
}

//checks if a vertex already contains an edge that is being added
bool Graph::duplicateEdge(int position, string* edge){
    Node * current = edgeList[position]; 
    bool duplicate = false;
    while(current){
        if(current->data.data == *edge){
            duplicate = true;
        }
        current = current->next;
    }

    return duplicate;
}

//If the position >= 0, then the vertex exists, weight must be > 0 and edgeposition must be >= 0.
//Checks for duplicate vertices and edges, calls addnode twice for bidirectional edges
bool Graph::addEdge(int weight, string* vertex, string* edge){ 
    bool valid = false;
    int position = getVertexPosition(vertex); 
    int edgePosition = getVertexPosition(edge);  
    if((position >= 0) && (weight > 0) && (edgePosition >= 0)){   
        if(vertexCount > edgeList.size()){
            prepEdge();
        }
        if(position == edgePosition){
        }
        else if(duplicateEdge(position, edge)){
        }
        else{
            valid = true;
        }
     }
    if(valid){
        if(addNode(weight, edge, position)){
            edgeCount++;
        }
        if(addNode(weight, vertex, edgePosition)){
            edgeCount++;
        }
     }
    return valid;
}
//Adds node at the head  if the position exists and string is not empty
bool Graph::addNode(int index, string* info, int position){
    bool valid = false; 
    if((index >= 0) && (*info != "")){
        valid = true;
        Node * node = new Node;
        node->data.id = index;
        node->data.data = *info;
        addHead(node, position);
        
    }
    return valid;
}
//Adds node to head of list 
void Graph::addHead(Node * newNode, int pos){
    if(edgeList[pos] == nullptr){ 
        newNode->next = NULL;
        newNode->prev = NULL; 
        edgeList[pos] = newNode;
    }
    else{
        edgeList[pos]->prev = newNode; 
        newNode->next = edgeList[pos];
        newNode->prev=NULL;
        edgeList[pos] = newNode;
    }
}

//Returns the vertex count
int Graph::getVertexCount(){
   return vertexCount;
}
//Returns the edge count
int Graph::getEdgeCount(){
    return edgeCount;
}

//Returns the Vertex string value
string Graph::getVertexValue(int position){
    string vertex = "";
    if(!vertexList.empty()){
        vertex = vertexList[position]->data.data;
    }
    return vertex;
}

//Returns the contents of an edge in a data object
bool Graph::getEdge(string* vertex, string* edge, Data* outData){
    bool exists = false;
    int position = getVertexPosition(vertex);
    Node* current;
    if(position >= 0 && edgeCount > 0){
        current = edgeList[position];
        while((current) && (!exists)){
            if(current->data.data == *edge){
                exists = true;
                outData->data = current->data.data;
                outData->id = current->data.id;
            }
            else{
                outData->data = "";
                outData->id = -1;
            }
            current = current->next;
        }
    }
    return exists;
}

//Prints all vertices
bool Graph::printVertices(){
    bool filled = false;
    if(!vertexList.empty()){
        filled = true;
        for (int i = 0; i < vertexList.size(); i++){
            cout << vertexList[i]->data.data << endl;
        }
    }
   return filled;
}

//Prints all edges. Prints blank if no edges exist
bool Graph::printEdges(){
    bool valid = false;
    Node * current;
    
    if(edgeCount > 0){
        valid = true;
        for (int i = 0; i < vertexList.size(); i++){
            current = edgeList[i];
            cout << vertexList[i]->data.data;
            while(current){
                cout << "-> [" << current->data.data;
                cout << " : " << current->data.id << "]";
                current = current->next;
            } 
            cout << endl;
        }
    }
    return valid;
}


