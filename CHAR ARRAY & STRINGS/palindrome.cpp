#include<iostream>
#include<string>
#include<fstream>
using namespace std;


// Function to calculate length of a string
int getLength(char arr[]) {
    int length = 0;
    int i=0;
    while(arr[i] != '\0') {
        length ++;
        i ++;

    }
    return length;
}
int checkPalindrone(char arr[]) {
    int n = getLength(arr);
    int i=0;
    int j=n-1;

    while(i<=j) {
        if(arr[i] != arr[j]) {
            return false;
        } else {
            i++;
            j--;
        }
    }
    return true;

}

int main () {


    cout<<"Enter a string"<<endl;
    char arr[100];
    cin>>arr;
    int size = getLength(arr);

    if (checkPalindrone(arr)) {
        cout<<"It is a Palindrone" <<endl;
    }
    else {
        cout<<"It is not a Palindrone" <<endl;
    
    }

}     