#include<iostream>
#include<string>
#include<fstream>
using namespace std;

int getLength(char arr[]) {
    int length = 0;
    int i=0;
    while(arr[i] != '\0') {
        length ++;
        i++;

    }
    return length;
}


void lowerToUpper(char arr[]) {
    int size = getLength(arr);
    for(int i=0;i<size;i++) {
        arr[i] = arr[i] - 'a'+ 'A';
    }


}


int main () {


    cout<<"Enter a lower case string"<<endl;
    char arr[100];
    cin>>arr;
    int size = getLength(arr);
    lowerToUpper(arr);

    cout<<arr<<endl;
    

}     