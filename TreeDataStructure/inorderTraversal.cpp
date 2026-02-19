#include <bits/stdc++.h>
#include "Node.h"
using namespace std;
// leetcode
class Solution {
    void solve(TreeNode* root, vector<int>& inorder){
        // base case
        if(root == NULL) return;

        solve(root -> left, inorder);
        inorder.push_back(root -> val);
        solve(root -> right, inorder);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        solve(root, inorder);
        return inorder;
    }
};