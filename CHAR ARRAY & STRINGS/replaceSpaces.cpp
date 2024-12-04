#include<iostream>
#include<string.h>
using namespace std;
void replace(char arr[]) {
    int n = strlen(arr);


    for(int i=0;i<n;i++) {
        if(arr[i]==' ') {
            arr[i]='@';
        }
    }
}

int main() { 

    char arr[100];
    cout<<"Enter a text "<<endl;
    cin.getline(arr,100);
    replace(arr);
    cout<<arr;
    
}