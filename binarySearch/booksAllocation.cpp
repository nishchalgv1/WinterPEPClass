#include <bits/stdc++.h>
using namespace std;
// https://www.geeksforgeeks.org/dsa/allocate-minimum-number-pages/
class Solution {
  bool canAllocatePages(vector<int>&arr, int maxPages, int k){
      int students = 1;
      int pagesSum = 0;
      
      for(int value: arr){
          if(pagesSum + value <= maxPages){
              pagesSum += value;
          }else{
              students++;
              pagesSum = value;
          }
      }
      return students <= k;
  }
    
  public:
    int findPages(vector<int> &arr, int k) {
        // code here
        int n = arr.size();
        if(k > n) return -1;
        int start = *max_element(arr.begin(), arr.end());
        int end = accumulate(arr.begin(), arr.end(), 0);
        
        int ans = -1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(canAllocatePages(arr, mid, k)){
                ans = mid;
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
        return ans;
    }
};