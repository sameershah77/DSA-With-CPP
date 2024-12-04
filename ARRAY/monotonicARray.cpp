#include<iostream>
#include<vector>
using namespace std;

// An array is monotonic if it is either monotone increasing or monotone decreasing.

// An array nums is monotone increasing if for all i <= j, nums[i] <= nums[j]. An array nums is monotone decreasing if for all i <= j, nums[i] >= nums[j].

// Given an integer array nums, return true if the given array is monotonic, or false otherwise.



// Example 1:

// Input: nums = [1,2,2,3]
// Output: true
// Example 2:

// Input: nums = [6,5,4,4]
// Output: true
// Example 3:

// Input: nums = [1,3,2]
// Output: false
    bool isMonotonic(vector<int>& nums) {

        int increase = true;
        int decrease = true;
        for(int i=0; i<nums.size()-1; i++) {
            if(nums[i] < nums[i+1]) {
                increase = false;
            }
            if(nums[i] > nums[i+1]) {
                decrease = false;
            }

            if(increase == false && decrease == false) {
                return false;
            }
        }

        return true;
    }
int main() {
    vector<int> arr1 = {2,5,7,9};
    vector<int> arr2 = {9,7,5,3};

    vector<int> arr3 = {3,8,4,7,};

    if(isMonotonic(arr1)) {
        cout<<"arr1 is monotonic"<<endl;
    }
    else {
        cout<<"arr1 is not monotonic"<<endl;
    }


    if(isMonotonic(arr2)) {
        cout<<"arr2 is monotonic"<<endl;
    }
    else {
        cout<<"arr2 is not monotonic"<<endl;
    }


    if(isMonotonic(arr3)) {
        cout<<"arr3 is monotonic"<<endl;
    }
    else {
        cout<<"arr3 is not monotonic"<<endl;
    }

}