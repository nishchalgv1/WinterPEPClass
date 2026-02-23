#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
    
        
        // if sum is 0 and whatever is your n, ans -> true
        dp[0][0] = 1;
        for(int i = 1; i < n + 1; ++i){
            // sum is 0, -> true
            dp[i][0] = 1;
        }
        
        for(int j = 1; j < sum + 1; ++j){
            dp[0][j] = 0;
        }
        
        for(int i = 1; i < n + 1; ++i){
            for(int j = 1; j < sum + 1; ++j){
                if(arr[i - 1] <= j){
                    int include = dp[i - 1][j - arr[i - 1]];
                    int exclude = dp[i - 1][j];
                    dp[i][j] = include || exclude;
                }else{
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        return dp[n][sum];
        
    }
};