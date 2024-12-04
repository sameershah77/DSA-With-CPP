#include<iostream>
using namespace std;

class A {

    public:


    int sum(int a,int b) {
        cout<<"I am first "<<endl;
        return a+b;
    }

    int sum(int a,int b,int c) {
        cout<<"I am first "<<endl;
        return a+b+c;
    }


    int sum (int a,float b) {
        cout<<"I am first "<<endl;
        return a+b;
    }
};

int main() {

    A obj;

    cout<<obj.sum(2,5)<<endl;
    cout<<obj.sum(10,2,15)<<endl;
    cout<<obj.sum(2,23.7f)<<endl;
    

}