#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool isPossible(vector<int>& arr, int timeLimit,  int k){
        //  k - denotes no of painters
        int painters = 1;
        int sum = 0;
        for(int i = 0; i < arr.size(); ++i){
            if(sum + arr[i] <= timeLimit){
                sum += arr[i];
            }else{
                painters++;
                sum = arr[i];
            }
        }
        if(painters <= k) return true;
        else return false;
    }
    
    int binarySearch(vector<int>&arr, int start, int end, int k){
        int ans = start;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(isPossible(arr, mid, k)){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
  public:
    int minTime(vector<int>& arr, int k) {
        // code here
        
        int n = arr.size();
        int start = *max_element(arr.begin(), arr.end());
        int sum = accumulate(arr.begin(), arr.end(), 0);
        int end = sum;
        int output = binarySearch(arr, start, end, k);
        return output;
    }
};