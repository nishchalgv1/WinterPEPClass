#include <iostream>
#include <vector>
#include "treeNode.h"
using namespace std;

int main(){
    TreeNode* root = new TreeNode(1);
    TreeNode* node1 = new TreeNode(2);
    TreeNode* node2 = new TreeNode(3);
    TreeNode* node3 = new TreeNode(4);
    TreeNode* node4 = new TreeNode(5);
    TreeNode* node5 = new TreeNode(6);
    // 1 -> 2, 3
    root ->children.push_back(node1);
    root -> children.push_back(node2);

    //connect 4 and 5 with 3 (node 2)
    node1 -> children.push_back(node3);
    node1 -> children.push_back(node4);

    // connect 3 with 6
    node2 -> children.push_back(node5);
    printTree(root);

}