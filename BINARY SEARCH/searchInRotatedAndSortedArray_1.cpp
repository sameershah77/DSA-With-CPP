#include<iostream>
#include<vector>
using namespace std;

// There is an integer array nums sorted in ascending order (with distinct values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity.

 

// Example 1:

// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Example 2:

// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
// Example 3:

// Input: nums = [1], target = 0
// Output: -1

    int getPivot(vector<int>& arr, int n) {

        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;

        while(s<e) {

            if(arr[mid] >= arr[0])
            {
                s = mid+1;
            }
            else{
                e = mid;
            }
            mid = s + (e-s)/2;
        }
        return s;
    }

    int binarySearch(vector<int>& arr, int start, int end, int key) {

        int mid = start + (end-start)/2;
        while(start <= end) {
            if(arr[mid] == key) {
                return mid;
            }
            //go to right wala part
            if(key > arr[mid]) {
                start = mid + 1;
            }
            else{ //key < arr[mid]
                end = mid - 1;
            }
            mid = start + (end-start)/2;
        }
        return -1;
    }

    int search(vector<int>& nums, int target) {

        int pivot = getPivot(nums, nums.size());
        if( target >= nums[pivot] && target <= nums[nums.size()-1]) {
            //BS on second line
            return binarySearch(nums, pivot, nums.size()-1, target);
        }
        else{
            //BS on first line
            return binarySearch(nums, 0, pivot - 1, target);
        }
        return -1;
    }
int main() {
    vector<int> nums = {4,5,6,7,0,1,2}; 
    int target = 0;
    int index = search(nums,target);

    cout<<"Element found at index "<<index<<endl;

}