#include<iostream>
using namespace std;

int main() {

    int a=5;
    int &b =a;

    cout<<a<<endl;//5
    cout<<b<<endl;//5
    a++;
    
    cout<<a<<endl;//6
    cout<<b<<endl;//6
    b++;
    
    cout<<a<<endl;//7
    cout<<b<<endl;//7
}