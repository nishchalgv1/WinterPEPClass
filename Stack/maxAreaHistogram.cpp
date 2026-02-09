#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;


vector<int> nearestSmallerToLeft(vector<int> &heights){
        stack<pair<int, int>> st;
        vector<int> output;
        int pseudoIndex = -1;
        int n = heights.size();
        for(int i = 0; i < n; ++i){
            int curr_elem = heights[i];
            if(st.size() == 0){
                output.push_back(pseudoIndex);
            }else if(st.size() > 0 && st.top().first < curr_elem){
                output.push_back(st.top().second);
            }else if(st.size() > 0 && st.top().first >= curr_elem){
                while(st.size() > 0 && st.top().first >= curr_elem){
                    st.pop();
                }
                if(st.size() == 0){
                    output.push_back(pseudoIndex);
                }else{
                    output.push_back(st.top().second);
                }
            }
            st.push({curr_elem, i});
        }
        return output;
    }
    vector<int> nearestSmallerToRight(vector<int> &heights){
        stack<pair<int, int>> st;
        int n = heights.size();
        vector<int> output;
        int pseudoIndex = 7;
        for(int i = n - 1; i >= 0; --i){
            int curr_elem = heights[i];
            if(st.size() == 0){
                output.push_back(pseudoIndex);
            }else if(st.size() > 0 && st.top().first < curr_elem){
                output.push_back(st.top().second);
            }else if(st.size() > 0 && st.top().first >= curr_elem){
                while(st.size() > 0 && st.top().first >= curr_elem){
                    st.pop();
                }
                if(st.size() == 0){
                    output.push_back(pseudoIndex);
                }else{
                    output.push_back(st.top().second);
                }
            }
            st.push({curr_elem, i});
        }
        reverse(output.begin(), output.end());
        return output;
    }
    
    int getMaxArea(vector<int> &arr) {
        // code here
        vector<int> nsl = nearestSmallerToLeft(arr);
        vector<int> nsr = nearestSmallerToRight(arr);

        cout << "left array:" << endl;
        for(auto val: nsl){
            cout << val << " ";
        }
        cout << endl;
        cout << "right array: " << endl;
        cout << "right size: " << nsr.size() << endl;
        for(auto val: nsr){
            cout << val << " ";
        }
        return -1;
        // int maxArea = 0;
        // for(int i = 0; i < arr.size(); ++i){
        //     int curr_elem_height = arr[i];
        //     int width = nsr[i] - nsl[i] - 1;
        //     int area = curr_elem_height * width;
        //     maxArea = max(maxArea, area);
        // }
        // return maxArea;
    }

    int main(){
        vector<int> arr = {60,20,50,40,10,50,60};
        cout << getMaxArea(arr) << endl;
    }