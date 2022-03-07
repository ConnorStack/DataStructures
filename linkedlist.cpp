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

bool LinkedList::addNode(int index, string* info){
    /*cout << "Inside addNode " << endl;
    Node *current = head;
    Node *node = new Node;
    
    if(node->data.id > index){
        current = current->next;
    }
    else if(node->data.id < index){
        node->next = current;
        node->prev = current->prev;
        current->prev->next = node;
        current->prev = node;
    }
    */
    return false;
}

bool LinkedList::deleteNode(int){

    return false;
}

bool LinkedList::getNode(int, Data*){

    return false;
}

void LinkedList::printList(bool backward){
    cout << "Inside printList " << endl;
    Node *current = head;
    cout << "Head mem in printlist: " << head <<endl;
    if (!backward){
        while(current){
            cout << current->data.id << " : " << current->data.data << endl;
            current = current->next;
        }
    }
    else{
        //need to reverse the list
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
