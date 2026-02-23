#include <bits/stdc++.h>
using namespace std;

class Solution {
   
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // base case
        int n = val.size();
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, -1));
        
        
        // 0th row and 0th col
        for(int i = 0; i < n + 1; ++i){
            dp[i][0] = 0;
        }
        
        // for every col fill it with 0
        for(int j = 0; j < W + 1; ++j){
            dp[0][j] = 0;
        }
        
        // i == n
        // j represents W
        for(int i = 1; i < n + 1; ++i){
            for(int j = 1; j < W + 1; ++j){
                if(wt[i - 1] <= j){
                    int include = val[i - 1] + dp[i - 1][j - wt[i - 1]];
                    int exclude = dp[i - 1][j];
                    dp[i][j] = max(include, exclude);
                }else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][W];
        
    }
};