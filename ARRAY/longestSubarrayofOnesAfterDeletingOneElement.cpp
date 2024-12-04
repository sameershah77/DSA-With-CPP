#include <iostream>
#include<vector>
#include<climits>
using namespace std;

// Given a binary array nums, you should delete one element from it.

// Return the size of the longest non-empty subarray containing only 1's in the resulting array. Return 0 if there is no such subarray.

 

// Example 1:

// Input: nums = [1,1,0,1]
// Output: 3
// Explanation: After deleting the number in position 2, [1,1,1] contains 3 numbers with value of 1's.
// Example 2:

// Input: nums = [0,1,1,1,0,1,1,0,1]
// Output: 5
// Explanation: After deleting the number in position 4, [0,1,1,1,1,1,0,1] longest subarray with value of 1's is [1,1,1,1,1].
// Example 3:

// Input: nums = [1,1,1]
// Output: 2
// Explanation: You must delete one element.
 

// Constraints:

// 1 <= nums.length <= 105
// nums[i] is either 0 or 1.

    int longestSubarray(vector<int>& nums) {
        vector<int> arr;
        int one = 0;
        for(auto val: nums) {
            if(val == 0) {
                if(!arr.empty()) {
                    arr[arr.size()-1] += one;
                    arr.push_back(one);
                }
                else {
                    arr.push_back(one);
                }
                one = 0;
            }
            else {
                one++;
            }
        }
        if(!arr.empty()) {
            arr[arr.size()-1] += one;
        }
        
        int maxi = INT_MIN;
        if(!arr.empty()) {
            for(auto val: arr) {
                maxi = max(val,maxi);
            }
        }
        return maxi == INT_MIN ? nums.size()-1 : maxi;
    }

int main () {
    vector<int> nums = {0,1,1,1,0,1,1,0,1};

    cout<<"Answer is "<<longestSubarray(nums)<<endl;
}