#include<iostream>
using namespace std;
//pointers in array


int main() {


    int arr[4] = {12,23,45,21};
    cout<<arr[0]<<endl;//12
    cout<<arr<<endl;//gives base address 
    cout<<&arr<<endl;//gives base address
    cout<<&arr[0]<<endl;//gives base address

    int *ptr = arr;
    cout<<ptr<<endl;//gives base address
    cout<<&ptr<<endl;// gives address of ptr not array

    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;
    cout<<endl;



    cout<<*arr<<endl;//12
    cout<<arr[0]<<endl;//12
    cout<<*arr+1<<endl;//13
    cout<<*(arr)+1<<endl;//13
    cout<<*(arr+1)<<endl;//23
    cout<<arr[1]<<endl;//23
    cout<<*(arr+2)<<endl;//45
    cout<<arr[2]<<endl;//45
    cout<<*(arr+3)<<endl;//21
    cout<<arr[3]<<endl;//21

    cout<<endl;
    cout<<endl;
    cout<<endl;

// important to understand
    int i=0;
    cout<<arr[i]<<endl;//12
    cout<<*(arr+i)<<endl;//12


    cout<<i[arr]<<endl;//12
    cout<<*(i+arr)<<endl;//12




}