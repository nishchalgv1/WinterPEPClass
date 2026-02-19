// gfg
#include <bits/stdc++.h>
#include "Node.h"
using namespace std;

class Solution {
    int height(TreeNode* root){
        // base case
        if(root == NULL) return 0;
        
        int leftHeight = height(root -> left);
        int rightHeight = height(root -> right);
        
        return  1 + max(leftHeight, rightHeight);
    }
  public:
    int diameter(TreeNode* root) {
        // code here
        if(root == NULL) return 0;
        
        // calculate the left height
        int option1 = height(root -> left) + height(root -> right);
        
        int leftDiameter = diameter(root -> left);
        int rightDiameter = diameter(root -> right);
        return max(option1, max(leftDiameter, rightDiameter));
        
    }
};