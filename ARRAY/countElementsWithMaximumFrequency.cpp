#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// You are given an array nums consisting of positive integers.

// Return the total frequencies of elements in nums such that those elements all have the maximum frequency.

// The frequency of an element is the number of occurrences of that element in the array.

 

// Example 1:

// Input: nums = [1,2,2,3,1,4]
// Output: 4
// Explanation: The elements 1 and 2 have a frequency of 2 which is the maximum frequency in the array.
// So the number of elements in the array with maximum frequency is 4.
// Example 2:

// Input: nums = [1,2,3,4,5]
// Output: 5
// Explanation: All elements of the array have a frequency of 1 which is the maximum.
// So the number of elements in the array with maximum frequency is 5.

    int maxFrequencyElements(vector<int>& nums) {
        
        vector<int> freq(101,0);
        
        for(int i=0; i<nums.size(); i++) {
            freq[nums[i]]++;
        }
        
        int maxi = INT_MIN;
        for(auto val: freq) {
            maxi = max(maxi,val);
        }
        int ans = 0;
        for(auto val: freq) {
            if(val == maxi) {
                ans += val;
            }
        }
        return ans;
        
    }

int main() {

    vector<int> nums = {1,2,2,3,1,4};

    cout<<"Answer is "<<maxFrequencyElements(nums)<<endl;

}