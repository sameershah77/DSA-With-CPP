#include<iostream>
#include<vector>
#include<climits>
using namespace std;

// Given an array nums of n integers where nums[i] is in the range [1, n], return an array of all the integers in the range [1, n] that do not appear in nums.

 

// Example 1:

// Input: nums = [4,3,2,7,8,2,3,1]
// Output: [5,6]
// Example 2:

// Input: nums = [1,1]
// Output: [2]
    vector<int> findDisappearedNumbers(vector<int>& nums) {
       
        int n = nums.size();
        int maxi = INT_MIN;
        for(auto val: nums) {
            maxi = max(val,maxi);
        }
        vector<bool> arr(n+1,false);


        for(int i=0; i<n ; i++) {
            arr[nums[i]] = true;
        }
        vector<int> ans;

        for(int i=1; i<=n; i++) {
            if(arr[i] == false) {
                ans.push_back(i);
            }
        }

       return ans;
    }
int main() {
    vector<int> nums = {4,3,2,7,8,2,3,1};

    nums = findDisappearedNumbers(nums);

    cout<<"Answer is "<<endl;
    for(auto val: nums) {
        cout<<val<<" ";
    }
    cout<<endl;

}