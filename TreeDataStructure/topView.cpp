#include <bits/stdc++.h>
#include "Node.h"
using namespace std;
class Solution {
    void solve(Node* root, vector<int>& output){
        if(root == NULL) return;
        
        queue<pair<Node*, int>> pendingNodes;
        pendingNodes.push({root, 0});
        
        map<int, int> myMap;
        
        while(!pendingNodes.empty()){
            pair<Node*, int> front = pendingNodes.front();
            pendingNodes.pop();
            
            Node* node = front.first;
            int hd = front.second;
            
            if(myMap.find(hd) == myMap.end()){
                myMap[hd] = node -> data;
            }
            
            if(node -> left != NULL){
                pendingNodes.push({node -> left, hd - 1});
            }
            
            if(node -> right != NULL){
                pendingNodes.push({node -> right, hd + 1});
            }
            
        }
        
        for(auto it: myMap){
            output.push_back(it.second);
        }
    }
  public:
    vector<int> topView(Node *root) {
        // code here
        vector<int> output;
        solve(root, output);
        return output;
        
    }
};