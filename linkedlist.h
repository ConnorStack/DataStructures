/*
 * File: linkedlist.h
 * Author: Connor Stack
 */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "data.h"

class LinkedList{
private:
    Node *head;
public:
    bool addNode(int, string*);
    bool deleteNode(int);
    bool getNode(int, Data*);
    void printList(bool = false);
    int getCount();
    bool clearList();
    bool exists(int);

};
#endif //LINKEDLIST_H