#include <vector>
#include <stack>
#include <iostream>
using namespace std;

vector<int> preGreaterEle(vector<int> &arr)
{
    //  code here
    vector<int> output;
    stack<int> st;

    int n = arr.size();
    for (int i = 0; i < n; ++i)
    {
        int curr_elem = arr[i];
        if (st.size() == 0)
        {
            output.push_back(-1);
        }
        else if (st.size() > 0 && st.top() > curr_elem)
        {
            output.push_back(st.top());
        }
        else if (st.size() > 0 && st.top() <= curr_elem)
        {
            while (st.size() > 0 && st.top() <= curr_elem)
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                output.push_back(-1);
            }
            else
            {
                output.push_back(st.top());
            }
        }
        st.push(curr_elem);
    }

    return output;
}

int main(){
    vector<int> arr ={10,4,2,20,40,12,30};
    vector<int> output = preGreaterEle(arr);
    for(int val: output){
        cout << val << " ";
    }
}
/*
You are given an integer array arr[ ]. For every element in the array, your task is to determine its Previous Greater Element (PGE).

The Previous Greater Element (PGE) of an element x is the first element that appears to the left of x in the array and is strictly greater than x.


Note: If no such element exists, assign -1 as the PGE for that position.

Examples:

Input: arr[] = [10, 4, 2, 20, 40, 12, 30]
Output: [-1, 10, 4, -1, -1, 40, 40]
Explanation:
For 10, no elements on the left, so answer is -1.
For 4, previous greater element is 10.
For 2, previous greater element is 4.
For 20, no element on the left greater than 20, so answer is -1.
For 40, no element on the left greater than 40, so answer is -1.
For 12, previous greater element is 40.
For 30, previous greater element is 40.
Input: arr[] = [10, 20, 30, 40]
Output: [-1, -1, -1, -1]
Explanation: Each element of the array has no previous greater element.
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105


 */