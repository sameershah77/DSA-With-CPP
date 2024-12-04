#include<iostream>

using namespace std;
int getLength(char arr[]) {
    int length = 0;
    int i=0;
    while(arr[i] != '\0') {
        length ++;
        i ++;

    }
    return length;
}

int main () {


    cout<<"Enter a string"<<endl;
    char arr[100];
    cin>>arr;
    int size = getLength(arr);

    int i=0;
    int j=size-1;
    while(i<=j) {
    swap(arr[i],arr[j]);
        i++;
        j--;

    }
    cout<<arr<<endl;
}     