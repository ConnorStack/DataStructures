/*
 * File: stack.cpp
 * Dynamic stack that accepts integer and string values.
 */


#include "stack.h"

//Constructor takes sizeInitializer and creates an array of pointers of that size. Sets top = -1.
Stack::Stack(int sizeInitializer){
    if(sizeInitializer > 1){
        stack = new Data*[sizeInitializer];
        size = sizeInitializer;
        top = -1;
    }
    else{
        throw 1;
    }
}
//Deallocate memory in our empty stack
Stack::~Stack(){
    delete[] stack;
} 

//Checks if stack is empty, if top = -1, stack is empty.
bool Stack::isEmpty() {
    return top < 0;
}

//Function pushes a randInt and randStr set in main. Stack receives a pointer to the information stored in Data. 
//Stack is incremented by 1
bool Stack::push(int randInt, string& randStr){
    bool pushed = false;
    if(top < size - 1){
        Data *data;
        data = new Data;
        data->id = randInt;
        data->information = randStr;
        stack[++top] = data;
        pushed =true;
    }
    return pushed;
}


//If top is atleast 0, the information at top is stored in an empty Data popdata, memory in deallocated from stack
//Stack is decremented by 1
bool Stack::pop(Data& popdata){
    bool popped = false;
    if (top >= 0) {
        popdata.id = stack[top]->id;
        popdata.information = stack[top]->information;
        delete stack[top];
        top--;
        popped = true;
    }
    return popped;
}

//Peek is similar to pop but no memory is deallocated.
bool Stack::peek(Data& popdata){
    bool peeked = false;
    if (top >= 0) {
        popdata.id = stack[top]->id;
        popdata.information = stack[top]->information;
        peeked = true;
    }
    return peeked;
}
