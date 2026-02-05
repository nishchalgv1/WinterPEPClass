#include <bits/stdc++.h>
using namespace std;

vector<int> leftSmaller(vector<int> arr) {
        // code here
        int n = arr.size();
        vector<int> output;
        stack<int> st;
        
        for(int i = 0; i < n; ++i){
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
        return output;
    }

/*
Given an array arr[] of integers, for each element in the array, find the nearest smaller element on its left. If there is no such smaller element, return -1 for that position.

Input: arr[] = [1, 6, 2]
Output: [-1, 1, 1]
Explaination: 
There is no number to the left of 1, so we return -1. 
After that, the number is 6, and the nearest smaller number on its left is 1. 
Next, the number is 2, and the nearest smaller number on the left is also 1.
Input: arr[] = [1, 5, 0, 3, 4, 5]
Output: [-1, 1, -1, 0, 3, 4]
Explaination: 
There is no number to the left of 1,  so we return -1. 
After that, the number is 5,  and the nearest smaller number on its left is 1. 
 Next, the number is 0, and there is no smaller number on the left, so we return -1.
Then comes 3, and the nearest smaller number on its left is 0.
After that, the number is 4, and the nearest smaller number on the left is 3. 
Finally, the number is 5, and the nearest smaller number on its left is 4.
Constraints:
1 ≤ arr.size()≤ 106
1 ≤ arr[i] ≤ 103 


*/