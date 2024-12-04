#include<iostream>
#include<vector>
#include<limits.h>
using namespace std;


// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security systems connected and it will automatically contact the police if two adjacent houses were broken into on the same night.

// Given an integer array nums representing the amount of money of each house, return the maximum amount of money you can rob tonight without alerting the police.

 

// Example 1:

// Input: nums = [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
// Total amount you can rob = 1 + 3 = 4.
// Example 2:

// Input: nums = [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
// Total amount you can rob = 2 + 9 + 1 = 12.
 





    // int recursion(vector<int>& nums,int n) {
    //     if(n < 0) {
    //         return 0;
    //     }
    //     if(n == 0) {
    //         return nums[0];
    //     }

    //     int include = recursion(nums,n-2) + nums[n];
    //     int exclude = recursion(nums,n-1) + 0;

    //     int maxi = max(include,exclude);

    //     return maxi;
    // }



    //this is top down approach

    int memo(vector<int>& nums,int n,vector<int>&dp) {
        if(n < 0) {
            return 0;
        }
        if(n == 0) {
            return nums[0];
        }
        if(dp[n] != -1) {
            return dp[n];
        }

        int include = memo(nums,n-2,dp) + nums[n];
        int exclude = memo(nums,n-1,dp) + 0;

        dp[n] = max(include,exclude);

        return dp[n];
    }



    // int tabulation(vector<int>& nums,int n) {
    //     vector<int>dp(n+2,0);
    //     dp[0] = nums[0];

    //     for(int i=1; i<=n; i++) {
    //         int temp = 0;
    //         if(i-2>=0) {
    //             temp = dp[i-2];
    //         }
    //         int include = temp + nums[i];
    //         int exclude = dp[i-1] + 0;

    //         dp[i] = max(include,exclude);
    //     }

    //     return dp[n];

    // }
    int rob(vector<int>& nums) {

        int n = nums.size()-1;
        vector<int> dp(n+1,-1);
        return memo(nums,n,dp);

    }
int main() {

    vector<int> nums = {1,2,3,1};

    int ans = rob(nums);

    cout<<"Maximum money we can rob is "<<ans<<endl;

}