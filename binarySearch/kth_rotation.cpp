#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    int findKRotation(vector<int> &arr) {
        // Code Here
        int start = 0;
        int end = arr.size() - 1;
        int n = arr.size();
        while(start <= end){
            // check if array is already sorted
            if(arr[start] <= arr[end]){
                return start;
            }
            
            // calculate mid
            int mid = start + (end - start) / 2;
            int next = (mid + 1) % n;
            int prev = (mid - 1 + n) % n;
            
            // check if mid is minimum
            if(arr[mid] <= arr[next] && arr[mid] <= arr[prev]){
                return mid;
            }
            
            //check if left half is sorted - move to right half
            if(arr[start] <= arr[mid]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
        return 0;
    }
};
