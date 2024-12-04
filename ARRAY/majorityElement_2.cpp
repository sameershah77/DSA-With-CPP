#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
// Given an integer array of size n, find all elements that appear more than ⌊ n/3 ⌋ times.

 

// Example 1:

// Input: nums = [3,2,3]
// Output: [3]
// Example 2:

// Input: nums = [1]
// Output: [1]
// Example 3:

// Input: nums = [1,2]
// Output: [1,2]
    vector<int> majorityElement(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int,int> mp;
        vector<int> ans;
        for(auto val: nums) {
            mp[val]++;
        }    

        for(auto val: mp) {
            if(val.second>n/3) {
                ans.push_back(val.first);
            }
        }    
        return ans;
    }
int main() {

    vector<int> nums = {3,1,3};

    cout<<"Majority Elements are "<<endl;

    vector<int> ans = majorityElement(nums);


    for(auto val:ans) {
        cout<<val<<" ";
    }


}