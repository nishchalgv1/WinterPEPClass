#include <bits/stdc++.h>
using namespace std;
// Order Agnostic
int binarySearch(vector<int> & arr, int start, int end, int target){
    bool isAscending = false;
    if(arr[start] < arr[end]){
        isAscending = true;
    }

    while(start <= end){
        int mid = (start) + (end - start) / 2;
        if(arr[mid] == target){
            return mid;
        }
        if(isAscending){
            // write the ascending binary search
            if(target < arr[mid]){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }else{
            //Descending order binary search
            if(target > arr[mid]){
                end = mid - 1;
            }else{
                start = mid + 1;
            }
        }
    }
    return -1;
}

int main(){

    vector<int> arr = {1,2,3,4,5,6,7,8,9,10,89};
    vector<int> arr1 = {89, 79,50, 4, 30, 20, 10, 8, 9, 5};
    int x = 89;
    int n = arr1.size();
    cout << "Index of target is: " << endl;
    cout << binarySearch(arr1, 0, n - 1, x);
}