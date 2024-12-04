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
        cout<<"Sleeping"<<endl;

    }



    // use of getter and setter


    private:
    int weight;

    // getter and setter ko hamesha public me rakh kar use karna padta hai
    public:
    int getWieght() {
        return weight;
    }

    void setWieght(int w) {
        weight = w;
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



    cout<<endl<<endl<<endl;
    cout<<"use of getter and setter"<<endl;
    // access private members
    ramesh.setWieght(12);

    int x = ramesh.getWieght();

    cout<<"Weight is "<<x<<endl;


}