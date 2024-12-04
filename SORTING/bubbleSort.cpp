#include<iostream>
#include<queue>
#include<climits>
using namespace std;


void bubblesort(int arr[],int x,int &count) {
    
for(int i = 0;i<x-1;i++) {
    for(int j = 0;j<x-i;j++) {
        if(arr[j] > arr[j+1]) {
            int temp = arr[j+1];
            arr[j+1] = arr[j];
            arr[j] = temp;
            count++;
            cout<<"I at "<<i<<endl;
        }
    }
}

for(int i = 0;i <x ;i ++) {
    cout<<arr[i] <<" ";
    }
}
void solve(int arr[],int x,int &ans) {
    
    priority_queue<pair<int,int>> maxHeap;

    for(int i=0; i<x; i++) {
        maxHeap.push({arr[i],i});
    }

    int L = x;
    
    while(maxHeap.empty() != true) {
        pair<int,int> p = maxHeap.top();
        int val = p.first;
        cout<<val<<endl;
        int index = p.second;
        if((L - index - 1) > 0) {
            ans += L - index - 1;
        }
        L--;
        maxHeap.pop();
    }
    return;
}
int main() {
    
    int x;
    cout<<"Enter the size of Array :- " <<endl;
    cin>>x;
    int arr[x];
    cout<<"Enter the elements of array"<<endl;
    for(int i =0;i <x;i ++) {
        cin>>arr[i];
    }
    cout<<"Your Original Array is : ";
    for(int i = 0; i < x;i ++) {
        cout<<arr[i]<<" ";
    }
    cout<<endl;

    cout<<"Your Sorted Array is : ";
    int ans = 0;
    bubblesort(arr,x,ans);

    // int ans = min(count,2*x-count);
    cout<<endl<<ans<<endl;
    
}