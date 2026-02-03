#include <iostream>
#include <unordered_map>
using namespace std;

// internal implementation uses Hash Table

int main(){
    unordered_map<string, bool> myMap;
    unordered_map<string, int> myMap1;
    unordered_map<int, string> myMap2;
    unordered_map<int, int> myMap3;

    myMap3.insert({10, 20});
    myMap3.insert({10, 20});
    myMap3.insert({10, 20});
    myMap3.insert({10, 20});
    myMap3.insert({10, 20});

    myMap1["Geeks"] = 1;
    myMap1["Geeks"] = 2;
    myMap1["Leetcode"] = 10;
    cout << "Print myMap1: " << endl;
    for(auto p: myMap1){
        cout << p.first << " " << p.second << endl;
    }
    cout << endl;
    cout << "Print myMap3: " << endl;
    for(auto p: myMap3){
        cout << p.first << " " << p.second << endl;
    }

    myMap["hello"] = true; // O(1)
    myMap.insert({"Map", false}); // O(1)
    myMap.insert({"Jethalal", true});
    myMap.insert({"TarakMehta", true});

    unordered_map<string, bool> :: iterator it;
    it = myMap.find("TarakMehta");
    if(it != myMap.end()){
        cout << "Key found: Tarak" << endl;
    }else{
        cout << "Key not found" << endl;
    }

    // string and string
    unordered_map<string, string> myMap4;
    myMap4.insert({"Jetha", "Babita"});
    myMap4.insert({"popatlal", "Rita"});
    // print myMap4
    for(auto pair : myMap4){
        cout << pair.first << " " << pair.second << endl;
    }
}
