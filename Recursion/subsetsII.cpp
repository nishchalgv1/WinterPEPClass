#include <bits/stdc++.h>
using namespace std;
//leetcode
class Solution {
    vector<vector<int>> finalOutput;
    void generateSubsets(vector<int>& nums, int idx, vector<int>& subsets){
        // base case
        if(idx == nums.size()){
            finalOutput.push_back(subsets);
            return;
        }

        // include the curr element
        subsets.push_back(nums[idx]);
        generateSubsets(nums, idx + 1, subsets);
        subsets.pop_back();

        int nextIdx = idx + 1;
        while(nextIdx < nums.size() && nums[nextIdx] == nums[idx]){
            nextIdx++;
        }
        generateSubsets(nums, nextIdx, subsets);
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        // sort the nums array to get all duplicates arranged together
        sort(nums.begin(), nums.end());
        vector<int> subsets;
        generateSubsets(nums, 0, subsets);
        return finalOutput;
    }
};