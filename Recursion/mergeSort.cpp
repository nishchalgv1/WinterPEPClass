#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int start, int mid, int end){
    // create a temp vector or array
    vector<int> temp;
    int i = start;
    int j = mid + 1;
    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            temp.push_back(arr[i]);
            i++;
        }else{
            temp.push_back(arr[j]);
            j++;
        }
    }

    while(i <= mid){
        temp.push_back(arr[i]);
        i++;
    }

    while(j <= end){
        temp.push_back(arr[j]);
        j++;
    }
    // copy back to original array
    for(int i = start; i <= end; ++i){
        arr[i] = temp[i - start];
    }
}

void mergeSort(vector<int>& arr, int start, int end){
    // base case
    if(start >= end) return;

    // calculate mid
    int mid = start + (end - start) / 2;

    // call on left half
    mergeSort(arr, start, mid);

    // call on right half
    mergeSort(arr, mid + 1, end);

    merge(arr, start, mid, end);
}

int main(){
    vector<int> arr = {5, 4, 3, 2, 1};
    int n = arr.size();
    mergeSort(arr, 0, n - 1);

    // print the arr
    for(int val: arr){
        cout << val << " ";
    }
}