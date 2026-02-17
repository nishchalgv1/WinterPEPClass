#include <iostream>
#include <string>
using namespace std;

void printSubsequences(string input, string output){
    // base case - when string becomes empty
    if(input.length() == 0) {
        cout << output << endl;
        return;
    }

    // do not include curr character
    printSubsequences(input.substr(1), output);

    // to include the curr character
    printSubsequences(input.substr(1), output + input[0]);

}

int main(){
    string s;
    cout << "Enter string: " << endl;
    cin >> s;

    string output = "";
    printSubsequences(s, output);
    //cout << output << endl;
}