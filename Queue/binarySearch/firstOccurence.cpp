#include <bits/stdc++.h>
using namespace std;
//first occurence of an element
int firstOccurence(vector<int> & arr, int target){
    int start = 0;
    int end = arr.size() - 1;
    int ans = -1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(target == arr[mid]){
            ans = mid;
            end = mid - 1;
        }else if(target < arr[mid]){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return ans;
}

int main(){

    vector<int> arr = {1, 2, 3, 5, 5, 5};
    int x = 5;
    int n = arr.size();
    cout << "first occurence is at index: " << endl;
    cout << firstOccurence(arr, x);
}