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

    // void setWieght(int weight) { 
    //     weight = weight; // doestn change enything
    // }

    // use of this keyword
    void setWieght(int weight) {
        this->weight = weight; //it pass weight of setWeight function in weight of line number 25
    }

};


int main() {

    Animal ramesh;

    cout<<endl<<endl<<endl;
    cout<<"use of getter and setter"<<endl;
    // access private members
    ramesh.setWieght(12);

    int x = ramesh.getWieght();

    cout<<"Weight is "<<x<<endl;


}