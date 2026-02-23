#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>& val, vector<int>& wt, int W, int n){
        if(n == 0 || W == 0) return 0;
        
        if(wt[n - 1] <= W){
            int include = val[n - 1] + 
            solve(val, wt, W - wt[n - 1], n - 1);
            
            // not pick
            int exclude = solve(val, wt, W, n - 1);
            
            return max(include, exclude);
        }else{
            return solve(val, wt, W, n - 1);
        }
    }
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        // base case
        int n = val.size();
        return solve(val, wt, W, n);
        
    }
};