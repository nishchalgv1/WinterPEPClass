#include <iostream>
#include <string>
using namespace std;

void printSubsequences(string input, string output){
    // base case
    if(input.length() == 0){
        cout << output << endl;
        return;
    }

    // do not include the 0th char
    printSubsequences(input.substr(1), output);

    // include the 0th char
    printSubsequences(input.substr(1), output + input[0]);
}

int main(){
    string input;
    cout << "Enter string: " << endl;
    cin >> input;

    string output = "";
    printSubsequences(input, output);
    cout << output << endl;
}