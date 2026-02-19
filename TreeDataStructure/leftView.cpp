#include <bits/stdc++.h>
#include "Node.h"
using namespace std;
class Solution {
  public:
    vector<int> leftView(TreeNode *root) {
        // code here
        // base case
        if(root == NULL) return {};
        
        queue<TreeNode*> pendingNodes;
        pendingNodes.push(root);
        vector<int> output;
        while(pendingNodes.size() != 0){
            int size = pendingNodes.size();
            for(int i = 0; i < size; ++i){
                //front of the queue
                TreeNode* front = pendingNodes.front();
                pendingNodes.pop();
                if(i == 0){
                    output.push_back(front -> val);
                }
                
                if(front -> left != NULL){
                    pendingNodes.push(front -> left);
                }
                
                if(front -> right != NULL){
                    pendingNodes.push(front -> right);
                }
            }
        }
        return output;
    }
};