#include <iostream>
#include <queue>
#include <stack>
using namespace std;

void reverseFirstK(queue<int> &q, int k) {
    if (k <= 0 || k > q.size()) return;

    stack<int> st;

    // Step 1: Push first k elements into stack
    for (int i = 0; i < k; i++) {
        st.push(q.front());
        q.pop();
    }

    // Step 2: Push stack elements back into queue
    while (!st.empty()) {
        q.push(st.top());
        st.pop();
    }

    // Step 3: Move remaining elements to the back
    int rem = q.size() - k;
    for (int i = 0; i < rem; i++) {
        q.push(q.front());
        q.pop();
    }
}

int main() {
    queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(6);

    int k = 3;
    reverseFirstK(q, k);

    // Print queue
    while (!q.empty()) {
        cout << q.front() << " ";
        q.pop();
    }
}
