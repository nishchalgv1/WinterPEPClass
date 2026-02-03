#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> v = {1, 2, 3, 4, 5};
    cout << "Print using for loop" << endl;
    for(int i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;

    vector<int> :: iterator it = v.begin();
    cout << "Deferencing iterator: " << (*it) << endl;
    cout << *(it + 2) << endl;

    // Printing all elements using iterator
    cout << "Printing all using iterator: " << endl;
    for(it = v.begin(); it != v.end(); ++it){
        cout << *(it) << " ";
    }
    cout << endl;

    //create a vector of pair
    vector<pair<int, int>> vp = {{10, 20}, {30, 40}, {50, 60}};
    vector<pair<string, int>> vp1 = {{"Hello", 1}, {"World", 2}, {"Pointers", 3}};

    // for(auto it = vp.begin(); it != vp.end(); ++it){
    //     cout << it -> first << " " << it -> second << endl;
    // }

    vector<pair<string, int>>:: iterator it1;
    for(it1 = vp1.begin(); it1 != vp1.end(); ++it1){
        cout << (*it1).first << " " << (*it1).second << endl;
    }

}