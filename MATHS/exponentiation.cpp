#include<iostream>
using namespace std;

int fastExponent(int x,int n) {
// T.C. O(logn)

//this is better solution always use this
    int ans =1;

    while(n>0) {
        if(n%2 != 0) {
            //odd
            ans = ans*x;
        }
        x=x*x;
        n=n/2;
    }
    return ans;
}

int slowExponent(int x,int n) {
// T.C. O(n)    
    int ans =1;
    for(int i=0;i<n;i++) {
        ans = ans*x;
    }
    return ans;
}



int main() {
    int x;
    cout<<"Enter the value of x : ";
    cin>>x;

    int n;
    cout<<"Enter the value of n : ";
    cin>>n;

    int ans1 = slowExponent(x,n);

    cout<<"Your answer of x^n is "<<ans1;

    cout<<endl;
    int ans2 = fastExponent(x,n);
    cout<<"Your answer of x^n is "<<ans2;
}