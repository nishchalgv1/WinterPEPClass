#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool canMakeMBouqets(vector<int>& bloomDay, int days, int m, int k){
        int counter = 0;
        int bouqets = 0;
        for(int i = 0; i < bloomDay.size(); ++i){
            if(bloomDay[i] <= days){
                counter++;
                if(counter == k){
                    bouqets++;
                    counter = 0;
                }
            }else{
                counter = 0;
            }
        }
        if(bouqets >= m) return true;
        else return false;
    }

    int binarySearch(vector<int>& bloomDay, int start, int end, int m, int k){
        // m -- no of bouqets you have to make
        // k -- no of flowers each bouqets should contain
        int ans = end;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(canMakeMBouqets(bloomDay, mid, m, k)){
                //if it is possible
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        } 
        return ans;
    }
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if((long long)m*k > n){
            return -1;
        }

        int min_elem = *min_element(bloomDay.begin(), bloomDay.end());
        int max_elem = *max_element(bloomDay.begin(), bloomDay.end());

        int start = min_elem, end = max_elem;
        int output = binarySearch(bloomDay, start, end, m, k);
        return output;
    }
};