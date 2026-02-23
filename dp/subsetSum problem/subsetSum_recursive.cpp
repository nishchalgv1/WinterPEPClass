#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool solve(vector<int>& arr, int target, int n){
        // base case
        if(target == 0) return true;
        if(n == 0) return false;
        
        if(arr[n - 1] <= target){
            int include = solve(arr, target - arr[n - 1], n - 1);
            int exclude = solve(arr, target, n - 1);
            return include || exclude;
        }else{
            return solve(arr, target, n - 1);
        }
    }
  public:
    bool isSubsetSum(vector<int>& arr, int sum) {
        // code here
        int n = arr.size();
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1, -1));
        
        return solve(arr, sum, n);
    }
};