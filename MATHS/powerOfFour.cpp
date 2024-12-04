#include<iostream>
using namespace std;

// Given an integer n, return true if it is a power of four. Otherwise, return false.

// An integer n is a power of four, if there exists an integer x such that n == 4x.

 

// Example 1:

// Input: n = 16
// Output: true
// Example 2:

// Input: n = 5
// Output: false
// Example 3:

// Input: n = 1
// Output: true

    bool isPowerOfFour(int n) {
        if(n==0) return false;

        while(n%4==0) {
            n/=4;
        }
        if(n==1) return true;
        return false;
    }
int main() {
    int n;
    cout<<"Enter a number ";
    cin>>n;

    if(isPowerOfFour(n)) {
        cout<<"It is a power of four"<<endl;
    }else {
        cout<<"It is not a power of four"<<endl;
    }
}