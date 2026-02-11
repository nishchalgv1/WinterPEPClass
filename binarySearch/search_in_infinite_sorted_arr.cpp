#include <bits/stdc++.h>
using namespace std;

int binarySearch(vector<int>& arr, int start, int end, int target){
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(target == arr[mid]) return mid;
        else if(target < arr[mid]) end = mid - 1;
        else start = mid + 1;
    } 
    return -1;
}

int main(){
    int target = 11;
    vector<int> arr = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
    // first fig out the start and end
    int start = 0;
    int end = 1;
    while(target > arr[end]){
        start = end;
        end = end * 2;
    }
    // after this while loop we have start and end
    int output = binarySearch(arr, start, end, target);
    cout << "index of key: " << output << endl;
}