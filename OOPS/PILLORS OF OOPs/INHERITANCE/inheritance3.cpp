#include<iostream>
using namespace std;

// different way to inherit -> public , private , protected

class Animal{

    protected:
    int age;


    void eat() {
        cout<<"Eating"<<endl;
    }
};


//protected to public

class Dog:public Animal {
    public:
    void print() {
        cout<<"protected to public"<<endl;
    }
    
};


//protected to protected

class Cat:protected Animal {
    public:
    void print() {
        cout<<"protected to protected"<<endl;
    }
    
};


//protected to private

class Fish:private Animal {
    public:
    void print() {
        cout<<"protected to private"<<endl;
    }
    
};



int main() {
//    protected to public
    Dog d1;
    d1.print();

//    d1.eat();// it throughs error ; protected to public ->  protected 
    





//    protected to protected

    Cat d2;
//    d2.eat();// it throughs error ; protected to protected ->  protected 
    d2.print();





//    protected to private

    Fish d3;

//    d3.eat();// it throughs error ; protected to private ->  private 
    d3.print();

    




}