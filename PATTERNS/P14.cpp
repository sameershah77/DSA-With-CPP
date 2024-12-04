#include<iostream>
using namespace std;


int main() {
    int n;

    cout<<"Enter the number of rows :- ";
    cin>>n;

    for(int row=1; row<=n; row++) {

        for(int col=1; col<=n-row+1; col++) {
            cout<<" ";
          
        }
        for(int col=1; col<=2*row-1; col++) {
           if(col==1) {
            cout<<"*";
           }
           else if(col==2*row-1) {
            cout<<"*";
           } 
           else {
            cout<<" ";
           }
          
        }
        cout<<endl;
       

    }

        for(int row=n; row>=1; row--) {

        for(int col=1; col<=n-row+1; col++) {
            cout<<" ";
          
        }
        for(int col=1; col<=2*row-1; col++) {
           if(col==1) {
            cout<<"*";
           }
           else if(col==2*row-1) {
            cout<<"*";
           } 
           else {
            cout<<" ";
           }
          
        }
        cout<<endl;
       

    }
    return 0;
}
