#include<iostream>
using namespace std;
class Animal {
    public:
    // Properties or  state
    int age;
    string name;

    // Behaviour or Function

    void eat () {
        cout<<"Eating"<<endl;
    }
    void sleep () {
        cout<<"Sleeping";

    }

};


int main() {

    Animal ramesh;


    cout<<"Age of ramesh is "<<ramesh.age<<endl;// it gives garbage values
    cout<<"Age of ramesh is "<<ramesh.name<<endl;// it gives garbage values


    ramesh.age = 12;
    ramesh.name = "Lion";
    cout<<"Age of ramesh is "<<ramesh.age<<endl;
    cout<<"name of ramesh is "<<ramesh.name<<endl;

    ramesh.eat();// Eating
    ramesh.sleep(); // Sleeping


}