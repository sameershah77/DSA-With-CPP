#include<iostream>
using namespace std;

class A {
    public:



    void chemistry() {
        cout<<"i am chemistry "<<endl;
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


    subject.A::chemistry();
    subject.B::chemistry();
    subject.physics();

}