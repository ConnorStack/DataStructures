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
void LinkedList::addHead(Node * current, int index, string* info){
    Node * newNode = new Node;
    newNode->data.id = index;
    newNode->data.data = *info;

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
void LinkedList::addMiddle(Node* current, int index, string* info){
    Node * node = new Node;
    
    node->data.id = index;
    node->data.data = *info;
  
    node->next = current;
    node->prev = current->prev;
    current->prev->next= node; //Make sure this step is possible. There must be a node before current.
    current->prev = node;

}
bool LinkedList::addNode(int index, string* info){
    //when current id is less than the next id, stop and insert new id
    //if current-> next is null use tail case
    bool addedNode = false;
    Node * current = head;

    cout << endl << "Head memory is: " << head <<endl;//debug only 
    cout << "Current memory is: " << current << endl;//debug only 

    if((index < 0) || (*info == "")){
        cout << "ID must be positive . Info cannot be empty" << endl;//debug only 
        addedNode = false;
    }
    else if((head == NULL ) || (index < current->data.id)){ 
        cout << "inside headnode if-statement "  << endl;//debug only 
        addHead(current, index, info);
        addedNode =  true;
    }
    else if(index > current->data.id){
        while(current != NULL){
            cout << "inside while loop " << endl;
            Node *previous = current->prev; //I plan to use this for the tail case
            
            addMiddle(current, index, info);
            //eventually tail  case, for now a way out of while loop;
            current = NULL; //Just manually adding node until addMiddle is working better
            addedNode = false;
            //traverse list to determine when ID is less than current ID, addMiddle
            //traverse list to determine tail. One idea is to have a current-prev 
            //so when current->NULL current prev can traverse backwards??? Rough plan.
        }
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
