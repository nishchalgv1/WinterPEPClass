#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    void reverseQueue(queue<int> &q) {
        // code here
        queue<int> q1;
        stack<int> st;
        
        int n = q.size();
        // adding elements from queue to stack
        for(int i = 0; i < n; ++i){
            st.push(q.front());
            q.pop();
        }
        
        while(!st.empty()){
            int top = st.top();
            q1.push(top);
            st.pop();
        }
        
        // print the queue
        while(!q1.empty()){
            cout << q1.front() << " ";
            q1.pop();
        }
    }
};