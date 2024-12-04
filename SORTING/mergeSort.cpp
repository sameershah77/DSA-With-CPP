#include<iostream>
#include<algorithm>
using namespace std;

void merge(int arr[],int start,int end) {
    
    int mid = start + (end-start)/2;

    int length1 = mid-start+1;
    int length2 = end-(mid+1)+1;  // or end-mid

    // assume to create two arrays of length length1 & length2
    int* leftArr = new int[length1];
    int* rightArr = new int[length2];

    int k=start;

    for(int i=0;i<length1;i++) {
        leftArr[i]=arr[k];
        k++;
    }
    k=mid+1;
    for(int i=0;i<length2;i++) {
        rightArr[i]=arr[k];
        k++;
    }


    int leftArrayIndex = 0;
    int rigthArrayIndex = 0;
    int mainArrayIndex = start;

    while (leftArrayIndex<length1 && rigthArrayIndex<length2) {
        if(leftArr[leftArrayIndex] < rightArr[rigthArrayIndex]) {
            arr[mainArrayIndex] = leftArr[leftArrayIndex];
            mainArrayIndex++;
            leftArrayIndex++;
        }
        else {
            arr[mainArrayIndex] = rightArr[rigthArrayIndex];
            mainArrayIndex++;
            rigthArrayIndex++;
        }
    }

    //copy logic for left array

    while (leftArrayIndex<length1) {
        arr[mainArrayIndex] = leftArr[leftArrayIndex];
        mainArrayIndex++;
        leftArrayIndex++;
    }


    //copy logic for rigth array

    while (rigthArrayIndex<length2) {
        arr[mainArrayIndex] = rightArr[rigthArrayIndex];
        mainArrayIndex++;
        rigthArrayIndex++;
    }

}

void mergeSort(int arr[],int start,int end) {
    // base case

    
    if(start==end) {
        return;
    }
    if(start>end) {
        return;
    }
    int mid = start + (end-start)/2;

    // left array

    mergeSort(arr,start,mid);

    // right array 

    mergeSort(arr,mid+1,end);

    // Now merger two sorted array

    merge(arr,start,end);


}

int main () {

    
    int n;
    cout<<"Enter the size of array :- ";
    cin>>n;
    int arr[n];
    cout<<"Insert elements in an array :- "<<endl;

    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<endl;

    cout<<"Your original array is "<<endl;

    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    mergeSort(arr,0,n-1); 

    cout<<"Your sorted array is "<<endl;

    for(int i=0;i<n;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;





}