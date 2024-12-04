#include<iostream>
using namespace std;

bool isPrime(int n) {

    if (n<=1) {
        return 0;
    }
    for(int i=2; i<n; i++ ) {
        if(n%i==0) {
            return 0;
        }
    }
    return 1;
}

int main() {
  int x;
    cout<<"Enter the Number :- ";
    cin>>x;
    if(isPrime(x)) {
        cout<<"It is a Prime Number";
    }
    else {
        cout<<"Not a Prime Number";
    }
 
 
    return 0;
}
