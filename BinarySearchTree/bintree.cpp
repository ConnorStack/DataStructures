/*
 * File: bintree.cpp
 * Author: Connor Stack
 */

#include "bintree.h"
#include <iostream>
using std::cout;
using std::endl;

//Constructor sets root to null
 BinTree::BinTree(){
     count = 0;
     root = NULL;
 }

BinTree::~BinTree(){
    
}
//if tree is empty, returns true
bool BinTree::isEmpty(){
    bool isEmpty = false;
    if(root==NULL){
        isEmpty = true;
    }
    return isEmpty;
}
//returns private attribute count value
int BinTree::getCount(){
    return count;
}
//passes an empty container to fill with roots id and information data
bool BinTree::getRootData(Data* node){
   bool filled = false;
    if(root){
        filled = true;
        node->id = root->data.id;
        node->information = root->data.information;
    }else{
        node->id = -1;
        node->information = "";
    }
    return filled;
}
//displays if empty, the height, count, and displays Pre, In, and Post order methods
void BinTree::displayTree(){
   if(isEmpty()){
        cout << "Tree is empty" << endl;
    }else{
        cout << "Tree is NOT empty" << endl;
    }
    cout << "Height " << getHeight() <<  endl;
    cout << "Node count: " << count << endl;
    cout << endl;
    cout << "Pre-Order Traversal "<< endl;
    displayPreOrder();
    cout << endl;
    cout << "In-Order Traversal "  << endl;
    displayInOrder();
    cout << endl;
    cout << "Post-Order Traversal " << endl;
    displayPostOrder();
    cout << endl;
}
//calls clear
void BinTree::clear(){
    clear(root);
    root = NULL;
}

//Clears tree 
void BinTree::clear(DataNode *root){
    if(root){
        clear(root->left);
        clear(root->right);
        root->left = NULL;
        root->right = NULL;
        delete root;
        count--;
    }
}
//adds a node, id must be greater than zero and string must be non empty
bool BinTree::addNode(int index, const string* info){
    bool valid = false;
    if((index >= 0) && (*info != "")){
        valid = true;
        DataNode * newNode = new DataNode;
        newNode->data.id = index;
        newNode->data.information = *info;
        newNode->left = NULL;
        newNode->right = NULL;
        if(addNode(newNode, &root)){ 
            count++;
            valid = true;
        }
    }
    return valid;
}
//adds nodes to tree, follows left heavy guidelines with binary search
bool BinTree::addNode(DataNode* node, DataNode** newRoot){
    bool valid = false;
    if(!(*newRoot)){
        *newRoot = node;
        valid = true;
    }else if(node->data.id != (*newRoot)->data.id){ 
        if(node->data.id < (*newRoot)->data.id ){
            if(addNode(node, &(*newRoot)->left)){
                valid = true;
            }
        }else if(node->data.id > (*newRoot)->data.id){
            if(addNode(node, &(*newRoot)->right)){
                valid = true;
            }
        }

    }
    return valid;
}
//validates id is greater than zero and calls getNode method
bool BinTree::getNode(Data* incommingData, int id){
    bool valid = false;
    if(id > 0){
        if(getNode(incommingData, id, root)){
            valid = true;
        }
    }
    return valid;
}
//Returns the data at a specific node of the tree given an id
bool BinTree::getNode(Data* incomingData, int id, DataNode* newRoot){
    bool valid;
    if(!(newRoot)){
        valid = false;
    }else if (newRoot){
        if (newRoot->data.id == id){
            valid = true;
            incomingData->id = newRoot->data.id; 
            incomingData->information = newRoot->data.information;
        }else{
            if(newRoot->data.id > id){
                if(getNode(incomingData, id, newRoot->left)){
                    valid = true;
                }
            }
            else if(newRoot->data.id < id){
                if(getNode(incomingData, id, newRoot->right)){
                    valid = true;
                }
            }
        }
    }
    return valid;
}

//validates id is greater than zero, root is not empty, and calls contains
bool BinTree::contains(int id){
    bool valid = false;
    if((id > 0)&&(root)){
        if(contains(id, root)){ 
            valid = true;
        }
    }
    return valid;
}
//returns true if the id matches a value in the tree
bool BinTree::contains(int id , DataNode* newRoot){
    bool valid = false;
    if(!(newRoot)){
        valid = false;
    }else{
        if (newRoot->data.id == id){
            valid = true;
        }else{
            if(newRoot->data.id > id){
                if(contains(id, newRoot->left)){
                    valid = true;
                }
            }else if(newRoot->data.id < id){
                if(contains(id, newRoot->right)){
                    valid = true;
                }
            }
        }
    }
    return valid;
}
//calls getHeight
int BinTree::getHeight(){
    int result = getHeight(root);
    return result;
}
//finds the height of the tree, from top down
int BinTree::getHeight(DataNode* tempRoot){ 
    int leftHeight = 0;
    int rightHeight = 0;
    int result = 0;

    if(!(tempRoot)){
        result = 0;
    }else if(tempRoot){
        if(tempRoot->left){
            leftHeight = getHeight(tempRoot->left);
        }
        if(tempRoot->right){
            rightHeight = getHeight(tempRoot->right);
        }
        result = std::max(leftHeight, rightHeight) + 1;
    }
    return result;
}
//uses count to determine if a node has been removed. Calls removeNode 
bool BinTree::removeNode(int id){
    int tempcount = count;
    bool success = false;
    root = removeNode(id, root);
    if (count < tempcount){
        success = true;
    }
    return success;
}

//Removes a node at a given position. Uses binary search and minValueNode method
DataNode* BinTree::removeNode(int id, DataNode* tempRoot){
    if(tempRoot !=  NULL){
        if(id < tempRoot->data.id){
            tempRoot->left = removeNode(id, tempRoot->left);
        }else if(id > tempRoot->data.id ){
            tempRoot->right = removeNode(id, tempRoot->right);
        }
        else{
            DataNode *temp; 
            if(tempRoot->left == NULL){
                temp = tempRoot->right;
                delete tempRoot;
                tempRoot = temp;
                count--;
            }
            else if(tempRoot->right == NULL){
                temp = tempRoot->left;
                delete tempRoot;
                tempRoot = temp;
                count--;
            }
            else{
                temp = minValueNode(tempRoot->right);
                root->data.id = temp->data.id;
                root->data.information = temp->data.information;
                root->right = removeNode(root->data.id, root->right); 
            }

        }
    }
    return tempRoot;
}
//Determines to node to replace the final conditional statement in removeNode
DataNode* BinTree::minValueNode(DataNode* node){
    DataNode * current = node;
    while (current && current->left != NULL){
        current = current->left;
    }
    return current;
}

//calls displayPreOrder
void BinTree::displayPreOrder(){
    displayPreOrder(root);
}
//follows preorder convention
void BinTree::displayPreOrder(DataNode* tempRoot){
    if(tempRoot){
        cout << tempRoot->data.id << " " << tempRoot->data.information << endl;
        if(tempRoot->left){
            displayPreOrder(tempRoot->left);
        }
        if(tempRoot->right){
            displayPreOrder(tempRoot->right);
        }
    }else{
        return;
    }
}
//calls displayPostOrder
void BinTree::displayPostOrder(){
    displayPostOrder(root);
}
//follows postorder convention
void BinTree::displayPostOrder(DataNode* tempRoot){
    if(tempRoot){
        displayPostOrder(tempRoot->left);
        displayPostOrder(tempRoot->right);
        cout << tempRoot->data.id << " " << tempRoot->data.information << endl;
    }
}
//calls displayInOrder
void BinTree::displayInOrder(){
    displayInOrder(root);

}
//follows InOrder convention
void BinTree::displayInOrder(DataNode* tempRoot){
     
    if (tempRoot) {
        displayInOrder(tempRoot->left);
        cout << tempRoot->data.id << " " << tempRoot->data.information << endl;
        displayInOrder(tempRoot->right);
        
    }
}
