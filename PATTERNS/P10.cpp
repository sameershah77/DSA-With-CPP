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
    for(int j=1; j<=i; j++) {
        cout<<j<<" ";
    }
    cout<<endl;


}




}