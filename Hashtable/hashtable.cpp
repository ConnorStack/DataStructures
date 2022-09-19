/*
 * File: hashtable.cpp
 * Author: Connor Stack
 */
#include "hashtable.h"

//Construct an array of size HASHTABLESIZE, fill it with Linkedlist objects.
Hashtable::Hashtable(){
    for(int i = 0; i < HASHTABLESIZE; i++){
        hashtable[i] = new LinkedList;
    }
    
}

//Destructor deletes each object in the array.
Hashtable::~Hashtable(){
    for (int i = 0; i < HASHTABLESIZE; i++){
        if(hashtable){
            delete hashtable[i];
            hashtable[i] = nullptr;   
        }
    }
}

/* Use the addNode method in  the LinkedList class to add nodes. 
The list is organized via hashtable methods. Insert entry with
hash to the approprate spot in the array
*/
bool Hashtable::insertEntry(int id, string* data){
    int position = hash(id);
    bool inserted = false;

    if((id > 0) && (*data != "")){
        if(hashtable[position]->addNode(id, data)){
            inserted = true;
            count++;
        }
    }
    return inserted;
}

/*
Get data sends an empty data object into getNode. It is being passed by ref
so a value will be assigned to it in getNode. A string associated with id is returned.
*/
string Hashtable::getData(int id){
    Data str_data;
    string outgoing_str_data = "";
    if(id > 0){
        int position = hash(id);
        if(hashtable[position]->getNode(id, &str_data)){
            outgoing_str_data = str_data.data;
        }
    }
    return outgoing_str_data;
}

/*
Removes the entry connected to value id. Uses Linkedlist's deleteNode method.
*/
bool Hashtable::removeEntry(int id){
    bool found = false;
    if(id > 0){
        int position = hash(id);
        if(hashtable[position]->deleteNode(id)){ 
            found =true;
            count--;
        }
    }
    return found;
}

/*
Simply increments and decrements count depending on add/remove Entry
*/
int Hashtable::getCount(){
    return count;
}

/*
Prints the  hashtable, formatted to look like a table.
*/
void Hashtable::printTable(){
    for(int i = 0; i < HASHTABLESIZE; i++){
        cout << i << " ";             
        hashtable[i]->printList(false);
        cout << endl;
    }
}

/*
simply performs modulo operation on id based on HASHTABLESIZE
*/
int Hashtable::hash(int id){
    return id % HASHTABLESIZE;
}
