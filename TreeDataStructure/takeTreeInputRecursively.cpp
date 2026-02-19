#include <iostream>
#include "treeNode.h"
#include <vector>
using namespace std;
 
TreeNode* takeInput(){
    // root Data
    int rootData;
    cout << "Enter root data: " << endl;
    cin >> rootData;

    // create the root node with the rootData
    TreeNode* root = new TreeNode(rootData);

    // no of children of this root from the user
    int numChild;
    cout << "Enter the no of children of " << rootData << ": ";
    cin >> numChild;

    for(int i = 0; i < numChild; ++i){
        TreeNode* child = takeInput();
        root -> children.push_back(child);
    }
    return root;
}

int main(){
    TreeNode* root = takeInput();

    // print the tree
    printTree(root);
}