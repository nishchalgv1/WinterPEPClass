#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findTarget(vector<int>& arr, int target) {
        // code here
        int n = arr.size();
        int start = 0;
        int end = n - 1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(arr[mid] == target){
                return mid;
            }
            // check mid - 1
            if(mid - 1 >= start && arr[mid - 1] == target){
                return mid - 1;
            }
            
            // check with mid + 1
            if(mid + 1 <= end && arr[mid + 1] == target){
                return mid + 1;
            }
            
            // decide left ya fir right me jana hai
            if(target < arr[mid]){
                end = mid - 2;
            }else{
                start = mid + 2;
            }
        }
        return -1;
    }
};