#include <bits/stdc++.h>
using namespace std;

// leetcode 387
class Solution {
public:
    int firstUniqChar(string s) {
        //Maintain a frequency array of 122 size
        //as lowercase letters starts from 97 and ends at 122
        //a -> 97 && z -> 122
        
        //To get the index 97 in array we do not need to create a 122 sized array
        //we can achieve store that char by calculating its idx 
        //like char - 'a'
        //if char is a then it will save in 0th idx i.e a - a = 97 - 97 = 0
        //so we will be storing all the lower case letters from idx 0 till 25
        //we need to create only 26 sized array
        
        int arr[26] = {0}; //constant extra space
        int n = s.length();
        for(int i = 0; i < n; ++i)
        {
            int idx = s[i] - 'a';
            arr[idx]++;
        }
        
        //iterate on the string and check for first unique char
        int ans = -1;
        for(int i = 0; i < n; ++i)
        {
            int idx = s[i] - 'a';
            if(arr[idx] == 1)
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};