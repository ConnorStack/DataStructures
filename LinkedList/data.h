/*
 * File: data.h
 * Author: Connor Stack
 */

#ifndef BINTREE_DATA_H
#define BINTREE_DATA_H

#include <string>
using std::string;

struct Data {
    int id;
    string data;
};

struct Node {
    Data data;
    Node *next, *prev;
};

#endif /* DATA_H */
