#include<iostream>
using namespace std;

class Animal{

    public:
    int age;


    void eat() {
        cout<<"Eating"<<endl;
    }
};

class Dog:public Animal {
    
};
int main() {
    Dog d1;
    d1.eat();
}