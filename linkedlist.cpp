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
    current->prev->next= node;  
    current->prev = node;
}

void LinkedList::addTail(Node* node, Node* current, int index,  string* info){
    node->next = NULL;
    node->prev = current;
    current->next = node; //This step sets sets current's next to new node
}

bool LinkedList::addNode(int index, string* info){
    bool valid = false;
    bool istail = false;
    Node * current = head;
    Node * tail;
    if((index >= 0) && (*info != "")){
        valid = true;
        
        while((current) && (!tail)){
            if((index > current->data.id) && (current->next != NULL)){
                tail = current;
                current = current->next;
            }
            else{
                istail = true;
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
        }
        else {
            addTail(node, current, index, info);
        }
    
    }
    return valid;
}

bool LinkedList::deleteNode(int delete_id){
    cout << "inside delete node " << endl;
    cout << delete_id << endl;
    Node* current = head;
    bool found = false;
    while(!found && current){
        if(current->data.id == delete_id){
            if(current->prev == NULL){
                current->next->prev =NULL;
                head->next = current->next; 
                delete current;
            }
            else if(current->next==NULL){
                current->prev->next = NULL;
                current->prev = NULL;
                delete current;
            }
            else{
                current->prev->next = current->next;
                current->next->prev = current->prev;
                delete current;
            }
            found = true;
        }
        else{
           current = current->next;
        }
    }
    return found;
}

bool LinkedList::getNode(int id, Data* outgoing_data){
    bool found = false;
    Node* current = head;
    while(!found && current){
        if(current->data.id == id){
            //outgoing_data->data = current->data.data;
            //outgoing_data->id = current->data.id;
            found = true;
        }
        else{
            current = current->next;
        }
    }
    return found;
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
    
}

bool LinkedList::clearList(){

    return false;
}

bool LinkedList::exists(int id){
    bool found = false;
    Node* current = head;
    while(found &&current){
        if(current->data.id == id){
            found = true;
        }
        else{
            current = current->next;
        }
    }
    return found;
}