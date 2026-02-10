#include <bits/stdc++.h>
using namespace std;

//https://www.geeksforgeeks.org/problems/search-in-a-rotated-array4618/1

class Solution {
  public:
    int search(vector<int>& arr, int key) {
        // Code Here
        int start = 0, end = arr.size() - 1;
        while(start <= end){
            int mid = start + (end - start) / 2;
            if(key == arr[mid]) return mid;
            
            // check if left half is sorted
            if(arr[start] <= arr[mid]){
                if(arr[start] <= key && key < arr[mid]){
                    // move to left
                    end = mid - 1;
                }else{
                    start = mid + 1;
                }
            }else{
                // right half is sorted
                // check if target lies in right half
                if(arr[mid] < key && key <= arr[end]){
                    start = mid + 1;
                }else{
                    end = mid - 1;
                }
            }
        }
        return -1;
    }
};