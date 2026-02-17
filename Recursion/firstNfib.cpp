#include <bits/stdc++.h>
using namespace std;

int fib(int n){
    // base case
    if(n == 0 || n == 1) return n;

    int fib1 = fib(n - 1);
    int fib2 = fib(n - 2);
    return fib1 + fib2;
}

int main(){
    int n;
    vector<int> output;
    cout << "enter n: " << endl;
    cin >> n;
    for(int i = 0; i <= n; ++i){
       int ans = fib(i);
       output.push_back(ans);
    }

    // print output
    for(int fib: output){
        cout << fib << " ";
    }
}