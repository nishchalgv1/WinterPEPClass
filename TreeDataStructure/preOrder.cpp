#include <bits/stdc++.h>
#include "Node.h"
using namespace std;

class Solution {
    void solve(TreeNode* root, vector<int>& preorder){
        // base case
        if(root == NULL) return;

        // add the root's data to the output -> preorder
        preorder.push_back(root -> val);

        solve(root -> left, preorder);
        solve(root -> right, preorder);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        // base case
        vector<int> preorder;
        solve(root, preorder);
        return preorder;
    }
};