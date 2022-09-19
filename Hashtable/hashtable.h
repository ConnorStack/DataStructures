/*
 * File: hashtable.h
 * Author: Connor Stack
 */
#ifndef HASHTABLE_H
#define HASHTABLE_H
#include <string>
using std::string;
#include "linkedlist.h"
#define HASHTABLESIZE 15

class Hashtable {

public:
    Hashtable();
    ~Hashtable();

    bool insertEntry(int, string*);
    string getData(int);
    bool removeEntry(int);
    int getCount();
    void printTable();

private:
    int hash(int);
    int count = 0;
    LinkedList *hashtable[HASHTABLESIZE];
};

#endif // HASHTABLE_H
