#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        // base case
        if(n == 0) return 0;
        if(n == 1) return 1;

        int fib1 = fib(n - 1);
        int fib2 = fib(n - 2);
        return fib1 + fib2;
    }
};