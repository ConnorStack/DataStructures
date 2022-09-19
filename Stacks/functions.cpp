/*
 * File: functions.cpp
 * Functions.cpp is made for creating random strings.
 */


#include "functions.h"
//This function creates a random string seven characters long, all uppercase.
void rand_string(std::string *str){
    int rnum = rand() % MAXSTRSIZE;
    char *buffer = new char[rnum+1];
    int i = 0;
    for(; i < rnum; i++){
        buffer[i] = (rand() % ('Z' - 'A' + 1)) + 'A';
    }
    buffer[i] = '\0';
    *str = buffer;
    delete buffer;
    return;
}

// Validates input, input must be all integer values, and the value must be at least = 2.
bool inputIntOnly(char * input){
    int i = 0;
    bool valid = true;
    while((input[i]) != '\0'){
        if(!isdigit(input[i])){
            valid = false;
        }
        i++;
    }
    if(valid == true){
        if( atoi(input) < 2){
            valid = false;
        }
    }
    return valid;
}

