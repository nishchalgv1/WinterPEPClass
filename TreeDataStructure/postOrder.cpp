#include <bits/stdc++.h>
#include "Node.h"
using namespace std;
class Solution {
    void solve(TreeNode* root, vector<int>& postorder){
        // base case
        if(root == NULL) return;

        solve(root -> left, postorder);
        solve(root -> right, postorder);
        postorder.push_back(root -> val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        solve(root, postorder);
        return postorder;
    }
};