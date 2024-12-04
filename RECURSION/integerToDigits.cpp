#include<iostream>
using namespace std;

void convertIntoDigits(int n) {
    if(n==0) {
        return;
    }

    int newN = n/10;
    convertIntoDigits(newN);
    int digit = n%10;
    cout<<digit<<"  :  ";

    
}

int main () {
    int n;
    cout<<"Enter a number :- ";
    cin>>n;

    convertIntoDigits(n);
}