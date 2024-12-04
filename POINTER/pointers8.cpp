#include<iostream>
using namespace std;

int main() {
    char ch = 'k';
    char *cptr = &ch;

    cout<<cptr;// k ke baad garbage value print hogi jab tak null character print nahi ho jata

    char name[100] = "Babbar";
    cout<<name<<endl;

    char *c = "Babbar";
    cout<<c<<endl;
}