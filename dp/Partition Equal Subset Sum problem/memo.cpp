#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool solve(vector<int>& nums, int n, int sum, vector<vector<int>>& dp){
        // base case
        if(sum == 0) return true;
        if(n == 0) return false;

        if(dp[n][sum] != -1) return dp[n][sum];
        if(nums[n - 1] <= sum){
            bool include = solve(nums, n - 1, sum - nums[n - 1], dp);
            bool exclude = solve(nums, n - 1, sum, dp);
            dp[n][sum] = include || exclude;
        }else{
            dp[n][sum] = solve(nums, n - 1, sum, dp);
        }
        return dp[n][sum];
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
        int sum = totalSum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        return solve(nums, n, sum, dp);
    }
};