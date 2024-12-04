#include<iostream>
using namespace std;

void insertionSort(int n, int arr[]){
    for(int i = 1;i <n ; i ++) {
        int temp = arr[i];
        int j = i-1;
        while(j >=0) {
            if(arr[j]>temp) {
                arr[j+1] = arr[j];
            }
            else{
                break;
            }
            j--;
        }
        arr[j+1] = temp;
    }

    for(int i = 0;i <n ;i ++) {
    cout<<arr[i] <<" ";
    }
}

int main() {
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
    insertionSort(x,arr);

}