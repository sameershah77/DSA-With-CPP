#include<iostream>
#include<vector>
using namespace std;

// Given an integer array nums, return the length of the longest strictly increasing 
// subsequence
// .

 

// Example 1:

// Input: nums = [10,9,2,5,3,7,101,18]
// Output: 4
// Explanation: The longest increasing subsequence is [2,3,7,101], therefore the length is 4.
// Example 2:

// Input: nums = [0,1,0,3,2,3]
// Output: 4
// Example 3:

// Input: nums = [7,7,7,7,7,7,7]
// Output: 1

    // TC - O(N*logN) and SC - O(N)
    int optimalBinarySearch(vector<int>& nums) {
        if(nums.size() == 0) return 0;

        vector<int> ans;
        ans.push_back(nums[0]);

        for(int i = 1; i < nums.size(); i++) {
            if(nums[i] > ans.back())
                ans.push_back(nums[i]);
            else{
                // overwrite the previous just big element
                int index = lower_bound(ans.begin(),ans.end(),nums[i]) - ans.begin();
                ans[index] = nums[i];
            }
        }
        return ans.size();
    }

    int lengthOfLIS(vector<int>& nums) {
        return optimalBinarySearch(nums);
    }

int main() {
    vector<int> nums = {10,9,2,5,3,7,101,18};

    cout<<"Asnwer is "<<optimalBinarySearch(nums)<<endl;

}