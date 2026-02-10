// https://www.geeksforgeeks.org/problems/number-of-occurrence2259/1

#include <bits/stdc++.h>
using namespace std;

class Solution {
     int firstOccurence(vector<int>& arr, int x){
        int start = 0, end = arr.size() - 1;
        int ans = -1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(x == arr[mid]){
                ans = mid;
                end = mid - 1;
            }else if(x < arr[mid]){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
    
     int lastOccurence(vector<int>& arr, int x){
        int start = 0, end = arr.size() - 1;
        int ans = -1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(x == arr[mid]){
                ans = mid;
                start = mid + 1;
            }else if(x < arr[mid]){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
  public:
    int countFreq(vector<int>& arr, int target) {
        // code here
        int first = firstOccurence(arr, target);
        int last = lastOccurence(arr, target);
        if(first == -1) return 0;
        int count = (last - first) + 1;
        return count;
    }
};
