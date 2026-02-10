// order of the given array is not given. Only it is given that array is sorted 
#include <iostream>
using namespace std;

int binarySearch(int* arr, int start, int end, int target){
    //if we reach here that means size is not 0
    // check if arr is sorted in ascending order
    bool isAscending = arr[start] <= arr[end];
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(target == arr[mid]) return mid;
        if(isAscending){
            // apply ascending order binarysearch
            if(target < arr[mid]){
                // move end to mid - 1 and discard the right half
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }else{ 
            // apply descending order binary search
            if(target < arr[mid]){
                start = mid + 1;
            }else{
                end = mid - 1;
            }
        }
    }
    return - 1;
} 

int main(){
    int arr[] = {10,20,30,40,50,60,70,89};
    int x = 40;
    int n = sizeof(arr)/sizeof(int);
    cout << binarySearch(arr, 0, n - 1, x) << endl;
}