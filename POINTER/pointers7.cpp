#include<iostream>
using namespace std;

int main() {
    char name[10]="Babbar";
    char * c =&name[0];

    cout<<name <<endl;// Babbar
    cout<<&name <<endl;//address of name
    cout<<*(name+3) <<endl;//b
    cout<<c <<endl;//Babbar
    cout<<&c <<endl;//address of c
    cout<<*(c+3) <<endl;////b
    cout<<c+2 <<endl;//bar
    cout<<*c <<endl;//////B
    cout<<c+8 <<endl;//empty string (8 is out of string size)


   







}