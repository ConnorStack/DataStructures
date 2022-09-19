/*
 * File: main.cpp
 * Main file is used to test our dynamic stack that accepts strings and integers
 */

#include "main.h"

int main(int argc, char **argv) {
    
    srand(time(NULL));
    int size;
    
    if(argc <= ARGCSET){
        cout << "Include at least one digit. " <<endl;
    }
    else if(argc > ARGCSET+1){
        cout << "Do not add more than one value. " << endl;
    }

    else if(inputIntOnly(argv[ARGCSET])){
        size = atoi(argv[ARGCSET]);
        Stack stack(size);
        cout << "Size of stack is " << size << endl;

        try{
            Stack stackErrorCheck(size);
        }
        catch(...){
            cout << "ERROR. Constructor did not initiate correctly. Ending program." << endl;
        }

        Data data;
        Data *dataptr = &data;

        cout << "Testing empty operations on isEmpty(), peek() and pop()." << endl << endl;

        if(stack.isEmpty()){
            cout << "Stack is empty" << endl;
        }
        else{
            cout << "Stack is not empty"<< endl;
        }

        if(stack.pop(*dataptr)){
            cout << "Popping: " << data.id << " : " << data.information << endl;
        }
        else{
            cout << "Pop underflow error: stack is empty" << endl;
        }

        if(stack.peek(*dataptr)){
            cout << "Peeking: " << data.id << " : " << data.information << endl;
        }
        else{
            cout << "Peek underflow error: stack is empty" << endl;
        }

 

        cout << endl << "Filling stack with random data, testing against negative integers, and empty strings." << endl << endl;

        int randInt;
        std::string randString;
        
        for(int i = 0; i < size*MULTIPLIER; i++){
            randInt = rand()%2 ? -(i + 1) : i+1;
            rand_string(&randString);

            if(randInt < 0){
                cout << "Error: negative value." << endl;
                if(randString == ""){
                    cout << "and Empty string" << endl;
                }
            }
            else if(randString == ""){
                cout << "Error: empty string." << endl;
            }
            else if(stack.push(randInt, randString)){
                cout << "Pushing value " << randInt << " : " << randString << endl; 
            }
            else {
            cout << "Overflow error. " << randInt << " : " << randString << " not pushed." << endl;
            }
        }

        
        cout << endl << "Peeking at the last item popped..." << endl << endl;

        if(stack.peek(*dataptr)){
            cout << "Peeking: " << data.id << " : " << data.information << endl;
        }
        else{
            cout << "Peek underflow error: stack is empty" << endl;
        }

        cout << "Popping all items in stack." << endl << endl;
   
        while(!stack.isEmpty()){
            if(stack.pop(*dataptr)){
                cout << "Popping: " << data.id << " : " << data.information << endl;
             }
            else{
                cout << "Pop underflow error: stack is empty" << endl;
            }
        }
        

        cout << endl << "Attempting to peek after emptying stack" << endl;
        if(stack.peek(*dataptr)){
            cout << "Peeking: " << data.id << " : " << data.information << endl;
        }
        else{
            cout << "Peek underflow error: stack is empty" << endl;
        }

        cout << "Attempting to pop after emptying stack." << endl;

         if(stack.pop(*dataptr)){
            cout << "Popping: " << data.id << " : " << data.information << endl;
        }
        else{
            cout << "Pop underflow error: stack is empty" << endl;
        }
        

        cout << "Filling stack half way" << endl << endl;
        
        
        for(int i = 0; i < size/2; i++){
            randInt = rand()%2 ? -(i + 1) : i+1;
            rand_string(&randString);

            if(randInt < 0){
                cout << "Error: negative value." << endl;
                if(randString == ""){
                    cout << "and Empty string" << endl;
                }
            }
            else if(randString == ""){
                cout << "Error: empty string." << endl;
            }
            else if(stack.push(randInt, randString)){
                cout << "Pushing value " << randInt << " : " << randString << endl; 
            }
            else {
                cout << "Overflow error. " << randInt << " : " << randString << " not pushed." << endl;
            }
        }
        cout << endl;
        
        cout << "Testing peek and pop on a partially filled stack" << endl << endl;

        if(stack.peek(*dataptr)){
            cout << "Peeking: " << data.id << " : " << data.information << endl;
        }
        else{
            cout << "Peek underflow error: stack is empty" << endl;
        }
        if(stack.pop(*dataptr)){
            cout << "Popping: " << data.id << " : " << data.information << endl;
        }
        else{
            cout << "Pop underflow error: stack is empty" << endl;
        }

        cout << "Emptying stack if anything remains."  << endl;

        while(!stack.isEmpty()){
            if(stack.pop(*dataptr)){
                cout << "Popping: " << data.id << " : " << data.information << endl;
             }
            else{
                cout << "Pop underflow error: stack is empty" << endl;
            }
        }
        if(stack.isEmpty()){
            cout << "Stack is empty" << endl;
        }
        else{
            cout << "Stack is not empty"<< endl;
        }
        cout << endl << "Testing Push past its limit" << endl << endl;

        
        for(int i = 0; i < size*LOOPMULTIPLIER; i++){
            randInt = rand()%2 ? -(i + 1) : i+1;
            rand_string(&randString);

            if(randInt < 0){
                cout << "Error: negative value." << endl;
                if(randString == ""){
                    cout << "and Empty string" << endl;
                }
            }
            else if(randString == ""){
                cout << "Error: empty string." << endl;
            }
            else if(stack.push(randInt, randString)){
                cout << "Pushing value " << randInt << " : " << randString << endl; 
            }
            else {
                cout << "Overflow error. " << randInt << " : " << randString << " not pushed." << endl;
            }
        }


        cout << endl << "Peeking and popping when stack is at capacity" << endl;
        if(stack.peek(*dataptr)){
            cout << "Peeking: " << data.id << " : " << data.information << endl;
        }
        else{
            cout << "Peek underflow error: stack is empty" << endl;
        }
        if(stack.pop(*dataptr)){
            cout << "Popping: " << data.id << " : " << data.information << endl;
        }
        else{
            cout << "Pop underflow error: stack is empty" << endl;
        }

        cout << endl << "Emptying Stack" << endl;
        while(!stack.isEmpty()){
            if(stack.pop(*dataptr)){
                cout << "Popping: " << data.id << " : " << data.information << endl;
             }
            else{
                cout << "Pop underflow error: stack is empty" << endl;
            }
        }
        if(stack.isEmpty()){
            cout << "Stack is empty" << endl;
        }
        else{
            cout << "Stack is not empty"<< endl;
        }

        cout << endl << "Random testing" << endl << endl;

        int choice = rand() % RANDOPTION + 1;
        for (int i = 0; i < size*LOOPMULTIPLIER; i++) {
            randInt = rand()%2 ? -(i + 1) : i+1;
            rand_string(&randString);

            switch (choice) {
                case 1:
                    cout << "Push: " <<endl;
                    if(randInt < 0){
                        cout << "Error: negative value." << endl;
                        if(randString == ""){
                            cout << "and Empty string" << endl;
                        }
                    }
                    else if(stack.push(randInt, randString)) {
                        cout << "Pushed: " << randInt << " : " << randString << endl;
                    }else {
                        cout << "Overflow error: " << randInt << " : " << randString << " not pushed" << endl;
                    }
                    break;
                case 2:
                    cout << "Pop: " <<endl;
                    if(stack.pop(*dataptr)){
                        cout << "Popping: " << data.id << " : " << data.information << endl;
                    }
                    else{
                        cout << "Pop underflow error: stack is empty" << endl;
                    }
                    break;
                case 3:
                    cout << "Peek: " <<endl;
                    if(stack.peek(*dataptr)){
                        cout << "Peeking: " << data.id << " : " << data.information << endl;
                    }
                     else{
                        cout << "Peek underflow error: stack is empty" << endl;
                    }
                    break;
                case 4:
                    cout << "isEmpty: " <<endl;
                    if (stack.isEmpty()) {
                        cout << "Stack is empty" << endl;
                    } else {
                        cout << "Stack is not empty" << endl;
                    }
                    break;
            }
            choice = rand() % RANDOPTION + 1;
        }
        cout << endl << "Random testing finished" << endl << endl;
        cout << "Emptying contents" <<endl;
            while(!stack.isEmpty()){
            try{
                stack.pop(data);
                cout << "Popped: " << data.id << " : " << data.information << endl;
            }catch(...){
                cout << "Pop underflow error: stack is empty" << endl;
            }
        }
        if(stack.isEmpty()){
            cout << "Stack is empty" << endl;
        }
        else{
            cout << "Stack is not empty"<< endl;
        }
    }
    else{
        cout << "Invalid entry" << endl; 
    }

    return 0;
    
}
