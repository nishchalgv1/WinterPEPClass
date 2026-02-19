#include "binaryTreeNode.h"
#include <iostream>
using namespace std;

BinaryTreeNode* takeInput(){
    int rootData;
    cout << "Enter root data: " << endl;
    cin >> rootData;

    if(rootData == -1) return NULL;
    //create the root node
    BinaryTreeNode* root = new BinaryTreeNode(rootData);
    
    BinaryTreeNode* leftChild = takeInput();
    BinaryTreeNode* rightChild = takeInput();
    root -> left = leftChild;
    root -> right = rightChild;

    return root;
}

void printBinaryTree(BinaryTreeNode* root){
    // base case
    if(root == NULL) return;

    cout << root -> data << ":";

    if(root -> left != NULL){
        cout << "L" << root -> left -> data << " ";
    }

    if(root -> right != NULL){
        cout << "R" << root -> right -> data << " ";
    }
    cout << endl;
    printBinaryTree(root -> left);
    printBinaryTree(root -> right);
}

int main(){
    BinaryTreeNode* root = takeInput();
    printBinaryTree(root);
}