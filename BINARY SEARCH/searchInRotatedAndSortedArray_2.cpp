#include<iostream>
#include<vector>
using namespace std;


// There is an integer array nums sorted in non-decreasing order (not necessarily with distinct values).

// Before being passed to your function, nums is rotated at an unknown pivot index k (0 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,4,4,5,6,6,7] might be rotated at pivot index 5 and become [4,5,6,6,7,0,1,2,4,4].

// Given the array nums after the rotation and an integer target, return true if target is in nums, or false if it is not in nums.

// You must decrease the overall operation steps as much as possible.

 

// Example 1:

// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true
// Example 2:

// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false
    int getPivot(vector<int>& arr, int n) {

        int s = 0;
        int e = n-1;
        int mid = s + (e-s)/2;
            while(s < e && arr[s] == arr[s+1])
                s++;
            
            while(s < e && arr[e] == arr[e-1])
                e--;

        while(s<e) {
            if(arr[mid] >= arr[0]) {
                s = mid+1;
            }
            else {
                e = mid;
            }
            mid = s + (e-s)/2;
        }
        return s;
    }

    bool binarySearch(vector<int>& arr, int start, int end, int key) {

        int mid = start + (end-start)/2;
        while(start <= end) {
            if(arr[mid] == key) {
                return true;
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
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int pivot = getPivot(nums, nums.size());
        if( target >= nums[pivot] && target <= nums[nums.size()-1]) {
            //BS on second line
            return binarySearch(nums, pivot, nums.size()-1, target);
        }
        else{
            //BS on first line
            return binarySearch(nums, 0, pivot - 1, target);
        }
        return false;
    }
int main() {
    vector<int> nums = {4,5,6,7,0,1,2}; 
    int target = 0;
    
    if(search(nums,target))
        cout<<"Element found "<<endl;
    else 
        cout<<"Element not found "<<endl; 
}