#include<iostream>
using namespace std;

class A {
    public:



    void math() {
        cout<<"i am maths "<<endl;
    }
};

class B {
    public:



        void chemistry() {
        cout<<"i am chemistry "<<endl;
    }
    
};

class C:public B,public A {
    public:

        void physics() {
        cout<<"i am physics "<<endl;
    }   
};


int main() {


    C subject;


    subject.math();
    subject.chemistry();
    subject.physics();

}