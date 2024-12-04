#include<iostream>
using namespace std;

// different way to inherit -> public , private , protected

class Animal{

    public:
    int age;


    void eat() {
        cout<<"Eating"<<endl;
    }
};


//public to public

class Dog:public Animal {
    public:
    void print() {
        cout<<"public to public"<<endl;
    }
    
};





//public to protected

class Cat:protected Animal {
    public:
    void print() {
        cout<<"public to protected"<<endl;
    }
    
};


//public to private

class Fish:protected Animal {
    public:
    void print() {
        cout<<"public to private"<<endl;
    }
    
};



int main() {
//    public to public
    Dog d1;
    d1.print();
    d1.eat();
    

//    public to protected

    Cat d2;
//    d2.eat();// it throughs error ; public to protected ->  protected 
    d2.print();

//    public to private

    Fish d3;

//    d3.eat();// it throughs error ; public to private ->  private 
    d3.print();

    




}