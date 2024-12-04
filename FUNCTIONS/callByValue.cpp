#include<iostream>
using namespace std;



void callByValue(int n) {
    n++;
    cout<<"Number in callByValue is " << n <<endl; // -----> 11
}
int main() {
    int n;
    cout<<"Enter the number"<<endl; 

    cin>>n;//---->10
    callByValue(n);

    cout<<"Number in main is "<< n <<endl; // ------> 10

    return 0;


}