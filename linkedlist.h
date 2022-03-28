/*
 * File: linkedlist.h
 * Author: Connor Stack
 */
#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include "data.h"
#include<iostream>
using std::cout;
using  std::endl;

class LinkedList{
public:
    LinkedList();
    ~LinkedList();
   
    bool addNode(int, string*);
    bool deleteNode(int);
    bool getNode(int, Data*);
    void printList(bool = false);
    int getCount();
    bool clearList();
    bool exists(int);
private:
    Node *head;
    void addHead(Node*, int, string*);  
    void addMiddle(Node*, Node*, int, string*);  
    void addTail(Node*, Node*, int,  string*);
    bool deleteHead();

};
#endif //LINKEDLIST_H