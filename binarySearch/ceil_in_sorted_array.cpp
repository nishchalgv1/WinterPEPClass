#include <bits/stdc++.h>
using namespace std;

// User function Template for C++
class Solution {
  public:
    int findCeil(vector<int>& arr, int x) {
        // code here
        //1 2 3 4 5 6 10 26 26 26 26 30 34, x = 26
        int n = arr.size();
        int start = 0, end = n - 1;
        int ans = -1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(arr[mid] >= x){
                ans = mid;
                end = mid - 1;
            }else{
                // arr[mid] < x
                start = mid + 1;
            }
        }
        return ans;
    }
};