/*
 * File: main.cpp
 * Author: Connor Stack
 */

#include "main.h"

int main() {
    srand(time(NULL));

    const int testdatasize = BASE + (rand() % OFFSET + 1);
    int ids[testdatasize];
    string strs[testdatasize];
    
    char buffer[BUFFERSIZE];
    for (int i = 0; i < testdatasize; i++) {
        ids[i] = rand() % MAXID + 1;
        for (int j = 0; j < BUFFERSIZE - 1; j++) {
            buffer[j] = 'a' + i;
        }
        buffer[BUFFERSIZE - 1] = '\0';
        strs[i] = buffer;
    }
    ids[testdatasize-2] = ids[testdatasize-3];
    strs[testdatasize-2] = "known duplicate";
    ids[testdatasize-1] = - 1;
    strs[testdatasize-1] = "known bad";
    
    cout << "Showing Test Data (" << testdatasize << " entries)..." << endl;
    for (int i = 0; i < testdatasize; i++) {
        cout << ids[i] << " : " << strs[i] << endl;
    }
    cout << endl;

    cout << "Creating hashtable object..." << endl;
    Hashtable hashtable;

    cout << "Constructed...calling getCount on empty hashtable. " << endl;
    cout << hashtable.getCount() << endl;
    cout << endl;
    cout << "Calling printTable on empty hashtable. " << endl;
    hashtable.printTable();
    cout << endl;

    cout << "Filling table with random data..." << endl;
    for(int i = 0; i < testdatasize; i++){
        cout << "adding..." << ids[i] << ": " << strs[i];
        if(hashtable.insertEntry(ids[i], &strs[i])){
            cout << " success" << endl;
        }
        else{
            cout << " failed" << endl;
        }
    }
    cout << endl;
    cout << "Finding valid entries with getCount = " << hashtable.getCount() <<endl;
    cout << endl;
    cout << "Calling printTable on filled table. " << endl;
    hashtable.printTable();
    cout << endl;
    cout << "Checking getData at random positions..." << endl;
    for(int i = 0; i < testdatasize; i++){
        int rand_position = rand() % (testdatasize-1);
        if(hashtable.getData(ids[rand_position]) == "" ){
            cout << "Checking data at id: "<< ids[rand_position] << " = no data" << endl;
        }
        else{
            cout << "Checking data at id: "<< ids[rand_position]<< " = " << hashtable.getData(ids[rand_position]) << endl;
        }
    }
    cout << "Finding valid entries with getCount = " << hashtable.getCount() <<endl;

    cout << endl;
    cout <<"Removing entries..." << endl;
    cout << endl;
    for(int i = 0; i < testdatasize; i++){
        cout << "removing..." << ids[i] ;
        if(hashtable.removeEntry(ids[i])){
            cout << " success" << endl;
        }
        else{
            cout << " failed " << endl; 
        }
    }
    cout <<endl;
    cout << "verify list count = " << hashtable.getCount() << endl;
    cout << endl;
    cout << "Removing on empty list..." << endl;
    for(int i = 0; i < testdatasize; i++){
        cout << "removing..." << ids[i] ;
        if(hashtable.removeEntry(ids[i])){
            cout << " success" << endl;
        }
        else{
            cout << " failed " << endl; 
        }
    }
    cout << endl;
    cout << "verify list count = " << hashtable.getCount() << endl;
    cout << endl;
    cout << "Checking getData at random positions on empty list..." << endl;
    for(int i = 0; i < testdatasize; i++){
        int rand_position = rand() % testdatasize-1;
        if(hashtable.getData(ids[rand_position]) == "" ){
            cout << "Checking data at id: "<< ids[rand_position] << " = no data" << endl;
        }
        else{
            cout << "Checking data at id: "<< ids[rand_position]<< " = " << hashtable.getData(ids[rand_position]) << endl;
        }
    }
    cout << endl;

    cout << "Finding valid entries with getCount = " << hashtable.getCount() <<endl;
    cout << "Printing empty table..." << endl;
    hashtable.printTable();
    cout << endl;

    cout << "Re-filling table with random data..." << endl;
    for(int i = 0; i < testdatasize; i++){
        cout << "adding..." << ids[i] << ": " << strs[i];
        if(hashtable.insertEntry(ids[i], &strs[i])){
            cout << " success" << endl;
        }
        else{
            cout << " failed" << endl;
        }
    }
    cout << endl;
    cout << "verify list count = " << hashtable.getCount() << endl;
    cout << "Printing filled  data..." << endl;
    hashtable.printTable();
    cout << endl;

    cout << "Adding a list of duplicates..." << endl;
    for(int i = 0; i < testdatasize; i++){
        cout << "adding..." << ids[i] << ": " << strs[i];
        if(hashtable.insertEntry(ids[i], &strs[i])){
            cout << " success" << endl;
        }
        else{
            cout << " failed" << endl;
        }
    }
    cout << endl;
    cout << "verify list count = " << hashtable.getCount() << endl;
    cout << endl;
    hashtable.printTable();
    cout << endl;
    cout << "Clearing list." << endl;
    for(int i = 0; i < testdatasize; i++){
        cout << "removing..." << ids[i] ;
        if(hashtable.removeEntry(ids[i])){
            cout << " success" << endl;
        }
        else{
            cout << " failed " << endl; 
        }
    }
    cout << endl;
    hashtable.printTable();
    cout << endl;
    cout << "Final count: " << hashtable.getCount() << endl;
    
    return 0;
}
