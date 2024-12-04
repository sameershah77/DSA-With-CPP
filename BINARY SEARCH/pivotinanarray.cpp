#include<iostream>
#include<vector>
using namespace std;

int getPivot(vector<int>arr,int n) {
    int s=0;
    int e=n-1;
    int mid = s+(e-s)/2;

    while(s<=e) {
        if(arr[mid] > arr[mid+1] && mid+1 < n) {
            return mid;
        }
        if(arr[mid] < arr[mid-1] && mid-1 >= 0) {
            return mid-1;
        }
        if (arr[s] >= arr[mid]) {
            e = mid-1;
        }
        else {
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }
    return -1;
}

int main() {
    int n;
    cout<<"Enter the size of array :-";
    cin>>n;


    vector<int> arr(n);
    cout<<"Insert the elements in array :-"<<endl;
    for(int i=0; i<n; i++) {
        cin>>arr[i];
        
    }

    cout<<"Your original array is :- "<<endl;

    for(int i=0; i<n; i++) {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;
     for(int i=0; i<n; i++) {
        cout<<"^"<<"  ";
    }
    cout<<endl;
     for(int i=0; i<n; i++) {
        cout<<"|"<<"  ";
    }
    cout<<endl;
    
    for(int i=0; i<n; i++) {
        cout<<i<<"  ";
    }
    cout<<endl;
    cout<<"Pivot element is at index "<< getPivot(arr,n) <<endl;
    return 0;
}