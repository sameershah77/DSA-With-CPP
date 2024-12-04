#include<iostream>
#include<algorithm>
#include<vector>

// Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]


// Example 2:

// Input: nums = [0,1]
// Output: [[0,1],[1,0]]


// Example 3:

// Input: nums = [1]
// Output: [[1]]

using namespace std;

    void permutation(vector<vector<int>> &ans,vector<int>&nums,int index) {
        if(index >= nums.size() ) {
            ans.push_back(nums);
            return;
        }

        for(int i=index;i<nums.size();i++) {
            swap(nums[i],nums[index]);
            permutation(ans,nums,index+1);
            swap(nums[i],nums[index]);
        }
    }


int main () {

        
        vector<int> nums;
        int n = 6;
        for(int i=1; i<=n; i++) {
            nums.push_back(i);
        }

        int count =0;
        vector<vector<int>>ans;
        int index =0;
        permutation(ans,nums,index);

        for(int i=0; i<ans.size(); i++) {
            count++;
            for(int j=0; j<ans[0].size(); j++) {
                cout<<ans[i][j]<<" ";
            }
            cout<<endl;
        }

         cout<<"Total number of permutations is "<<count<<endl<<endl;


}


