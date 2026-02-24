#include <bits/stdc++.h>
using namespace std;

class Solution {
    int solve(vector<int>&arr, int target, int n){
        // base case
        if(n == 0){
            if(target == 0) return 1;
            else return 0;
        }
        
        if(arr[n - 1] <= target){
            int include_count = solve(arr, target - arr[n - 1], n - 1);
            int exclude_count = solve(arr, target, n - 1);
            return include_count + exclude_count;
        }else{
            return solve(arr, target, n - 1);
        }
    }
  public:
    int perfectSum(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        return solve(arr, target, n);
    }
};