#include<iostream>
using namespace std;


class Animal {
    public:

    void speak() {
        cout<<"Speaking "<<endl;
    }
};

class Dog:public Animal {
    public:    
    void speak() {
        cout<<"Barking "<<endl;
    }
};

int main() {
    // Normal function overriding in Dynamic memory
    cout<<"Normal function overriding in Dynamic memory "<<endl;
    Animal *a = new Animal();
    a->speak();

    Dog *b = new Dog();
    b->speak();

    //Upcasting 
    cout<<"Upcasting "<<endl;

    Animal *c = new Dog(); // animal par pointer hai toh animal ka speak print hoga 
    c->speak();

    //Downcasting
    cout<<"Downcasting "<<endl;

    Dog *d = (Dog *) new Animal(); //dog par pointer hai toh dog ka speak print hoga
    d->speak(); 
}