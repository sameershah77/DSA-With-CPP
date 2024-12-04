#include<iostream>
using namespace std;

class Fruit {
    public:


    int color;
    int flavour;


    void test() {
        cout<<"Yummy !! "<<endl;
    }
};

class Mango:public Fruit {
    public:
    int calcium;

};

class Alphanso:public Mango {
   
};


int main() {

    Alphanso x;
    x.test();

}