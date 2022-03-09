/*
 * File: linkedlist.cpp
 * Author: Connor Stack
 */
#include "linkedlist.h"

LinkedList::LinkedList(){
    head = NULL;
/*
    Node *node1;
    node1 = new Node;

    Node *node2;
    node2 = new Node;

    Node *node3;
    node3 = new Node;

    node1->data.id=3;
    node1->data.data = "First";

    node2->data.id = 5;
    node2->data.data = "Second";

    node3->data.id = 7;
    node3->data.data = "Third";

    head = node1;
    cout << "Head mem: " << head <<endl;
    node1->prev = NULL;
    node1->next = node2;
    node2->prev  = node1;
    node2->next = node3;
    node3->next = NULL;
    node3->prev = node2;
*/
}

LinkedList::~LinkedList(){

}
void LinkedList::addHead(Node * current, int index, string* info){
    //Prep new node
    Node * newNode = new Node;
    newNode->data.id = index;
    newNode->data.data = *info;

    if(head == NULL){
        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;
    }
    else{
        //Place it in front of current head
        newNode->data.id = index;
        newNode->data.data = *info;
        head->prev = newNode; //head->
        newNode->next = head;
        //Move head to point to new node 
        newNode->prev=NULL;
        head = newNode;
    }

}
bool LinkedList::addNode(int index, string* info){
    //if head = NULL, use headnode case
    //else if head = pointer, check if id of current is >, <, or = to id
    //if current-> next is null use tail case
     //this needs to be changed, new Node should be one of the last things  done, after validation.
    bool addedNode;
    Node * current = head;

    cout << "Head is " << head <<endl;

    if((index < 0) || (*info == "")){
        cout << "ID must be positive . Info cannot be empty" << endl;//debug only 
        addedNode = false;
    }
    else if((head == NULL ) || (index < current->data.id)){ 
        cout << "inside headnode if-statement "  << endl;
        addHead(current, index, info);
        addedNode =  true;
    }
    return addedNode;
}

bool LinkedList::deleteNode(int){

    return false;
}

bool LinkedList::getNode(int, Data*){

    return false;
}

void LinkedList::printList(bool backward){
    Node *current = head;
    bool  tail = false;

    if (!backward){
        while(current){
            cout << current->data.id << " : " << current->data.data << endl;
            current = current->next;
        }
    }
    else{
        while(current && !tail){
            if(current-> next){
                current = current->next;
            }
            else{
                tail = true;
            }
        }
        while(current){
            cout << current->data.id << " : " << current->data.data << endl;
            current = current->prev;
            
        }
    }
}

int LinkedList::getCount(){

    return 0;
}

bool LinkedList::clearList(){

    return false;
}

bool LinkedList::exists(int){

    return false;
}
