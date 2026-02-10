#include <iostream>
#include <vector>
using namespace std;

void merge(vector<int>& arr, int start, int mid, int end){
    int size = end - start + 1;
    int *temp = new int[size];

    int i = start;
    int j = mid + 1;
    int k = 0; // temp array ka index

    // left half & right half --> merge
    while(i <= mid && j <= end){
        if(arr[i] <= arr[j]){
            temp[k] = arr[i];
            i++;
        }else{
            temp[k] = arr[j];
            j++;
        }
        k++;
    }
    // remaining left half elements are pending
    while(i <= mid){
        temp[k] = arr[i];
        k++;
        i++;
    }

    //copy remaining elements of right half
    while(j <= end){
        temp[k] = arr[j];
        j++;
        k++;
    }
    // copy temp array elements back to original array
    for(int idx = 0; idx < size; idx++){
        arr[start + idx] = temp[idx];
    }
    delete [] temp;
}

void mergeSort(vector<int>& arr, int start, int end){
    if(start >= end) return;
    // calculate mid
    int mid = start + (end - start) / 2;
    //call mergeSort on left half
    mergeSort(arr, start, mid);

    // call mergeSort on right half
    mergeSort(arr, mid + 1, end);
    
    //merge both halves
    merge(arr, start, mid, end);
}

int main(){
    vector<int> arr = {5, 4, 3, 8, 10, 7, 2, 1};
    int n = arr.size();
    mergeSort(arr, 0, n - 1);
    for(int val: arr){
        cout << val << " ";
    }
}