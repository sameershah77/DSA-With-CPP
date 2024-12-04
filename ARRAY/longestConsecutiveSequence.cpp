#include<iostream>
#include<vector>
using namespace std;

// Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.

// You must write an algorithm that runs in O(n) time.

 

// Example 1:

// Input: nums = [100,4,200,1,3,2]
// Output: 4
// Explanation: The longest consecutive elements sequence is [1, 2, 3, 4]. Therefore its length is 4.
// Example 2:

// Input: nums = [0,3,7,2,5,8,4,6,0,1]
// Output: 9

    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        if(nums.size() == 1) {
            return 1;
        }
        if(nums.size() == 0) {
            return 0;
        }
        
        int maxCount = INT_MIN;
        int count = 1;
        for(int i=1; i<nums.size(); i++) {
            if(nums[i] - nums[i-1] == 1) {
                count++;
            }
            else if(nums[i] - nums[i-1] == 0) {
                continue;
            }
            else {
                maxCount = max(maxCount,count);
                count = 1;
            }
        }
        maxCount = max(maxCount,count);
        return maxCount;
    }

int main() {

    vector<int> nums = {100,4,200,1,3,2};
    cout<<"Answer is "<<longestConsecutive(nums)<<endl;
}