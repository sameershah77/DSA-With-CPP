#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

// You must implement a solution with a linear runtime complexity and use only constant extra space.

 

// Example 1:

// Input: nums = [2,2,3,2]
// Output: 3
// Example 2:

// Input: nums = [0,1,0,1,0,1,99]
// Output: 99
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto val:nums) {
            mp[val]++;
        }
        for(auto val:mp)  {
            if(val.second  ==  1)  {
                return val.first;
                break;
            }
        }
        return -1;
    }
int main() {
    vector<int> nums = {2,2,3,2};
    cout<<"Anwer is "<<singleNumber(nums)<<endl;

}