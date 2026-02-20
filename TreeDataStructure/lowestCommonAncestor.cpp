#include <bits/stdc++.h>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // We'll be doing dfs traversal left and then right
        // whenever we find root is p or either q root is the ans
        // if from one side we are getting NULL or from other side getting not NULL
        // then return not NULL
        // if that is not the case we need to return root -> val
        if(root == NULL || root == p || root == q){
            return root;
        }

        TreeNode* left = lowestCommonAncestor(root -> left, p, q);
        TreeNode* right = lowestCommonAncestor(root -> right, p, q);

        if(left == NULL) return right;
        else if(right == NULL) return left;
        else{
            return root; // both left and right are not null, we found our result
        }
    }
};