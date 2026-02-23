#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool solve(vector<int>& arr, int target, int n,
    vector<vector<int>>& dp){
        // base case
        if(target == 0) return true;
        if(n == 0) return false;
        
        if(dp[n][target] != -1) return dp[n][target];
        
        if(arr[n - 1] <= target){
            int include = solve(arr, target - arr[n - 1], n - 1, dp);
            int exclude = solve(arr, target, n - 1, dp);
            dp[n][target] = include || exclude;
        }else{
            dp[n][target] = solve(arr, target, n - 1, dp);
        }
        return dp[n][target];
    }
  public:
 
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        
        return solve(arr, sum, n, dp);
    }
};