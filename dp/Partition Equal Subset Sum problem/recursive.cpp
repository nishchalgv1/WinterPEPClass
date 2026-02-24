#include <bits/stdc++.h>
using namespace std;


class Solution {
    bool solve(vector<int>& nums, int n, int target){
        // base case
        if(target == 0) return true;
        if(n == 0) return false;

        if(nums[n - 1] <= target){
            bool include = solve(nums, n - 1, target - nums[n - 1]);
            bool exclude = solve(nums, n - 1, target);
            return include || exclude;
        }else{
            return solve(nums, n - 1, target);
        }
    }
public:
    bool canPartition(vector<int>& nums) {
        // parition is only possible when totalSum is even

        // calculate the totalSum
        int totalSum = 0;
        for(int val: nums){
            totalSum += val;
        }

        if(totalSum % 2 != 0) return false;

        int n = nums.size();
        return solve(nums, n, totalSum / 2);
    }
};