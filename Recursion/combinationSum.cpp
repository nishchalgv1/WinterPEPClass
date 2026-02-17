#include <bits/stdc++.h>
using namespace std;

//leetcode

class Solution {
    void generateCombinations(int idx, int target, vector<int>& candidates, vector<int>& ans, vector<vector<int>>& finalOutput){
        // base case
        if(idx == candidates.size()){
            // target == 0
            if(target == 0){
                finalOutput.push_back(ans);
            }
            return;
        }

        // make a call only if curr_elem <= target
        if(candidates[idx] <= target){
            // pick the element
            ans.push_back(candidates[idx]);
            generateCombinations(idx, target - candidates[idx], candidates, ans, finalOutput);
            ans.pop_back();
        }
        generateCombinations(idx + 1, target, candidates, ans, finalOutput);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        // base case
        vector<vector<int>> finalOutput;
        vector<int> ans;
        generateCombinations(0, target, candidates, ans, finalOutput);
        return finalOutput;
    }
};