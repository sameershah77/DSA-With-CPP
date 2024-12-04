#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
// Given an array nums of size n, return the majority element.

// The majority element is the element that appears more than ⌊n / 2⌋ times. You may assume that the majority element always exists in the array.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: 3
// Example 2:

// Input: nums = [2,2,1,1,1,2,2]
// Output: 2
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        if(nums.size()==1) {
            return nums[0];
        }
        int count =0;
        for(int i=0;i<nums.size()-1;i++) {
            if(nums[i]==nums[i+1]) {
                count++;
            }
            else {
                count=0;
            }
            if(count>=nums.size()/2) {
                return nums[i];
            }
        }
        return 0;
    }
int main() {

    vector<int> nums = {2,2,1,1,1,2,2};

    cout<<"Majority Element is "<<majorityElement(nums)<<endl;


}