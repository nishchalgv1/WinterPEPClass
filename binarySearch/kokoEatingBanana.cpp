#include <bits/stdc++.h>
using namespace std;

class Solution {
    long long calculateTime(vector<int>& piles, int speed){
        long long totalHours = 0;
        for(long long bananas: piles){
            totalHours += ceil(double(bananas) / double(speed));
        }
        return totalHours;
    }
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int start = 1;
        int max_elem = *max_element(piles.begin(), piles.end());
        int end = max_elem;

        int ans = max_elem;
        while(start <= end){
            int mid = start + (end - start) / 2;
            long long time_taken = calculateTime(piles, mid);
            if(time_taken <= h){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
};