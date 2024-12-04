#include<iostream>
#include<vector>
using namespace std;
int binarySearch(vector<int> arr,int start,int end ,int target) {
    if(start > end) {
        return -1;
    }
    int mid =(start+end)/2;
    if(arr[mid]==target) {
        return mid;
    }
    if(arr[mid] < target) {
        return binarySearch(arr,mid+1,end,target);
    }
    else {
        return binarySearch(arr,start,mid-1,target);
    }
}

int main() {

    int n;
    cout<<"Enter the size of array :- ";
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
 
    for(int i=0;i<n;i++) {
        cout<<"^"<<"  ";
    }
    cout<<endl;
  
    for(int i=0;i<n;i++) {
        cout<<"|"<<"  ";
    }
    cout<<endl;
  
    for(int i=0;i<n;i++) {
        cout<<i<<"  ";
    }
    cout<<endl;
    int target;
    cout<<"Enter Target value :- ";
    cin>>target;
    int start = 0;
    int end = n-1;
    int ans = binarySearch(arr,start,end,target);
    cout<<"Your element is found at Index "<<ans<<endl;
}
