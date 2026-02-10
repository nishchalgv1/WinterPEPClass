#include <iostream>
#include <vector>
using namespace std;

int lastOccurence(vector<int>& arr, int target){
    int start = 0;
    int end = arr.size() - 1;
    int ans = -1;
    while(start <= end){
        int mid = start + (end - start) / 2;
        if(target == arr[mid]){
            ans = mid;
            start = mid + 1;
        }else if(target < arr[mid]){
            end = mid - 1;
        }else{
            start = mid + 1;
        }
    }
    return ans;
}

int main(){

    vector<int> arr = {1, 2, 3, 5, 5, 5, 5, 10, 11};
    int x = 5;
    int n = arr.size();
    cout << "last occurence is at index: " << endl;
    cout << lastOccurence(arr, x);
}