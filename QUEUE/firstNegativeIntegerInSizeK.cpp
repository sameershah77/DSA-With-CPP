#include<iostream>
#include<vector>
#include<deque>
using namespace std;


// Given an array A[] of size N and a positive integer K, find the first negative integer for each and every window(contiguous subarray) of size K.

 

// Example 1:

// Input : 
// N = 5
// A[] = {-8, 2, 3, -6, 10}
// K = 2
// Output : 
// -8 0 -6 -6
// Explanation :
// First negative integer for each window of size k
// {-8, 2} = -8
// {2, 3} = 0 (does not contain a negative integer)
// {3, -6} = -6
// {-6, 10} = -6
 
// Example 2:
// Input : 
// N = 8
// A[] = {12, -1, -7, 8, -15, 30, 16, 28}
// K = 3
// Output :
// -1 -1 -7 -15 -15 0 


void solve(vector<int> arr, int n, int k) {
    deque<int> q;
    for(int i=0; i<k; i++) {
        if(arr[i] < 0) {
            q.push_back(i);
        }
    }


    for(int i=k; i<n; i++) {
        if(q.empty()) {
            cout<<0<<" ";
        }
        else {
            cout<<arr[q.front()]<<" ";
        }

        while(q.empty() == false && i-q.front() >= k) {
            q.pop_front();
        }
        if(arr[i] < 0) {
            q.push_back(i);
        }

    }

    if(q.empty()) {
            cout<<0<<" ";
        }
        else {
            cout<<arr[q.front()]<<" ";
        }

}

int main() {

    vector<int> arr = {-8,2,3,-6,10};
    int n = 5;
    int k = 2;

    solve(arr,n,k);
}