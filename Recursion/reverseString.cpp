#include <bits/stdc++.h>
using namespace std;

void reverseString(string &s, int start, int end){
    // base case
    if(start >= end) return;

    // swap start and end
    int temp = s[end];
    s[end] = s[start];
    s[start] = temp;

    reverseString(s, start + 1, end - 1);
}

int main(){
    string s = "Hello";
    // olleh
    reverseString(s, 0, s.length() - 1);
    cout << s << endl;
}