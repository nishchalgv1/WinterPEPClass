#include <bits/stdc++.h>
using namespace std;
// Problem : Stream First Non-repeating (geeksforgeeks)
class Solution {
  public:
    string firstNonRepeating(string &s) {
        // code here
        
        unordered_map<char, int> freq;
        queue<char> q;
        string ans = "";
        
        for(int i = 0; i < s.length(); ++i){
             char c = s[i];
             // storing frequency of each character
             freq[c]++;
             q.push(c);
             while(!q.empty() && freq[q.front()] > 1){
                q.pop();
             }
        
            if(q.empty()){
                ans.push_back('#');
            }else{
                ans.push_back(q.front());
            }
        }
        return ans;
    }
};