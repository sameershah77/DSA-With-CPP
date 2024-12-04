#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// Given an array of integers nums, return the number of good pairs.

// A pair (i, j) is called good if nums[i] == nums[j] and i < j.

 

// Example 1:

// Input: nums = [1,2,3,1,1,3]
// Output: 4
// Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
// Example 2:

// Input: nums = [1,1,1,1]
// Output: 6
// Explanation: Each pair in the array are good.
// Example 3:

// Input: nums = [1,2,3]
// Output: 0
    int numIdenticalPairs(vector<int>& nums) {
        unordered_map<int, int> m;
        int count = 0;
        for(auto val : nums){
            count += m[val];
            m[val]++;
        }
        return count;
    }
int main() {

    vector<int> nums = {1,2,3,1,1,3};


    cout<<"Number of good pairs are "<<numIdenticalPairs(nums)<<endl;
    // Output: 4
    // Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.
}