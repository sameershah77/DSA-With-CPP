#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;



// You are given an array nums that consists of non-negative integers. Let us define rev(x) as the reverse of the non-negative integer x. For example, rev(123) = 321, and rev(120) = 21. A pair of indices (i, j) is nice if it satisfies all of the following conditions:

// 0 <= i < j < nums.length
// nums[i] + rev(nums[j]) == nums[j] + rev(nums[i])
// Return the number of nice pairs of indices. Since that number can be too large, return it modulo 109 + 7.

 

// Example 1:

// Input: nums = [42,11,1,97]
// Output: 2
// Explanation: The two pairs are:
//  - (0,3) : 42 + rev(97) = 42 + 79 = 121, 97 + rev(42) = 97 + 24 = 121.
//  - (1,2) : 11 + rev(1) = 11 + 1 = 12, 1 + rev(11) = 1 + 11 = 12.
// Example 2:

// Input: nums = [13,10,35,24,76]
// Output: 4


    int reverse(int n) {
        int ans = 0;
        while(n != 0) {
            ans += n%10;
            n = n/10;
            if(n != 0) {
                ans *= 10;
            }            
        }
        return ans;
    }
    int countNicePairs(vector<int>& nums) {

        unordered_map<int,int> mp;
        int count = 0;
        for(int i=0; i<nums.size(); i++) {
            int temp = nums[i] - reverse(nums[i]);
            if(mp.count(temp) == true) {
                count += mp[temp];
                count %= (int)1e9+7;
            }
            mp[temp]++;
        }

        return count; 
    }
int main() {

    vector<int> nums = {42,11,1,97};

    cout<<"Number of nice pairs is "<<countNicePairs(nums)<<endl;

}