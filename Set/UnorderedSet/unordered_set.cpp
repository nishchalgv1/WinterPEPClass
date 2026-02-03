#include <iostream>
#include <unordered_set>
using namespace std;

int main(){
    unordered_set<int> mySet = {10, 20, 30, 40, 50};
    
    // insertion 
    mySet.insert(99);
    mySet.insert(99);
    
    auto it = mySet.find(99);
    mySet.erase(it);
    if(it != mySet.end()){
        cout << "99 is present" << endl;
    }else{
        cout << "element not found" << endl;
    }

    // print all elements
    cout << "print: " << endl;
    mySet.clear();
    for(auto it1 : mySet){
        cout << it1 << " ";
    }
    cout << endl;
}