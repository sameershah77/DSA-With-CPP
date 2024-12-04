#include<iostream>
#include<vector>
using namespace std;

bool checkSorted(vector<int> &arr,int &n,int i) {
    if(i==n-1) {
        return true;
    }


    if(arr[i+1] < arr[i]) {
        return false;
    }


    checkSorted(arr,n,i+1);
}

int main () {
    int n;
    cout<<"ENter the size of array :- ";
    cin>>n;
    vector<int> arr(n);
    cout<<"Insert elements in Array :- "<<endl;
    for(int i=0;i<n;i++) {
        cin>>arr[i];
    }
    cout<<endl;

    cout<<"Your Array :- "<<endl;
    for(int i=0;i<n;i++) {
        cout<<arr[i]<<"  ";
    }
    cout<<endl;

    int i=0;
    bool isSorted=checkSorted(arr,n,i);
    if(isSorted) {
        cout<<"Array is sorted "<<endl;
    }
    else {
        cout<<"Array is not sorted "<<endl;
    }
}