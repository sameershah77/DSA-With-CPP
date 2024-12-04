#include<iostream>
#include<vector>
using namespace std;

// important question
// it is in searching and sorting 3rd video in supreme batch


int binary(vector<int> arr, int target) {

    int start = 0;
    int end = arr.size()-1;
    int mid =  start + (end - start)/2;


    while (start <= end ) {
        if (arr[mid] == target) {
            return mid;
        }
        if (mid-1 >= start && arr[mid-1] == target) {
            return mid -1;
        }
        if (mid +1 <= end && arr[mid+1]==target) {
            return mid +1;
        }
        if(target > arr[mid]) {
            start = mid +2;
        }
        else {
            end = mid -2;
        }
        mid = start + (end - start)/2;
    }
    return -1;
}

int main() {
    int size;
    cout<<"Enter the size of an nearly sorted array :- ";
    cin>>size;
    vector<int> arr(size);
    cout<<"Insert elements in an nearly sorted array :- "<<endl;
    for(int i=0; i<size; i++) {
        cin>>arr[i];
    }

    cout<<"Your Nearly Sorted Array is :- "<<endl;
    for(int i=0; i<size; i++) {
            cout<<arr[i]<<"  ";
    }


    cout<<endl;
     for(int i=0; i<size; i++) {
        cout<<"^"<<"  ";
    }
    cout<<endl;
     for(int i=0; i<size; i++) {
        cout<<"|"<<"  ";
    }

    cout<<endl;
    for(int i=0; i<size; i++) {
        cout<<i<<"  ";
    }
    



    cout<<endl;
    int target;
    cout<<"Enter element to be search :- ";
    cin>>target;
    cout<<endl;
    int ans = binary(arr,target);

    cout <<" index of "<<target <<" is "<<ans<<endl;;


 return 0;
}