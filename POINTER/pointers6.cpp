#include<iostream>
using namespace std;

int main() {
    char ch[10]="Babbar";
    char * c =&ch[0];
    cout<<c<<endl;
    //jitna hamne padha hai uss hisaab se yaha address print hona chahiye tha par yeh galat hai
    //yaha Babbar print hoga
    //reason : cout ki implementation alag hoti hai char ke liye iss wajah se 
    cout<<endl;

    cout<<ch<<endl; //Babbar
    cout<<&ch<<endl; // address of ch
    cout<<ch[0]<<endl;//B
    cout<<&ch[0]<<endl;//address of ch
    cout<<c<<endl;//Babbar
    cout<<&c<<endl;//address of c
    cout<<*c<<endl;//B





}