#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
//Leetcode question 322 

// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1

int changeCoin(vector<int>arr,int target) {
    if(target==0) {
        return 0;   
    }
    if(target<0) {
        return INT_MAX;
    }

    int mini = INT_MAX;
    for(int i=0;i<arr.size();i++) {
        int ans = changeCoin(arr,target-arr[i]);
        if(ans != INT_MAX) {
            mini = min(mini,ans+1);
        }
    }
    return mini;
}

int main() {
    vector<int> arr = {1,2,5};

    int target =11;

    int ans = changeCoin(arr,target);
    cout<<"Answer is "<<ans<<endl;

    return 0;
}