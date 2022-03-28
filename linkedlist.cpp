/*
 * File: linkedlist.cpp
 * Author: Connor Stack
 * 
 * Purpose of this file is to create a  doubly linked list that acts on a coupled int and string*.
 * Items to be placed in ascending order. All positive int and non-empty string. No duplicate int id values.
 */
#include "linkedlist.h"

LinkedList::LinkedList(){
    head = NULL;
}

//Cycle through list starting at head, deleting each node til current=NULL
LinkedList::~LinkedList(){
    this->clearList();
}

//Fist edge case of addNode. Integers coming in are always > 0 and *info is filled with some string.
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

//Standard case. Integers coming in are always > 0 and *info is filled with some string.
void LinkedList::addMiddle(Node* node, Node * current, int index, string* info){
    node->next = current;
    node->prev = current->prev;
    current->prev->next= node;  
    current->prev = node;
}

//Edge case for  addNode, adds a tail to the  linked list. Integers coming in are always > 0 and *info is filled with some string.
void LinkedList::addTail(Node* node, Node* current, int index,  string* info){
    node->next = NULL;
    node->prev = current;
    current->next = node; //This step sets sets current's next to new node
}

//This function only works with postitive integers and non-empty strings. Contradicting data will be ignored.
bool LinkedList::addNode(int index, string* info){
    bool valid = false; 
    bool duplicate = false;
    Node * current = head;
    Node * tail;
    if((index >= 0) && (*info != "")){
        valid = true;
        while(current && valid){
            if(current->data.id == index){
                valid = false;
                duplicate = true;
            }
            else if(index > current->data.id){
                tail = current;
                current = current->next;
            }
            else{
                valid = false;
            }
        }
        if(!duplicate){
            valid = true;
            Node * node = new Node;
            node->data.id = index;
            node->data.data = *info;
            if((head == NULL) || (index <= head->data.id)){ //this first case is non transverse.
                addHead(node, index, info);
            }
            else if (tail->next == NULL){
                addTail(node, tail, index, info);
            }
            else{
                addMiddle(node, current, index, info);
            }
        }
    }
    return valid;
}
/*
deleteHead() should not have anything passed to it. If you are going to delete the head,
you already know where it is, it's the head. You should simply check that head is or is not NULL, 
and if it is not, then check to see if there is another node after it.

That will give you three cases to account for:

Head is null: do nothing, return false.
Head is not null, head->next is null: delete head, set head to null, return true.
Head is not null, head->next is not null: set temp to head, set head to head->next, delete temp
*/

//Edgecase of deleteNode. When head-> prev == NULL, we are at the head. Two edge cases exist inside. When there is only one node, or more.


bool LinkedList::deleteHead(){
    bool head_filled = true;
    Node *temp;
    if(head == NULL){
        head_filled= false;
        //delete head; //When I swap these I get a memory  allocation error
        //head = NULL;
    }
    else if(head->next == NULL){
        //head = head->next; 
        //head->prev = NULL;//current->next->prev = NULL; This code is  essentailly the same thing but not as clear
        delete head;
        head = NULL;
    }
    else if(head->next != NULL){
        temp = head;
        head = head->next;
        delete temp;
    }

    return head_filled;
}

/*
bool LinkedList::deleteHead(){
    bool head_is_null = false;
    if(head != NULL){
        head = head->next; 
        head->prev = NULL;//current->next->prev = NULL; This code is  essentailly the same thing but not as clear
        delete head;
        head = NULL;
    }
    else{
        head_is_null = true;
        delete head; //When I swap these I get a memory  allocation error
        head = NULL;
    }

    return head_is_null;
}
*/

/*
void LinkedList::deleteHead(Node* current){
    if(current->next != NULL){
        head = current->next; 
        head->prev = NULL;//current->next->prev = NULL; This code is  essentailly the same thing but not as clear
        delete current;
        current = NULL;
    }
    else{
        head = NULL;
        delete head; //When I swap these I get a memory  allocation error
    }

    delete current;
}
*/

//deleteNode deletes an item at the specified ID, delete_id will match the id in linked list and delete its contents/deallocate the node.
bool LinkedList::deleteNode(int delete_id){
    //cout << delete_id << endl;
    Node* current = head;
    bool found = false;
    while(!found && current){
        if(current->data.id == delete_id){
            if(current->prev == NULL){
                deleteHead(); //  deleteHead(current);
            }
            else if(current->next == NULL){
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

//Returns data at specified location
bool LinkedList::getNode(int id, Data* outgoing_data){
    bool found = false;
    Node* current = head;
    while(!found && current){
        if(current->data.id == id){
            outgoing_data->data = current->data.data;
            outgoing_data->id = current->data.id;
            found = true;
        }
        else{
            current = current->next;
        }
    }
    return found;
}

//Prints list. If false prints forwards, if true prints backwards.
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

//Returns the  number of items in the linked list.
int LinkedList::getCount(){
    Node * current = head;
    int i = 0;
    while(current){
        i++;
        current = current->next;
    }
    return i;
}

//Deletes all items in linked list
bool LinkedList::clearList(){
    Node * current = head;
    Node * temp;
    while(head){ //while(current)
        //temp = current->next;
        deleteHead(); // deleteHead(current);
        //current = temp;
    }
    return false; //occasional bug, might be because how bool is always returning false.
}

//Returns true if specified item exists.
bool LinkedList::exists(int id){
    bool found = false;
    Node* current = head;
    while(!(found) && current){
        if(current->data.id == id){
            found = true;
        }
        current = current->next;
        
    }
    return found;
}