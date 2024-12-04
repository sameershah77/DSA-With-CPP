#include<iostream>
using namespace std;

// different way to inherit -> public , private , protected

class Animal{

    private:
    int age;

    void eat() {
        cout<<"Eating"<<endl;
    }
};


//private to public

class Dog:public Animal {
    public:
    void print() {
        cout<<"private to public"<<endl;
    }
    
};


//private to protected

class Cat:protected Animal {
    public:
    void print() {
        cout<<"private to protected"<<endl;
    }
    
};


//private to private

class Fish:private Animal {
    public:
    void print() {
        cout<<"private to private"<<endl;
    }
    
};



int main() {
//    private to public
    Dog d1;
//    d1.print();// it throughs error ; private to private ->  N.A. 

//    d1.eat();// it throughs error ; private to public ->  N.A. 
    





//    private to protected

    Cat d2;
//    d2.eat();// it throughs error ; private to protected ->  N.A.  
//    d2.print();// it throughs error ; private to private ->  N.A. 





//    private to private

    Fish d3;

//    d3.eat();// it throughs error ; private to private ->  N.A.  
//    d3.print();// it throughs error ; private to private ->  N.A. 

    




}