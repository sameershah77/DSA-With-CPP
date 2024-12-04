#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;
// You are given an integer array coins representing coins of different denominations and an integer amount representing a total amount of money.

// Return the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.

// You may assume that you have an infinite number of each kind of coin.

 

// Example 1:

// Input: coins = [1,2,5], amount = 11
// Output: 3
// Explanation: 11 = 5 + 5 + 1
// Example 2:

// Input: coins = [2], amount = 3
// Output: -1
// Example 3:

// Input: coins = [1], amount = 0
// Output: 0
 

    int topDown(vector<int>& coins, int amount, vector<int>& dp) {
        if(amount == 0) {
            return 0;
        }
        if(amount < 0) {
            return INT_MAX;
        }

        if(dp[amount] != -1) {
            return dp[amount];
        }

        int mini = INT_MAX;
        for(int i=0; i<coins.size(); i++) {
            int ans = topDown(coins,amount-coins[i],dp);
            if(ans != INT_MAX) {
                mini = min(mini,ans+1);
            }
        }
        dp[amount] = mini;
        return dp[amount];
    }

    int bottomUp(vector<int>& coins, int &amount) {
        vector<int> dp(amount+1,INT_MAX);

        dp[0] = 0;

        for(int target = 1; target<= amount; target++) {
            int mini = INT_MAX;
            for(int i=0; i<coins.size(); i++) {
                if(target-coins[i] >= 0) {
                    int ans = dp[target-coins[i]];
                    if(ans != INT_MAX) {
                        mini = min(mini,ans+1);
                    }
                }
            }
            dp[target] = mini;
        }
        return dp[amount];
    }


    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount+1,-1);
        int ans = topDown(coins, amount, dp);

        if(ans == INT_MAX) {
            return -1;
        }
        
        return ans;
    }
int main() {
    vector<int> coins = {1,2,5};
    int amount = 11;
    int ans = coinChange(coins,amount);

    cout<<ans<<" coins need to make amount "<<amount<<endl;

}