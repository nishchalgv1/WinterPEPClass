#include <bits/stdc++.h>
using namespace std;

class Solution {
   
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
        
        dp[0][0] = 1;
        for(int i = 1; i < n + 1; ++i){
            dp[i][0] = 1; //true
        }
        for(int j = 1; j < sum + 1; ++j){
            dp[0][j] = 0; //false
        }

        for(int i = 1; i < n + 1; ++i){
            for(int j = 1; j < sum + 1; ++j){
                if(nums[i - 1] <= j){
                    int include = dp[i - 1][j - nums[i - 1]];
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