#include<iostream>
using namespace std;

class A {
    public:



    void math() {
        cout<<"i am maths "<<endl;
    }
};

class B:public A {
    public:



        void chemistry() {
        cout<<"i am chemistry "<<endl;
    }
    
};

class C:public A {
    public:

        void physics() {
        cout<<"i am physics "<<endl;
    }   
};


int main() {


    C subject1;


    subject1.math();
    subject1.physics();
    

    B subject2;

    subject2.math();
    subject2.chemistry();
}