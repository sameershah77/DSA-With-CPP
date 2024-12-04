#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
using namespace std;

// Given an integer array nums, return all the triplets [nums[i], nums[j], nums[k]] such that i != j, i != k, and j != k, and nums[i] + nums[j] + nums[k] == 0.

// Notice that the solution set must not contain duplicate triplets.

 

// Example 1:

// Input: nums = [-1,0,1,2,-1,-4]
// Output: [[-1,-1,2],[-1,0,1]]
// Explanation: 
// nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
// nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
// nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
// The distinct triplets are [-1,0,1] and [-1,-1,2].
// Notice that the order of the output and the order of the triplets does not matter.
// Example 2:

// Input: nums = [0,1,1]
// Output: []
// Explanation: The only possible triplet does not sum up to 0.
// Example 3:

// Input: nums = [0,0,0]
// Output: [[0,0,0]]
// Explanation: The only possible triplet sums up to 0.

    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        map<vector<int>,int> mp;
        for(int i=0; i<nums.size(); i++) {
            int j = i+1;
            int k = nums.size()-1;
            while(j<k) {
                int sum = nums[i]+nums[j]+nums[k];
                if(sum == 0) {
                    mp[{nums[i],nums[j],nums[k]}]++;
                    j++;
                    k--;
                }
                else if(sum < 0) {
                    j++;
                }
                else {
                    k--;
                }
            }
        }

        vector<vector<int>> ans;

        for(auto val: mp) {
            ans.push_back(val.first);
        }
        return ans;
    }

    int main() {

        vector<int> nums = {-1,0,1,2,-1,-4};

        vector<vector<int>> ans = threeSum(nums);

        cout<<"Answer are "<<endl;

        for(auto val: ans) {
            for(auto i: val) {
                cout<<i<<" ";
            }
            cout<<endl;
        }

    }