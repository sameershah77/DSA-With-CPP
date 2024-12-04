#include<iostream>
using namespace std;


int main() {
    int n;

    cout<<"Enter the number of rows :- ";
    cin>>n;

    for(int row=1; row<=n; row++) {

        for(int col=1; col<=n; col++) {

            if(col==n-row+1|| col==1||row==1) {
                cout<<"*";
            } else {
                cout<<" ";
            }

          
        }
        cout<<endl;

    }
    return 0;
}

