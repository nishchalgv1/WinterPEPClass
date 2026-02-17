#include <iostream>
#include <vector>
using namespace std;

int sum(vector<int>& arr, int n){
    // base case
    if(n == 0) return 0;

    return arr[n - 1] + sum(arr, n - 1);
}

int sumAlternative(vector<int>& arr, int idx){
    if(idx == arr.size()) return 0;

    return arr[idx] + sumAlternative(arr, idx + 1);
}

int main(){
    vector<int> arr = {1, 2, 3, 4, 5};
    int n = arr.size();
    int output = sum(arr, n);
    int outputAlternative = sumAlternative(arr, 0);
    cout << outputAlternative << endl;
}