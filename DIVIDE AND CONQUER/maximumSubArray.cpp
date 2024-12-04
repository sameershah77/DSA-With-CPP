#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using namespace std;


// Given an integer array nums, find the 
// subarray
//  with the largest sum, and return its sum.

 

// Example 1:

// Input: nums = [-2,1,-3,4,-1,2,1,-5,4]
// Output: 6
// Explanation: The subarray [4,-1,2,1] has the largest sum 6.

// Example 2:

// Input: nums = [1]
// Output: 1
// Explanation: The subarray [1] has the largest sum 1.

// Example 3:

// Input: nums = [5,4,-1,7,8]
// Output: 23
// Explanation: The subarray [5,4,-1,7,8] has the largest sum 23.
 

// Constraints:

// 1 <= nums.length <= 105
// -104 <= nums[i] <= 104
 

// Follow up: If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.


    int maxSumArrayFinder(vector<int> &nums,int start,int end) {
        if(start==end) {
            return nums[start];
        }
        int mid = start+(end-start)/2;

        int maxLeftBorderSum = INT_MIN;
        int maxRightBorderSum = INT_MIN;

        int maxLeftSum = maxSumArrayFinder(nums,start,mid);
        int maxRightSum = maxSumArrayFinder(nums,mid+1,end);

        int leftBorderSum = 0;
        int rightBorderSum = 0;
        //cross border max sum for left
        
        for(int i=mid; i>=start; i--) {
            leftBorderSum += nums[i];
            if(leftBorderSum > maxLeftBorderSum) {
                maxLeftBorderSum = leftBorderSum;
            }
        } 
        //cross border max for right
        for(int i=mid+1; i<=end; i++) {
            rightBorderSum += nums[i];
            if(rightBorderSum > maxRightBorderSum) {
                maxRightBorderSum = rightBorderSum;
            }
        } 
        int crossBorderSum = maxLeftBorderSum + maxRightBorderSum;
        return max(maxLeftSum,max(maxRightSum,crossBorderSum));
    }
    int maxSubArray(vector<int>& nums) {
        return maxSumArrayFinder(nums,0,nums.size()-1);
    }
int main() {
    vector<int> arr = {-2,1,-3,4,-1,2,1,-5,4};
    int ans = maxSubArray(arr);

    cout<<"Maximum of sum of sub array is "<<ans<<endl;

}