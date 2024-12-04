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

    Animal * suresh = new Animal;
    
    // suresh.age = 15;
    // suresh.name = "Kutta"; it not works because suresh stores address of animal object

    //we use
    (*suresh).age = 15;
    (*suresh).name = "Kutta";
    cout<<(*suresh).age<<endl;
    cout<<(*suresh).name<<endl;

    // alternate method and best method to use
    suresh->age = 15;
    suresh->name = "Billi";
    cout<<suresh->age<<endl;
    cout<<suresh->name<<endl;

    suresh->eat();
    suresh->sleep();


}