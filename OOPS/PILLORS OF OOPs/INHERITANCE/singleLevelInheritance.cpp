#include<iostream>
using namespace std;

class Car {
    public:


    int power;
    int myllage;


    void speedUp() {
        cout<<"Speeding up"<<endl;
    }
};

class BMW:public Car {

};


int main() {
    BMW sameer;


    sameer.speedUp();
}