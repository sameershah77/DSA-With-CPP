#include<iostream>
#include<string.h>
using namespace std;


int main() { 
    cout<<"This is string "<<endl;
    string  str;
    str[0]='s';
    str[1]='s';
    str[2]='a';
    str[3]='\0';
    str[4]='s';
    str[5]='\0';
    str[6]='s';
    cout<<str<<endl;
    cout<<"This is character array "<<endl;

    char arr[100];
    arr[0]='s';
    arr[1]='s';
    arr[2]='a';
    arr[3]='\0';
    arr[4]='s';
    arr[5]='\0';
    arr[6]='s';
    cout<<arr<<endl;;

    
}