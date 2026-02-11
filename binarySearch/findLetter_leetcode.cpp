#include <bits/stdc++.h>
using namespace std;
// https://leetcode.com/problems/find-smallest-letter-greater-than-target/description/
char nextGreatestLetter(vector<char> &letters, char target)
{
    int n = letters.size();
    int start = 0, end = n - 1;
    char output = letters[0];
    while (start <= end)
    {
        int mid = start + (end - start) / 2;
        if (letters[mid] > target)
        {
            output = letters[mid];
            end = mid - 1;
        }
        else
        {
            start = mid + 1;
        }
    }
    return output;
}