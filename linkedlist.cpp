/*
 * File: linkedlist.cpp
 * Author: Connor Stack
 */
#include "linkedlist.h"

LinkedList::LinkedList(){
    head = NULL;
}

LinkedList::~LinkedList(){

}
void LinkedList::addHead(Node * newNode, int index, string* info){
    if(head == NULL){
        newNode->next = NULL;
        newNode->prev = NULL;
        head = newNode;
    }
    else{
        head->prev = newNode; 
        newNode->next = head;
        newNode->prev=NULL;
        head = newNode;
    }
}

void LinkedList::addMiddle(Node* node, Node * current, int index, string* info){
    node->next = current;
    node->prev = current->prev;
    current->prev->next= node;  //This step is giving me issues. Previous is probably pointing to bad data  or null?
    current->prev = node;
}

bool LinkedList::addNode(int index, string* info){
    bool valid = false;
    bool tail = false;
    Node * current = head;
    if((index >= 0) && (*info != "")){
        valid = true;
        while(current && !tail){
            if(index > current->data.id){
                current = current->next;
            }
            else{
                tail = true;
            }
        }
        Node * node = new Node;
        node->data.id = index;
        node->data.data = *info;
        if((head == NULL) || (index < head->data.id)){ //this first case is non transverse.
            addHead(node, index, info);
        }
        else if((index < current->data.id)  && (current != NULL)){
            addMiddle(node, current, index, info);
        }/*
        else {
            addTail(node, index, info);
        }*/
    }
    return valid;
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
/*
bool valid = true;
    Node * current = head;
    int method = 4;
    int * methodptr = &method;
    cout << "current: " << &current << endl;
    while((valid) && (*methodptr >=3)){
        if((index < 0) || (*info =="")){
            valid = false;
        } 
        else if(head == NULL || index < current->data.id){
            *methodptr = 1; //addHead
        }
        else if((index > current->data.id)  && (current->next != NULL)){
            *methodptr = 2; //addMid
            cout << "method 2" << endl;
        }
        else if (current->next == NULL){
            *methodptr = 3; //addTail
        }
    }
    if(valid){
        Node * node = new Node;
        if(*methodptr == 1){
            addHead(node, index, info);
        }
        else  if(*methodptr == 2){
            addMiddle(node, current, index, info);
        }
        else {
            //addTail(node, index, info);
        }
    }
    return valid;*/