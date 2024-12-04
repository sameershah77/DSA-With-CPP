#include<iostream>
#include<vector>
using namespace std;
// Given an integer array nums of unique elements, return all possible 
// subsets
//  (the power set).

// The solution set must not contain duplicate subsets. Return the solution in any order.

 

// Example 1:

// Input: nums = [1,2,3]
// Output: [[],[1],[2],[1,2],[3],[1,3],[2,3],[1,2,3]]
// Example 2:

// Input: nums = [0]
// Output: [[],[0]]
    void solve(vector<int> &nums,vector<vector<int>> &ans, vector<int> &result,int i,int &count) {

        if(i>=nums.size()) {
            count++;
            ans.push_back(result);
            
            return;
        }
        
        //Include
        result.push_back(nums[i]);
        solve(nums,ans,result,i+1,count);
        result.pop_back();
        //Exclude

        solve(nums,ans,result,i+1,count); 

    }


    vector<vector<int>> subsets(vector<int>& nums,int &count) {
        vector<vector<int>>ans;
        int i=0;
        

        vector<int> result;
        solve(nums,ans,result,i,count);
        return ans;
    }
int main() {


    vector<int> nums = {1,2,3};
    int count = 0;
    vector<vector<int>> arr = subsets(nums,count);
    cout<<"Total numbsr of subsets are "<<count<<endl;
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr[0].size(); j++) {
            if(arr[i][j] > nums[nums.size()-1] || arr[i][j] <=0) {   // this condition is only to avoid garbage value
                arr[i][j]=0;
            }
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    

    
}