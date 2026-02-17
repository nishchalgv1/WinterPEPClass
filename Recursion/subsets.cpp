#include <bits/stdc++.h>
using namespace std;

//leetcode
class Solution {
    void generateSubsets(vector<int>& nums, vector<int>& ans, int idx, vector<vector<int>>& finalOutput){
        // base case
        if(idx == nums.size()){
            // if we reach at this point, 
            finalOutput.push_back(ans);
            return;
        }

        // include the curr_element
        ans.push_back(nums[idx]);
        generateSubsets(nums, ans, idx + 1, finalOutput);

        // do not include
        ans.pop_back();
        generateSubsets(nums, ans, idx + 1, finalOutput);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> finalOutput;
        vector<int> ans;
        generateSubsets(nums, ans, 0, finalOutput);
        return finalOutput;
    }
};