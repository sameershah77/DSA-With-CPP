#include<iostream>
using namespace std;

    //T.C. = O(logN)
    void heapify(int arr[], int index, int n) {

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
    //T.C. = O(N) including heapify function
    void buildHeap(int arr[], int n) {

        //from n/2+1 -> n are the leaf nodes , no  need to heapify it i.e. single node is always a heap
        //from 1 to n/2 nodes are valid to heapify
        for(int i=n/2; i>0; i--) {
            heapify(arr,i,n);
        }
    }

    //this is main code
    //T.C = O(NlogN)
    void heapSort(int arr[],int n) {

        while(n > 1) {
            //swap first element element with last
            swap(arr[1],arr[n]);
            //neglate last element
            n--;
            heapify(arr,1,n);
        }

    }

int main() {

    int arr[] = {-1,5,7,8,3,12,4,7,9};
    int n = 8;
    cout<<endl;
    cout<<"Array is : ";
    for(auto val: arr) {
        cout<<val<<" ";
    }
    
    buildHeap(arr,n);
    //we can sort an array if it is in the form of heap
    heapSort(arr,n);
    cout<<endl;
    cout<<"Array after sorting using heap sort : ";
    for(auto val: arr) {
        cout<<val<<" ";
    }

}