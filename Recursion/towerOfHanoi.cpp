#include <iostream>
#include <string>
using namespace std;

void towerOfHanoi(char source, char helper, char dest, int n){
    // base case
    if(n == 1){
        cout << "Moving disk " << n << " from " << source << " to " << dest << endl;
        return;
    }

    // move n - 1 disks from A to B
    towerOfHanoi(source, dest, helper, n - 1);

    // move remaining one disk from A to C
    cout << "Moving disk " << n << " from " << source  << " to " << dest << endl;

    // move n - 1 disks from B to C
    towerOfHanoi(helper, source, dest, n - 1);
}

int main(){
    int n;
    cout << "Enter no of circular disks: " << endl;
    cin >> n;
    towerOfHanoi('A', 'B', 'C', n);
}