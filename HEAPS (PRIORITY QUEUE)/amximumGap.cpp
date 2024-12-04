#include<iostream>
#include<vector>
#include<queue>
#include<climits>
using namespace std;
// Given an integer array nums, return the maximum difference between two successive elements in its sorted form. If the array contains less than two elements, return 0.

// You must write an algorithm that runs in linear time and uses linear extra space.

 

// Example 1:

// Input: nums = [3,6,9,1]
// Output: 3
// Explanation: The sorted form of the array is [1,3,6,9], either (3,6) or (6,9) has the maximum difference 3.
// Example 2:

// Input: nums = [10]
// Output: 0
// Explanation: The array contains less than 2 elements, therefore return 0.
    int maximumGap(vector<int>& nums) {
        if(nums.size() < 2)  {
            return 0;
        }        
        priority_queue<int,vector<int>,greater<int>>minHeap;
        for(auto val: nums)  {
            minHeap.push(val);
        }
        int el = minHeap.top();
        minHeap.pop();
        int diff = INT_MIN;

        while(minHeap.empty() == false){
            int e =  minHeap.top();
            if(diff < e - el) {
                diff = e - el;
            }
            minHeap.pop();
            el = e;
        }
        return diff;
    }
int main() {
    vector<int> nums = {3,6,9,1};

    cout<<"Answer is "<<maximumGap(nums)<<endl;

}