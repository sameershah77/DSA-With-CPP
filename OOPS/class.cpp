#include<iostream>
using namespace std;

class A1 {

};
class A2{
    int age;

};
class A3 {
    int age;
    int weight;
};
class A4 {
    int age;
    int weight;
    char ch;

};


int main() {
  cout<<"Size of empty class is "<<sizeof(A1)<<endl;//1  
  cout<<"Size of class is "<<sizeof(A2)<<endl;//4
  cout<<"Size of class is "<<sizeof(A3)<<endl;//8
  cout<<"Size of class is "<<sizeof(A4)<<endl;//9 hona tha par 12 kyu // catch : learn padding and greedy alignment
  return 0;
}