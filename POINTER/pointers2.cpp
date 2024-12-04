#include<iostream>
using namespace std;

int main() {
    int a = 2;
    int *ptr = &a;
    cout<<"gives address stored in ptr : "<<ptr<<endl;
    cout<<"gives address of a : "<<&a<<endl;
    cout<<"gives value of a : "<<a<<endl;
    cout<<"gives address of ptr : "<<&ptr<<endl;
    cout<<"gives value of address stored in ptr : "<<*ptr<<endl;
}