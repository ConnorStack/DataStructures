/*
 * File: stack.h
 * Dynamic stack that accepts integer and string values.
 */

#ifndef STACK_H
#define STACK_H

#include "data.h"

class Stack {

public:
    Stack(int);
    ~Stack();

    bool push(int, string&);
    bool pop(Data &);
    bool isEmpty();
    bool peek(Data&);

private:
    int top;
    int size;
    Data **stack;
};

#endif //STACK_H
