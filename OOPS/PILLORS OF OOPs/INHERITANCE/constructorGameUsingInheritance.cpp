#include<iostream>
using namespace std;

class Animal {
    public:

    Animal() {
        cout<<"I am inside Animal "<<endl;
    }
};

class Dog:public Animal {
    public:   

    
    Dog() {
        cout<<"I am inside Dog "<<endl;
    }
    
};

int main() {
    
    // object ka construc call hoga i.e. left me jo hai and agar object interited hai kisi dusri class se toh pehle uska constructor call hoga
    Animal *a = new Animal(); // animal ka consttructor
 
    cout<<endl<<endl;
    Dog *b = new Dog(); // animal ka consttructor and dog ka consttructor
    cout<<endl<<endl;
  
    //Upcasting 
    cout<<"Upcasting "<<endl;

    Animal *c = new Dog(); //  animal ka consttructor dog ka consttructor
    cout<<endl<<endl;
 

    //Downcasting
    cout<<"Downcasting "<<endl;

    Dog *d = (Dog *) new Animal(); // animal ka consttructor
    cout<<endl<<endl;

}