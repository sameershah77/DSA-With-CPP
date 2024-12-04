#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
using namespace std;

// positioning in 1-based indexed ;;;;;;
// int firstRepeated(int arr[], int n) {
        
//         unordered_map<int,int> hash;
//         for(int i=0;i<n;i++) {
//             hash[arr[i]]++;
//         }
        
//         for(int i=0;i<n;i++) {
//             if(hash[arr[i]] > 1) {
//                 return i+1;
//             }
//         }
        
//         return -1;
//     }
int main () {
    // int n=7;

    // int arr[] = {1, 7, 3, 4, 3, 5, 6};

    // int ans = firstRepeated(arr,n);

    // cout<<"First repeating element is "<<arr[ans-1]<<" at index "<<ans<<endl;

    int  arr[] = {1,1,1,1,2,3,3,3,3,3};

    int ans = 0;
    int count = 0;
    for(int i=0; i<9; i++) {
        if(arr[i] == arr[i+1]) {
            count ++;
        }
        else {
            if(count>ans) {
                ans = count;
            }
            count = 0;
        }
    }
                if(count>ans) {
                ans = count;
            }
    cout<<ans;
}