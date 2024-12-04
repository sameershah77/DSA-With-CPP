#include<iostream>
using namespace std;
class Animal  {
    public:
    int age;
    int weight;
    string name;
    

    //Destructor Constructor
    ~Animal() {
        cout<<"Destructor called"<<endl<<endl<<endl;
    }



};

int main() {

    //Static desctructor
    Animal a;

    // Dynamic Destructor
    Animal *b = new Animal(); //it not works until we destroy it

    delete b;//now b desctructor called;;;








}