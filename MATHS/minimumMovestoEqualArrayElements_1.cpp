#include<iostream>
#include<vector>
using namespace std;

// Given an integer array nums of size n, return the minimum number of moves required to make all array elements equal.

// In one move, you can increment n - 1 elements of the array by 1.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: 3
// Explanation: Only three moves are needed (remember each move increments two elements):
// [1,2,3]  =>  [2,3,3]  =>  [3,4,3]  =>  [4,4,4]
// Example 2:

// Input: nums = [1,1,1]
// Output: 0
    int minMoves(vector<int>& nums) {
        int mini = INT_MAX;

        for(auto val: nums) {
            mini = min(val,mini);
        }

        int count = 0;

        for(auto val: nums) {
            count += (val - mini);
        }

        return count;
    }
int main() {

    vector<int> nums = {1,2,3,4,5};

    cout<<"Answer is "<<minMoves(nums)<<endl;

}