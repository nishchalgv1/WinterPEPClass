#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(int n, vector<int>& dp){
        // base case
        if(n == 0) return 0;
        if(n == 1) return 1;

        if(dp[n] != -1) return dp[n];

        int fib1 = fib(n - 1);
        int fib2 = fib(n - 2);

        dp[n] = fib1 + fib2;
        return dp[n];
    }
public:
    int fib(int n) {
        vector<int> dp(n + 1, -1);
        return solve(n, dp);
    }
};