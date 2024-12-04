#include<iostream>
using namespace std;

// Dilpreet wants to paint his dog's home that has n boards with different lengths. The length of ith board is given by arr[i] where arr[] is an array of n integers. He hired k painters for this work and each painter takes 1 unit time to paint 1 unit of the board. 

// The problem is to find the minimum time to get this job done if all painters start together with the constraint that any painter will only paint continuous boards, say boards numbered {2,3,4} or only board {1} or nothing but not boards {2,4,5}.


// Example 1:

// Input:
// n = 5
// k = 3
// arr[] = {5,10,30,20,15}
// Output: 35
// Explanation: The most optimal way will be:
// Painter 1 allocation : {5,10}
// Painter 2 allocation : {30}
// Painter 3 allocation : {20,15}
// Job will be done when all painters finish
// i.e. at time = max(5+10, 30, 20+15) = 35
// Example 2:

// Input:
// n = 4
// k = 2
// arr[] = {10,20,30,40}
// Output: 60
// Explanation: The most optimal way to paint:
// Painter 1 allocation : {10,20,30}
// Painter 2 allocation : {40}
// Job will be complete at time = 60

      bool isPossibleSolution(int arr[], int N, int k, long long sol) {
        int count = 1;
        int timeSum = 0;
        for(int i=0; i<N; i++) {
            if(arr[i] > sol) {
                return false;
            }
            
            if(arr[i] + timeSum > sol) {
                timeSum = arr[i];
                count++;
                
                if(count > k) {
                    return false;
                }
            }
            else {
                timeSum += arr[i];
            }
        }
        return true;
        
    }
    long long minTime(int arr[], int N, int k) {
        // code here
        // return minimum time

        long long start = 0;

        long long sum = 0;
        for(int i=0; i< N; i++) {
            sum += arr[i];
        }
        long long end = sum;
        
        long long mid = start + (end - start)/2;
        long long ans = -1;
        
        while(start <= end) {
            
            if(isPossibleSolution(arr,N,k,mid)) {
                ans = mid;
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
            mid = start + (end - start)/2;
        }
        return ans;
    }
int main() {

    int n = 4;
    int arr[] = {12,34,67,90};
    int k = 2;

    cout<<"Answer is "<<minTime(arr,n,k);

}