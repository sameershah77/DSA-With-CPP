#include<iostream>
#include<limits.h>
using namespace std;

void maximum(int arr[],int n,int i,int& max){

    if(i>=n) {
        return;
    }
    

    if(arr[i]>max) {
        max = arr[i];
    }

    maximum(arr,n,i+1,max);

}


void minimum(int arr[],int n,int i,int& min){

    if(i>=n) {
        return;
    }
    

    if(arr[i]<min) {
        min = arr[i];
    }

    minimum(arr,n,i+1,min);

}


int main () {
    int arr[] = {1,4,6,8,0,4,3,6,8,19};
    int n=10;

    int i=0;
    int max = INT_MIN;
    int min = INT_MAX;

    maximum(arr,n,i,max);

    minimum(arr,n,i,min);

    cout<<"Your Maximum value is "<<max<<endl;
    cout<<"Your Minimum value is "<<min<<endl;
}