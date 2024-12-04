#include<iostream>
#include<vector>
using namespace std;

// Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

// In one move, you can increment or decrement an element of the array by 1.

// Test cases are designed so that the answer will fit in a 32-bit integer.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: 2
// Explanation:
// Only two moves are needed (remember each move increments or decrements one element):
// [1,2,3]  =>  [2,2,3]  =>  [2,2,2]
// Example 2:

// Input: nums = [1,10,2,9]
// Output: 16

    int minMoves2(vector<int>& nums) {

        sort(nums.begin(),nums.end());

        int middle = nums[nums.size()/2];

        int count = 0;

        for(auto val: nums) {
            count += abs(middle - val);
        }

        return count;
    }
int main() {

    vector<int> nums = {1,2,3,4,5};

    cout<<"Answer is "<<minMoves2(nums)<<endl;

}