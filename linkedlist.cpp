/*
 * File: linkedlist.cpp
 * Author: Connor Stack
 */
#include "linkedlist.h"

LinkedList::LinkedList(){
    //Node *head = NULL;

    Node *node1;
    node1 = new Node;

    Node *node2;
    node2 = new Node;

    Node *node3;
    node3 = new Node;

    node1->data.id=1;
    node1->data.data = "First";

    node2->data.id = 2;
    node2->data.data = "Second";

    node3->data.id = 3;
    node3->data.data = "Third";

    head = node1;
    cout << "Head mem: " << head <<endl;
    node1->prev = NULL;
    node1->next = node2;
    node2->prev  = node1;
    node2->next = node3;
    node3->next = NULL;
    node3->prev = node2;

}

LinkedList::~LinkedList(){

}
void LinkedList::addHead(Node * node, int index, string* info){
    //Prep new node
    //Place it in front of current head
    node->data.id = index;
    node->data.data = *info;

    head->prev = node;
    node->next = head;
    //Move head to point to new node 
    node->prev=NULL;
    head = node;

}
bool LinkedList::addNode(int position, string* info){
    //if head = NULL, use headnode case
    //else if head = pointer, check if id of current is >, <, or = to id
    //if current-> next is null use tail case
    int index = position;
    //string *contents = info;
    Node *newNode = new Node;
    addHead(newNode, index, info);
    return false;
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
