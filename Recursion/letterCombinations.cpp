#include <bits/stdc++.h>
using namespace std;

//leetcode
class Solution {
    void solve(int idx, string digits, string output, vector<string>& ans, vector<string> mappings){
        // base case
        if(idx == digits.length()) {
            ans.push_back(output);
            return;
        }
        int number = digits[idx] - '0'; // 2
        string letters = mappings[number];
        for(int i = 0; i < letters.length(); ++i){
            solve(idx + 1, digits, output + letters[i], ans, mappings);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if(digits.length() == 0) return ans;

        vector<string> mappings = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

        solve(0, digits, "", ans, mappings);
        return ans;
    }
};