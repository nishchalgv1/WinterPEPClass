#include <iostream>
#include <set>
using namespace std;

int main(){
    // set -
    set<int> mySet = {1, 2, 3, 4, 5};
    mySet.insert(5); // O(logN)
    mySet.insert(10);
    set<string> mySet1; // O(logN)

    mySet1.insert("Ram");
    mySet1.insert("Ram");
    mySet1.insert("Hanuman");
    mySet1.insert("HalkuRe");

    set<string> :: iterator it;
    for(it = mySet1.begin(); it != mySet1.end(); ++it){
        cout << *it << endl;
    }

    cout << "Printing mySet: " << endl;
    for(auto it : mySet){
        cout << it << endl;
    }

    auto it1 = mySet1.find("Mohan");
    if(it1 != mySet1.end()){
        cout << "Mohan exists" << endl;
    }else{
        cout << "Mohan is not present in set." << endl;
    }

    auto it2 = mySet1.find("Ram");
    mySet1.erase(it2); // remove Ram
    mySet1.erase(mySet1.begin()); // remove first
    
    mySet1.clear();
    cout << "Updated set: " << endl;
    for(auto val: mySet1){
        cout << val << endl;
    }

}