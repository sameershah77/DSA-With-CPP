#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;

// You are given a 2D integer grid of size m x n and an integer x. In one operation, you can add x to or subtract x from any element in the grid.

// A uni-value grid is a grid where all the elements of it are equal.

// Return the minimum number of operations to make the grid uni-value. If it is not possible, return -1.

 

// Example 1:


// Input: grid = [[2,4],[6,8]], x = 2
// Output: 4
// Explanation: We can make every element equal to 4 by doing the following: 
// - Add x to 2 once.
// - Subtract x from 6 once.
// - Subtract x from 8 twice.
// A total of 4 operations were used.
// Example 2:


// Input: grid = [[1,5],[2,3]], x = 1
// Output: 5
// Explanation: We can make every element equal to 3.
// Example 3:


// Input: grid = [[1,2],[3,4]], x = 2
// Output: -1
// Explanation: It is impossible to make every element equal.


    int minOperations(vector<vector<int>>& grid, int x) {

        vector<int> nums;

        for(auto val1: grid) {
            for(auto val2: val1) {
                nums.push_back(val2);
            }
        }        
        sort(nums.begin(),nums.end());
        int middle = nums[nums.size()/2];
        int count = 0;

        for(auto val: nums) {
            if((abs(middle - val)%x) != 0) {
                return -1;
            }
            else {
                count += (abs(middle - val)/x);
            }
        }
        return count;
    }
int main() {

    vector<vector<int>> grid = {{2,4},{6,8}}; 
    int x = 2;

    cout<<"ANSwer is "<<minOperations(grid)<<endl;

}