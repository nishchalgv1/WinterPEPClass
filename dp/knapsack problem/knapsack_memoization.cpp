#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& val, vector<int>& wt, int W, int n,
    vector<vector<int>> &dp){
        if(n == 0 || W == 0) return 0;
        
        if(dp[n][W] != -1) return dp[n][W];
        
        if(wt[n - 1] <= W){
            int include = val[n - 1] + 
            solve(val, wt, W - wt[n - 1], n - 1, dp);
            
            // not pick
            int exclude = solve(val, wt, W, n - 1, dp);
            
            dp[n][W] = max(include, exclude);
        }else{
            dp[n][W] = solve(val, wt, W, n - 1, dp);
        }
        return dp[n][W];
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // base case
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        return solve(val, wt, W, n, dp);
        
    }
};