#include <iostream>
#include "treeNode.h"
#include <vector>
#include <queue>
using namespace std;

TreeNode* takeInputLevelWise(){
    int rootData;
    cout << "Enter root data: " << endl;
    cin >> rootData;

    TreeNode* root = new TreeNode(rootData);
    // create the queue of TreeNode pointers
    queue<TreeNode*> pendingNodes;
    
    // push the root node in queue
    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        // get the front of the queue
        TreeNode* front = pendingNodes.front();
        pendingNodes.pop();

        // take the children input 
        int numChild;
        cout << "Enter total no of children of " << front -> data << endl;
        cin >> numChild;

        for(int i = 0; i < numChild; ++i){
            // take the child data
            int childData;
            cout << "Enter " << i << " child of " << front -> data << endl;
            cin >> childData;
            //create the child Node with the childData
            TreeNode* child = new TreeNode(childData);
            front -> children.push_back(child);
            // push the child to the queue
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTreeLevelWise(TreeNode* root){
    // base case
    if(root == NULL) return;

    queue<TreeNode*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        // get the front of the queue
        TreeNode* front = pendingNodes.front();
        cout << front -> data << ":";
        pendingNodes.pop();

        // print all the child of front
        for(int i = 0; i < front -> children.size(); ++i){
            cout << front -> children[i] -> data << " ";
            pendingNodes.push(front -> children[i]);
        }
        cout << endl;
    }
}

void printLevelWise2(TreeNode* root){
    // base case
    if(root == NULL) return;

    queue<TreeNode*> pendingNodes;
    pendingNodes.push(root);

    while(!pendingNodes.empty()){
        // get the front of the queue
        int size = pendingNodes.size();
        while(size--){
             TreeNode* front = pendingNodes.front();
            //cout << front -> data << endl;
            pendingNodes.pop();

            // print all the child of front
            for(int i = 0; i < front -> children.size(); ++i){
                cout << front -> children[i] -> data << " ";
                pendingNodes.push(front -> children[i]);
            }
            cout << endl;
        }
    }
}

int main(){
    TreeNode* root = takeInputLevelWise();

    // print the tree
    printLevelWise2(root);
}