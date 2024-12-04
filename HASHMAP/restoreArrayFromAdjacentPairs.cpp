#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;


// There is an integer array nums that consists of n unique elements, but you have forgotten it. However, you do remember every pair of adjacent elements in nums.

// You are given a 2D integer array adjacentPairs of size n - 1 where each adjacentPairs[i] = [ui, vi] indicates that the elements ui and vi are adjacent in nums.

// It is guaranteed that every adjacent pair of elements nums[i] and nums[i+1] will exist in adjacentPairs, either as [nums[i], nums[i+1]] or [nums[i+1], nums[i]]. The pairs can appear in any order.

// Return the original array nums. If there are multiple solutions, return any of them.

 

// Example 1:

// Input: adjacentPairs = [[2,1],[3,4],[3,2]]
// Output: [1,2,3,4]
// Explanation: This array has all its adjacent pairs in adjacentPairs.
// Notice that adjacentPairs[i] may not be in left-to-right order.
// Example 2:

// Input: adjacentPairs = [[4,-2],[1,4],[-3,1]]
// Output: [-2,4,1,-3]
// Explanation: There can be negative numbers.
// Another solution is [-3,1,4,-2], which would also be accepted.
// Example 3:

// Input: adjacentPairs = [[100000,-100000]]
// Output: [100000,-100000]


    vector<int> restoreArray(vector<vector<int>>& vals) {
        unordered_map<int, vector<int>> pairs;
        
        for (const vector<int>& val : vals) {
            pairs[val[0]].push_back(val[1]);
            pairs[val[1]].push_back(val[0]);
        }
        
        vector<int> result;
        int start = -1000000;
        
        for (const auto& entry : pairs) {
            if (entry.second.size() == 1) {
                start = entry.first;
                break;
            }
        }
        
        int left = -1000000;
        result.push_back(start);
        
        for (int i = 1; i < vals.size() + 1; ++i) {
            const vector<int>& val = pairs[start];
            int newval = (val[0] == left) ? val[1] : val[0];
            result.push_back(newval);
            left = start;
            start = newval;
        }
        
        return result;
    }
    
int main() {
    vector<vector<int>> adjacentPairs = {{2,1},{3,4},{3,2}};

    vector<int> arr = restoreArray(adjacentPairs);

    cout<<"Answer is "<<endl;
    for(auto val: arr) {
        cout<<val<<" ";
    }

}