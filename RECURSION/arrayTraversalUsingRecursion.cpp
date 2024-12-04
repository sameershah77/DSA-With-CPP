#include<iostream>
using namespace std;

//method 1
void print1(int arr[],int n,int i) {
    if(i>=n) {
        return;
    }
    cout<<arr[i]<<" ";

    print1(arr,n,i+1);

}
//Method 2
void print2(int arr[],int n) {
      if(n==0) {
        return;
    }

    cout<<*arr<<" ";
    print2(arr+1,n-1);
}

int main() {

    int arr[5]={10,20,30,40,50};
    int n=5;
    int i=0;

    print1(arr,n,i);
    cout<<endl;
    print2(arr,n);
}