#include<iostream>
using namespace std;

void selectionSort(int arr[], int n) {   
for (int i =0;i <n-1;i++) {

        int minIndex = i;
        for (int j = i + 1 ; j < n;j ++) {
        if (arr[j]<arr[minIndex]) {
            minIndex=j;
            }
                
        }
    int temp = arr[minIndex];
    arr[minIndex] = arr[i];
    arr[i] = temp;
   }
    for(int i = 0;i <n ;i ++) {
    cout<<arr[i] <<" ";
    }
   
}

int main () {
    int x;
    cout<<"Enter the size of Array :- " <<endl;
    cin>>x;
    int arr[x];
    cout<<"Enter the elements of array"<<endl;
    for(int i =0;i <x;i ++) {
        cin>>arr[i];
    }
    cout<<"Your Original Array is : ";
    for(int i = 0; i < x;i ++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"Your Sorted Array is : ";
    selectionSort(arr,x);
}