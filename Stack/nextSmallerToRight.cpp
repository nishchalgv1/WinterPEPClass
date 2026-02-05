#include <bits/stdc++.h>
using namespace std;

vector<int> nextSmallerEle(vector<int>& arr) {
        //  code here
        int n = arr.size();
        vector<int> output;
        stack<int> st;
        
        for(int i = n - 1; i >= 0; --i){
            int curr_elem = arr[i];
            if(st.size() == 0){
                output.push_back(-1);
            }else if(st.size() > 0 && st.top() < curr_elem){
                output.push_back(st.top());
            }else if(st.size() > 0 && st.top() >= curr_elem){
                while(st.size() > 0 && st.top() >= curr_elem){
                    st.pop();
                }
                if(st.size() == 0){
                    output.push_back(-1);
                }else{
                    output.push_back(st.top());
                }
            }
            st.push(curr_elem);
        }
        reverse(output.begin(), output.end());
        return output;
    }
/*
You are given an integer array arr[ ]. For every element in the array, your task is to determine its Next Smaller Element (NSE).


The Next Smaller Element (NSE) of an element x is the first element that appears to the right of x in the array and is strictly smaller than x.

If no such element exists, assign -1 as the NSE for that position.
Examples:

Input: arr[] = [4, 8, 5, 2, 25]
Output: [2, 5, 2, -1, -1]
Explanation: 
The first element smaller than 4 having index > 0 is 2.
The first element smaller than 8 having index > 1 is 5.
The first element smaller than 5 having index > 2 is 2.
There are no elements smaller than 4 having index > 3.
There are no elements smaller than 4 having index > 4.
Input: arr[] = [13, 7, 6, 12]
Output: [7, 6, -1, -1]
Explanation:
The first element smaller than 13 having index > 0 is 7.
The first element smaller than 7 having index > 1 is 6.
There are no elements smaller than 6 having index > 2.
There are no elements smaller than 12 having index > 3.

Input: arr[] = [4, 1]
Output: [1, -1]
Explanation: 4 will be updated to 1 and 1 will be updated to -1.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105
*/