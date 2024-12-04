#include<iostream>
#include<vector>
using namespace std;

void pairSum(vector<int> arr, int n,int sum) {

    cout<<"These are the pairs :- "<<endl;
    for(int i=0; i<arr.size(); i++) {
        for(int j=i+1; j<arr.size(); j++) {
            if(arr[i]+arr[j]==sum) {
               
                 cout<<"("<<arr[i]<<","<<arr[j]<<")"<<endl;
            }
          
        }
    }

}

int main() {
    int sum;
    cout<<"Enter the sum value by which two elements makes your sum :-";

    cin>>sum;

    int n;
    cout<<"Enter the size of array :-";
    cin>>n;
    vector<int> arr(n);

    cout<<"Enter the elements in Array :-"<<endl;

    for(int i=0; i<n; i++) {
        cin>>arr[i];
    }
    pairSum(arr,n,sum);
 

    return 0;
}