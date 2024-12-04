#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// You are given an integer array nums and an integer k.

// In one operation, you can choose any index i where 0 <= i < nums.length and change nums[i] to nums[i] + x where x is an integer from the range [-k, k]. You can apply this operation at most once for each index i.

// The score of nums is the difference between the maximum and minimum elements in nums.

// Return the minimum score of nums after applying the mentioned operation at most once for each index in it.

 

// Example 1:

// Input: nums = [1], k = 0
// Output: 0
// Explanation: The score is max(nums) - min(nums) = 1 - 1 = 0.
// Example 2:

// Input: nums = [0,10], k = 2
// Output: 6
// Explanation: Change nums to be [2, 8]. The score is max(nums) - min(nums) = 8 - 2 = 6.
// Example 3:

// Input: nums = [1,3,6], k = 3
// Output: 0
// Explanation: Change nums to be [4, 4, 4]. The score is max(nums) - min(nums) = 4 - 4 = 0.

    int smallestRangeI(vector<int>& nums, int k) {
        int mini = INT_MAX;
        int maxi = INT_MIN;

        for(auto val: nums) {
            if(val < mini) {
                mini = val;
            }
            if(val > maxi) {
                maxi = val;
            }
        }
        int ans = maxi - mini - 2*k;

        return ans > 0 ? ans : 0;
    }
int main() {
    vector<int> nums = {0,10}; 
    int k = 2;

    int ans = smallestRangeI(nums,k);

    cout<<"Answer is "<<ans<<endl;

}