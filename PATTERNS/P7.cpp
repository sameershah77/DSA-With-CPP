#include<iostream>
using namespace std;

int main() {
cout<<"Enter the number of row :- "<<endl;
int row;
cin>>row;
cout<<"Enter the number of coloumn :- "<<endl;
int col;
cin>>col;


for(int i=1; i<=row; i++) {
    if(i==1 || i==row) {
        for(int j=1; j<=col; j++) {
            cout<<" * ";
        }

    } else {
        cout<<" * ";
        for(int j=2; j<=col-1; j++) {
            cout<<"   ";
        }
        cout<<" * ";

    }
    cout<<endl;


}




}