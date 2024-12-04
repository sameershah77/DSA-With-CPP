#include<iostream>
#include<vector>
#include<algorithm>
#include<limits>
using namespace std;
// to find first and last occurance of an element in array

int firstOcc(vector<int> arr,int key) { 

    int start = 0;
    int end = arr.size() -1;
    
    // int mid = (start + end)/2; 
    // iski jagah yeh likhna 

    int mid = start + (end-start)/2;  // To prevent Run time Error;

    int ans = -1;
    while (start <= end) {


        if (arr[mid]==key) {
            ans = mid;
            end = mid -1;
        }

        if (key > arr[mid]) {
            start = mid +1;
        } else {

            end = mid -1;
        }
        mid = start + (end - start)/2;
    }
    return ans;

}



int lastOcc(vector<int> arr,int key) { 

    int start = 0;
    int end = arr.size() -1;
    
    // int mid = (start + end)/2;
    // iski jagah yeh likhna 

    int mid = start + (end-start)/2;  // To prevent Run time Error;

    int ans = -1;
    while (start <= end) {


        if (arr[mid]==key) {
            ans = mid;
            start = mid +1;

        }

        if (key > arr[mid]) {
            start = mid +1;
        } else {

            end = mid -1;
        }
        mid = start + (end - start)/2;
    }
    return ans;

}


int main() {


int n;
cout<<"Enter the size of array :- ";
cin>>n;
vector<int> arr(n);

cout<<"Insert the elements of array :- "<<endl;
for(int i=0;i<n;i++) {
    cin>>arr[i];
}

cout<<"Your array is :- "<<endl;
for(int i=0; i<n; i++) {
    cout<<arr[i]<<" ";
}
cout<<endl;
int target;
cout<<"Enter the target value to be find First and Last Occurance :- ";
cin>>target; 

cout<< " First occurance is an index " << firstOcc(arr,target)<<endl;
cout<< " Last occurance is an index " << lastOcc(arr,target)<<endl;
cout<< "Total Occurance is " <<lastOcc(arr,target) - firstOcc(arr,target)<< endl;
}