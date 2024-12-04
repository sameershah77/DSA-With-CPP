#include<iostream>
#include<string.h>
using namespace std;;
int main() {
    int a = 5;
    char ch = 'j';
    string str = "hello";
    double x = 2.333;



    int *ptrOfa = &a;
    char *ptrOfch = &ch;
    string *ptrOfstr = &str;
    double *ptrOfx = &x;


    cout<<"Size is "<<sizeof(ptrOfa)<<endl;
    cout<<"Size is "<<sizeof(ptrOfch)<<endl;
    cout<<"Size is "<<sizeof(ptrOfstr)<<endl;
    cout<<"Size is "<<sizeof(ptrOfx)<<endl;


}