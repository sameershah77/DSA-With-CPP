#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;

    

//     There are 3n piles of coins of varying size, you and your friends will take piles of coins as follows:

// In each step, you will choose any 3 piles of coins (not necessarily consecutive).
// Of your choice, Alice will pick the pile with the maximum number of coins.
// You will pick the next pile with the maximum number of coins.
// Your friend Bob will pick the last pile.
// Repeat until there are no more piles of coins.
// Given an array of integers piles where piles[i] is the number of coins in the ith pile.

// Return the maximum number of coins that you can have.

 

// Example 1:

// Input: piles = [2,4,1,2,7,8]
// Output: 9
// Explanation: Choose the triplet (2, 7, 8), Alice Pick the pile with 8 coins, you the pile with 7 coins and Bob the last one.
// Choose the triplet (1, 2, 4), Alice Pick the pile with 4 coins, you the pile with 2 coins and Bob the last one.
// The maximum number of coins which you can have are: 7 + 2 = 9.
// On the other hand if we choose this arrangement (1, 2, 8), (2, 4, 7) you only get 2 + 4 = 6 coins which is not optimal.
// Example 2:

// Input: piles = [2,4,5]
// Output: 4
// Example 3:

// Input: piles = [9,8,7,6,5,1,2,3,4]
// Output: 18
    // using heap

    int maxCoins1(vector<int>& piles) {

        int ans = 0;
         priority_queue<int>maxHeap;

         for(auto val: piles) {
             maxHeap.push(val);
         }

         int n = piles.size();

         while(maxHeap.size() > n/3) {
             maxHeap.pop();
             ans += maxHeap.top();
             maxHeap.pop();
         }
         return ans;

    }

    // using sorting

    int maxCoins2(vector<int>& piles) {

        int ans = 0;
     
        sort(piles.begin(),piles.end());

        int n = piles.size();

        int flag = 1;

        for(int i=n/3; i<n; i++) {
            if(flag%2 != 0) {
                ans += piles[i];
            }
            flag++;
        }
        return ans;
    }


int main() {

    vector<int>  piles = {9,8,7,6,5,1,2,3,4};

    cout<<"Answer is "<<maxCoins1(piles)<<endl;
    cout<<"Answer is "<<maxCoins2(piles)<<endl;

}