#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/split-array-largest-sum/description/
class Solution {

    bool isPossible(vector<int>& nums, int k, int limit){
        int subarrays = 1;
        int sum = 0;
        for(int value: nums){
            if(sum + value <= limit){
                sum += value;
            }else{
                subarrays++;
                sum = value;
            }
        }
        return subarrays <= k;
    }
public:
    int splitArray(vector<int>& nums, int k) {
        int start = *max_element(nums.begin(), nums.end());
        int end = accumulate(nums.begin(), nums.end(), 0);

        int ans = end;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(isPossible(nums, k, mid)){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
};