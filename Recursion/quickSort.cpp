#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int partition(vector<int>& arr, int start, int end){
    // choose the pivot as first element or element at start
    int pivot = arr[start];

    // count the total no of elements < pivot
    int counter = 0;
    for(int i = start + 1; i <= end; ++i){
        if(arr[i] < pivot){
            counter++;
        }
    }

    int pivotIdx = start + counter;
    // place the pivot at its correct position
    swap(arr[pivotIdx], arr[start]);

    // place elements < pivot to left of pivot and elements > pivot to right of pivot
    int i = start;
    int j = end;
    while(i < pivotIdx && j > pivotIdx){
        if(arr[i] < arr[pivotIdx]){
            i++;
        }else if(arr[j] >= arr[pivotIdx]){
            j--;
        }else{
            // swap them
            swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }
    return pivotIdx;
}

void quickSort(vector<int>& arr, int start, int end){
    // base case
    if(start >= end) return;

    int partitionIdx = partition(arr, start, end);

    // call quickSort on left half
    quickSort(arr, start, partitionIdx - 1);

    //call quickSort on right half
    quickSort(arr, partitionIdx + 1, end);
}

int main(){
    vector<int> arr = {5, 4, 20, 10, 5, 7, 8, 3, 1};
    int n = arr.size();
    quickSort(arr, 0, n - 1);
    for(int val: arr){
        cout << val << " ";
    }
}

/*      Time        Space
Best	O(n log n)	O(log n)
Average	O(n log n)	O(log n)
Worst	O(n²)	    O(n)
*/