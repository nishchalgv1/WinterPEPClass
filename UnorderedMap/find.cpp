#include <iostream>
#include <unordered_map>
using namespace std;

// internal implementation uses Hash Table

int main(){
    unordered_map<string, int> myMap;
    myMap.insert({"Tarak", 2});
    auto it = myMap.find("Tarak");
    myMap.erase(it);
    for(auto p: myMap){
        cout << "It prints nothing" << endl;
        cout << p.first << " " << p.second << endl;
    }
    myMap.insert({"Hello", 2});
    myMap["Geeks"] = 5;
    for(auto it: myMap){
        cout << it.first << " " << it.second << endl;
    }
    myMap.clear();
        for(auto it: myMap){
        cout << it.first << " " << it.second << endl;
    }
}
