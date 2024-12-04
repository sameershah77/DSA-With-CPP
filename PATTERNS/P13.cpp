#include<iostream>
using namespace std;

int main() {
    int n;
    int m;
    int x;
    int y;
    cout<<"Enter the number of rows :- ";
    cin>>n;
    if(n%2==1)  {
        m=n-1;

    }

    else {
        m=n;
    }
  
    for(int i=1; i<=n; i++) {
        //space

        for(int j=1; j<=n-i; j++) {
            cout<<"   ";
        }
        for(int j=1; j<=i; j++) {
            cout<<" * ";
        }
        
        for(int j=1; j<=i; j++) {
            cout<<" * ";
        }
        cout<<endl;
    }

    for(int i=m; i>=1; i--) {
        //space

        for(int j=1; j<=n-i; j++) {
            cout<<"   ";
        }
        for(int j=1; j<=i; j++) {
            cout<<" * ";
        }
        
        for(int j=1; j<=i; j++) {
            cout<<" * ";
        }
        cout<<endl;
    }


    

    return 0;
}

