#include <bits/stdc++.h>
using namespace std;

// Problem from GFG
class Solution {

int merge(vector<int>& arr, int start, int mid, int end){
    // create a temp vector or array
    vector<int> temp;
    int i = start;
    int j = mid + 1;
    int count = 0;
    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            count += (mid - i) + 1;
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }
// aggressive cows
    while(j <= end){
        temp.push_back(arr[j]);
        j++;
    }
    // copy back to original array
    for(int i = start; i <= end; ++i){
        arr[i] = temp[i - start];
    }
    return count;
}

int mergeSort(vector<int>& arr, int start, int end){
    // base case
    if(start >= end) return 0;

    // calculate mid
    int mid = start + (end - start) / 2;

    // call on left half
    int left = mergeSort(arr, start, mid);

    // call on right half
    int right = mergeSort(arr, mid + 1, end);

    int mergeCount = merge(arr, start, mid, end);
    
    return left + right + mergeCount;
}

  public:
    int inversionCount(vector<int> &arr) {
        // Code Here
        int n = arr.size();
       int count = mergeSort(arr, 0, n - 1);
       return count;
    }
};