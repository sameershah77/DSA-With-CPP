#include<iostream>
using namespace std;

void heapifyLoop(int arr[], int index, int n) {
 
        while(index < n) {
            int leftChildIndex = 2*index;
            int rightChildIndex = 2*index+1;

            int largest = index;

            if(leftChildIndex <= n && arr[largest] < arr[leftChildIndex]) {
                largest = leftChildIndex;
            }
            if(rightChildIndex <= n && arr[largest] < arr[rightChildIndex]) {
                largest = rightChildIndex;
            }

            if(largest == index) {
                break;
                return;
            } 
            else {
                swap(arr[index],arr[largest]);
                index = largest;
            }
        }
}


void heapifyRecursion(int arr[],int &index, int n) {
    int leftIndex = 2*index;
    int rightIndex = 2*index+1;
    int largest = index;
    if(leftIndex <= n && arr[largest] < arr[leftIndex]) {
        largest = leftIndex;
    }

    if(rightIndex <= n && arr[largest] < arr[rightIndex]) {
        largest = rightIndex;
    }

    if(index == largest) {
        return;
    }
    else {
        swap(arr[index],arr[largest]);
        index = largest;
        heapifyRecursion(arr,index,n);
    }
}

int main() {

    int arr[] = {-1,50,40,25,23,22,10,30};
    int n = 7;
    int index = 3;
    cout<<endl;    
    cout<<"Iterative "<<endl;
    cout<<endl;
    cout<<"Original array is "<<endl;
    for(auto val : arr) {
        cout<<val<<" ";
    }
    cout<<endl;


    heapifyLoop(arr,index,n);
    cout<<"After changing "<<index<<"th index using heap(LOOP)"<<endl;
    for(auto val : arr) {
        cout<<val<<" ";
    }
    cout<<endl; 

    cout<<endl;

    cout<<"Recursive "<<endl;
    


    int arr2[] = {-1,50,40,25,23,22,10,30};
    int n2 = 7;
    int index2 = 3;
    cout<<endl;
    cout<<"Original array is "<<endl;
    for(auto val : arr2) {
        cout<<val<<" ";
    }
    cout<<endl;

    heapifyRecursion(arr2,index2,n2);
    cout<<"After changing "<<index<<"th index using heap(RECURSION)"<<endl;
    for(auto val : arr) {
        cout<<val<<" ";
    }
    cout<<endl;           
}