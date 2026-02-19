#include <iostream>
#include <vector>
using namespace std;

class TreeNode{
    public:
    int data;
    vector<TreeNode*> children;

    // constructor
    TreeNode(int data){
        this -> data = data;
    }
};

void printTree(TreeNode* root){
    // base case
    if(root == NULL){
        return;
    }

    // print root's data'
    cout << root -> data << ":";
    for(int i = 0; i < root -> children.size(); ++i){
        cout << root -> children[i] -> data  << " ";
    }
    cout << endl;
    for(int i = 0; i < root -> children.size(); ++i){
        printTree(root -> children[i]);
    }
}
