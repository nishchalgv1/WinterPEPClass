#include <bits/stdc++.h>
#include "Node.h"
using namespace std;
class Solution {
    void solve(Node* root, vector<vector<int>>& output){
        // base case
        if(root == NULL) return;
        
        queue<pair<Node*, int>> pendingNodes;
        pendingNodes.push({root, 0});
        
        map<int, vector<int>> myMap;
        
        while(!pendingNodes.empty()){
            pair<Node*, int> front = pendingNodes.front();
            pendingNodes.pop();
            
            Node* node = front.first;
            int hd = front.second;
            
            myMap[hd].push_back(node -> data);
            
            if(node -> left != NULL){
                pair<Node*, int> p;
                p.first = node -> left;
                p.second = hd - 1;
                pendingNodes.push(p);
            }
            
            if(node -> right != NULL){
                pendingNodes.push({node -> right, hd + 1});
            }
        }
        
        // traverse on the map from leftmost HD to rightmost 
        // -2 -1 0 +1 +2
        for(auto it: myMap){
            output.push_back(it.second);
        }
    }
  public:
    vector<vector<int>> verticalOrder(Node *root) {
        // code here
        vector<vector<int>> output;
        solve(root, output);
        return output;
    }
};