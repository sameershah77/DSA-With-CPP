#include<iostream>
#include<vector>
#include<climits>
#include<algorithm>
using  namespace std;


// You are given an integer array nums. A number x is lonely when it appears only once, and no adjacent numbers (i.e. x + 1 and x - 1) appear in the array.

// Return all lonely numbers in nums. You may return the answer in any order.

 

// Example 1:

// Input: nums = [10,6,5,8]
// Output: [10,8]
// Explanation: 
// - 10 is a lonely number since it appears exactly once and 9 and 11 does not appear in nums.
// - 8 is a lonely number since it appears exactly once and 7 and 9 does not appear in nums.
// - 5 is not a lonely number since 6 appears in nums and vice versa.
// Hence, the lonely numbers in nums are [10, 8].
// Note that [8, 10] may also be returned.
// Example 2:

// Input: nums = [1,3,5,3]
// Output: [1,5]
// Explanation: 
// - 1 is a lonely number since it appears exactly once and 0 and 2 does not appear in nums.
// - 5 is a lonely number since it appears exactly once and 4 and 6 does not appear in nums.
// - 3 is not a lonely number since it appears twice.
// Hence, the lonely numbers in nums are [1, 5].

    vector<int> findLonely(vector<int>& nums) {
        nums.push_back(INT_MIN);
        nums.push_back(INT_MAX);
        sort(nums.begin(),nums.end());
        
        
        vector<int> ans;
        
        for(int i=0; i<nums.size(); i++) {
            if(i+1 < nums.size() && i-1 >= 0 && nums[i]+1 != nums[i+1] && nums[i]-1 != nums[i-1] && nums[i] != nums[i+1] && nums[i] != nums[i-1]) {
                ans.push_back(nums[i]);
            }
        }
        return ans;

    }
int main() {
    vector<int> nums = {10,6,5,8};

    nums = findLonely(nums);

    cout<<"Lonely Elements are "<<endl;

    for(auto val: nums) {
        cout<<val<<" ";
    }
    cout<<endl;


}