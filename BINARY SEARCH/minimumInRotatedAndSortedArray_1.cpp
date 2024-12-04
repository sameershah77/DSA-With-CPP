#include<iostream>
#include<vector>
using namespace std;


// Suppose an array of length n sorted in ascending order is rotated between 1 and n times. For example, the array nums = [0,1,2,4,5,6,7] might become:

// [4,5,6,7,0,1,2] if it was rotated 4 times.
// [0,1,2,4,5,6,7] if it was rotated 7 times.
// Notice that rotating an array [a[0], a[1], a[2], ..., a[n-1]] 1 time results in the array [a[n-1], a[0], a[1], a[2], ..., a[n-2]].

// Given the sorted rotated array nums of unique elements, return the minimum element of this array.

// You must write an algorithm that runs in O(log n) time.

 

// Example 1:

// Input: nums = [3,4,5,1,2]
// Output: 1
// Explanation: The original array was [1,2,3,4,5] rotated 3 times.
// Example 2:

// Input: nums = [4,5,6,7,0,1,2]
// Output: 0
// Explanation: The original array was [0,1,2,4,5,6,7] and it was rotated 4 times.
// Example 3:

// Input: nums = [11,13,15,17]
// Output: 11
// Explanation: The original array was [11,13,15,17] and it was rotated 4 times.


int getPivot(vector<int>arr, int n) {

    int s=0;
    int e=n-1;
    int mid = s+(e-s)/2;

    while(s<=e) {
        if(arr[mid] > arr[mid+1] && mid+1 < n) {
            return mid;
        }
        if(arr[mid] < arr[mid-1] && mid-1 >= 0) {
            return mid-1;
        }
        if (arr[s] >= arr[mid]) {
            e = mid-1;
        }
        else {
            s = mid+1;
        }
        mid = s+(e-s)/2;
    }
    return 0;

}

    int findMin(vector<int>& nums) {

        if(nums.size() == 1) {
            return nums[0];
        }
        //if array not rotated and it is sorted
        if(nums[0] < nums[nums.size()-1]) {
            return nums[0];
        }

        int pivot = getPivot(nums, nums.size());

        if(nums[0] > nums[pivot+1] && pivot+1 < nums.size()) {
            return nums[pivot+1];
        }
        return nums[0];
    }


int main() {

    vector<int> arr = {3,4,5,1,2};

    cout<<"Answer is "<<findMin(arr)<<endl;

}