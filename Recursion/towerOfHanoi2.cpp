#include <iostream>
#include <string>
using namespace std;

long long towerOfHanoi(char source, char helper, char dest, int n){
    // base case
    if(n == 1){
        return 1;
    }
    // move n - 1 disks from A to B
    long long ans1 = towerOfHanoi(source, dest, helper, n - 1);

    // move n - 1 disks from B to C
    long long ans2 = towerOfHanoi(helper, source, dest, n - 1);
    return ans1 + 1 + ans2;
}

int main(){
    int n;
    cout << "Enter no of circular disks: " << endl;
    cin >> n;
    cout << "Steps: " << endl;
    cout << towerOfHanoi('A', 'B', 'C', n);
}