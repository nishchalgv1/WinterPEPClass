#include <bits/stdc++.h>
using namespace std;

vector<int> nextLargerElement(vector<int>& arr) {
        // code here
        vector<int> output;
        
        stack<int> st;
        int n = arr.size();
        
        for(int i = n - 1; i >= 0; --i){
            int curr_elem = arr[i];
            if(st.size() == 0){
                output.push_back(-1);
            }else if(st.size() > 0 && st.top() > curr_elem){
                output.push_back(st.top());
            }else if(st.size() > 0 && st.top() <= curr_elem){
                while(st.size() > 0 && st.top() <= curr_elem){
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

int main(){
    vector<int> arr ={10,4,2,20,40,12,30};
    vector<int> output = nextLargerElement(arr);
    for(int val: output){
        cout << val << " ";
    }
}
/*
You are given an array arr[] of integers, the task is to find the next greater element for each element of the array in order of their appearance in the array. Next greater element of an element in the array is the nearest element on the right which is greater than the current element.
If there does not exist next greater of current element, then next greater element for current element is -1.

Examples

Input: arr[] = [1, 3, 2, 4]
Output: [3, 4, 4, -1]
Explanation: The next larger element to 1 is 3, 3 is 4, 2 is 4 and for 4, since it doesn't exist, it is -1.
Input: arr[] = [6, 8, 0, 1, 3]
Output: [8, -1, 1, 3, -1]
Explanation: The next larger element to 6 is 8, for 8 there is no larger elements hence it is -1, for 0 it is 1, for 1 it is 3 and then for 3 there is no larger element on right and hence -1.
Input: arr[] = [1, 2, 3, 5]
Output: [2, 3, 5, -1]
Explanation: For a sorted array, the next element is next greater element also except for the last element.
Input: arr[] = [5, 4, 3, 1]
Output: [-1, -1, -1, -1]
Explanation: There is no next greater element for any of the elements in the array, so all are -1.
Constraints:
1 ≤ arr.size() ≤ 106
0 ≤ arr[i] ≤ 109
*/