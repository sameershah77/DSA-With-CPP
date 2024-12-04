#include<iostream>
 using namespace std;
// if arr = 1 2 3 4 5 
// then extreme is 1 5 2 4 3
void extreme(int arr[],int size) {

int i=0;
int j=size-1;
    while(i<=j) {
        if(i==j) {
            cout<<arr[i]<<" ";
        }
        else {
            cout<<arr[i]<<" ";
        cout<<arr[j]<<" ";
        }
        
        i++;
        j--;
    }
    cout<<endl;
}
int main () {
    int size;
    cout<<"Enter size ";
    cin>>size;

    int arr[size];
    cout<<"Insert the elements "<<endl;
    for(int i=0;i<size;i++) {
        cin>>arr[i];
    }
    cout<<"your extreme array is "<<endl;
    extreme(arr,size); 
    cout<<"Your original array"<<endl;
    for(int i=0;i<size;i++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
   
}