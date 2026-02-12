#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool canPlaceKCows(vector<int> &stalls, int k, int dist){
        int count = 1; // first cow is placed at first stall (0th)
        int last_cow_placed = stalls[0];
        
        for(int i = 0; i < stalls.size(); ++i){
            if(stalls[i] - last_cow_placed >= dist){
                count++;
                last_cow_placed = stalls[i];
            }
            if(count >= k) return true;
        }
        return false;
    }
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        // code here
        sort(stalls.begin(), stalls.end());
        int start = 1;
        //max dis b/w any two cows
        int n = stalls.size();
        int max_dist = stalls[n - 1] - stalls[0];
        int end = max_dist;
        int ans = 0;
        while(start <= end){
            int mid = start + (end - start) / 2;
            
            if(canPlaceKCows(stalls, k, mid)){
                ans = mid;
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return ans;
    }
};