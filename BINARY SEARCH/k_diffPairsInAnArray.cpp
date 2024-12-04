#include<iostream>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
using namespace std;


// Using Binary Search T.C. - O(n*logn) 
    int bs(vector<int> nums,int start,int end,int target) {
        while(start<=end) {
            int mid = start + (end-start)/2;
            if(nums[mid]==target) {
                return mid;
            }
            else if(target > nums[mid]) {
                start = mid+1;
            }
            else {
                end = mid-1;
            }
            
        }
        return -1;
    }
    int findPairs(vector<int>& nums, int k) {
        
        sort(nums.begin(),nums.end());
        set<pair<int,int>> ans;

        for(int i=0;i<nums.size();i++) {
            if(bs(nums,i+1,nums.size()-1,nums[i]+k) != -1) {
                ans.insert({nums[i],nums[i]+k});
            }
        }
        return ans.size();

    }

    //another method using two pointers .... T.C.- O(n^2)
    // int findPairs(vector<int>& nums, int k) {
        
    //     sort(nums.begin(),nums.end());
    //     set<pair<int,int>> ans;
    //     int i=0;
    //     int j=1;
    //     while(j<nums.size()) {
    //         int diff = nums[j]-nums[i];
    //         if(diff==k) {
    //             ans.insert({nums[i],nums[j]});
    //             i++;
    //             j++;
    //         }
    //         else if(diff >k) {
    //             i++;
    //         }
    //         else {
    //             j++;
    //         }
    //         if(i==j) {
    //             j++;
    //         }
    //     }
    //     return ans.size();
    // }
int main () {
    vector<int> nums = {1,3,4,5,1};
    int k=3;
    int ans = findPairs(nums,k);
    cout<<"Number of pairs are "<<ans<<endl;

}