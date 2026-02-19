#include <iostream>
class BinaryTreeNode{
    public:
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;
    // constructor
    BinaryTreeNode(int data){
        this -> data = data;
        left = NULL;
        right = NULL;
    }
};