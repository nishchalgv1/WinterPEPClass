#include <bits/stdc++.h>
using namespace std;

//leetcode

class Solution {
    void generateCombinations(int idx, int target, vector<int>& candidates, vector<int>& ans, vector<vector<int>>& finalOutput){
        // base case
        if(idx >= candidates.size()){
            if(target == 0){
                finalOutput.push_back(ans);
            }
            return;
        }

        // pick the element
        if(candidates[idx] <= target){
            ans.push_back(candidates[idx]);
            generateCombinations(idx + 1, target - candidates[idx], candidates, ans, finalOutput);
            ans.pop_back();
        }

        // do not pick the element
        // skip duplicates 
        int nextIdx = idx + 1;
        while(nextIdx < candidates.size() && candidates[nextIdx] == candidates[idx]){
            nextIdx++;
        }
        // do not pick the element
        generateCombinations(nextIdx, target, candidates, ans, finalOutput);
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> finalOutput;
        vector<int> ans;
        generateCombinations(0, target, candidates, ans, finalOutput);
        return finalOutput;
    }
};