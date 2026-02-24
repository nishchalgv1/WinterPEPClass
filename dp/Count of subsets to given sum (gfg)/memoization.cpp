#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>&arr, int target, int n , vector<vector<int>>&dp){
        // base case
        if(n == 0){
            if(target == 0) return 1;
            else return 0;
        }
        
        if(dp[n][target] != -1) return dp[n][target];
        
        if(arr[n - 1] <= target){
            int include_count = solve(arr, target - arr[n - 1], n - 1, dp);
            int exclude_count = solve(arr, target, n - 1, dp);
            dp[n][target] = include_count + exclude_count;
        }else{
            dp[n][target] = solve(arr, target, n - 1, dp);
        }
        return dp[n][target];
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(target + 1, -1));
        return solve(arr, target, n, dp);
    }
};