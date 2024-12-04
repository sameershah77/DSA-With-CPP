#include<iostream>
using namespace std;
class Animal  {
    public:
    int age;
    int weight;
    string name;
    

    //Default Constructor
    Animal() {
        this->age = 0;
        this->weight = 0;
        cout<<"Default Constructor called"<<endl<<endl<<endl;
    }


    //Parametrized Constructor
    Animal(int age) {
        this->age = age;
        cout<<"Parameterized Constructor 1 called"<<endl;
    }

    Animal(int age,string name) {
        this->age = age;
        this->name = name;
        cout<<"Parameterized Constructor 2 called"<<endl;
    }


    Animal(string name,int age,int weight) {
        this->age = age;
        this->name = name;
        this->weight = weight;
        cout<<"Parameterized Constructor 3 called"<<endl<<endl<<endl;
    }

    Animal (Animal & obj) {
        this->age = obj.age;
        this->name = obj.name;
        cout<<"Copy Constructor called "<<endl<<endl<<endl;
    }


};

int main() {
    Animal a;

    Animal b(100);

    Animal c(10,"sameer");

    Animal d("sameer",22,70);





    Animal x;
    x.age = 23;
    x.name = "Sameer";
    Animal z(x);//Now it calles copy constructor 

    // there two type Shallow copy and Deep copy.




}