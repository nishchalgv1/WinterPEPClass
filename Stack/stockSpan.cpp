#include <bits/stdc++.h>
using namespace std;

vector<int> calculateSpan(vector<int> &arr)
{
    // code here
    vector<int> output;
    stack<pair<int, int>> st;
    int n = arr.size();
    for (int i = 0; i < n; ++i)
    {
        int curr_elem = arr[i];
        if (st.size() == 0)
        {
            output.push_back(i + 1);
        }
        else if (st.size() > 0 && st.top().first > curr_elem)
        {
            output.push_back(i - st.top().second);
        }
        else if (st.size() > 0 && st.top().first <= curr_elem)
        {
            while (st.size() > 0 && st.top().first <= curr_elem)
            {
                st.pop();
            }
            if (st.size() == 0)
            {
                output.push_back(i + 1);
            }
            else
            {
                output.push_back(i - st.top().second);
            }
        }
        st.push({arr[i], i});
    }
    return output;
}

/*
The stock span problem is a financial problem where we have a series of daily price quotes for a stock and we need to calculate the span of stock price for all days.
You are given an array arr[] representing daily stock prices, the stock span for the i-th day is the number of consecutive days up to day i (including day i itself) for which the price of the stock is less than or equal to the price on day i. Return the span of stock prices for each day in the given sequence.

Examples:

Input: arr[] = [100, 80, 90, 120]
Output: [1, 1, 2, 4]
Explanation: Traversing the given input span 100 is greater than equal to 100 and there are no more days behind it so the span is 1, 80 is greater than equal to 80 and smaller than 100 so the span is 1, 90 is greater than equal to 90 and 80 so the span is 2, 120 is greater than 90, 80 and 100 so the span is 4. So the output will be [1, 1, 2, 4].
Input: arr[] = [10, 4, 5, 90, 120, 80]
Output: [1, 1, 2, 4, 5, 1]
Explanation: Traversing the given input span 10 is greater than equal to 10 and there are no more days behind it so the span is 1, 4 is greater than equal to 4 and smaller than 10 so the span is 1, 5 is greater than equal to 4 and 5 and smaller than 10 so the span is 2, and so on. Hence the output will be [1, 1, 2, 4, 5, 1].
Constraints:
1 ≤ arr.size() ≤ 105
1 ≤ arr[i] ≤ 105
 */