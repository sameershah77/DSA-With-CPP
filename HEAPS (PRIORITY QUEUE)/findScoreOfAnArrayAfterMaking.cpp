#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
using namespace std;


// You are given an array nums consisting of positive integers.

// Starting with score = 0, apply the following algorithm:

// Choose the smallest integer of the array that is not marked. If there is a tie, choose the one with the smallest index.
// Add the value of the chosen integer to score.
// Mark the chosen element and its two adjacent elements if they exist.
// Repeat until all the array elements are marked.
// Return the score you get after applying the above algorithm.

 

// Example 1:

// Input: nums = [2,1,3,4,5,2]
// Output: 7
// Explanation: We mark the elements as follows:
// - 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,1,3,4,5,2].
// - 2 is the smallest unmarked element, so we mark it and its left adjacent element: [2,1,3,4,5,2].
// - 4 is the only remaining unmarked element, so we mark it: [2,1,3,4,5,2].
// Our score is 1 + 2 + 4 = 7.
// Example 2:

// Input: nums = [2,3,5,1,3,2]
// Output: 5
// Explanation: We mark the elements as follows:
// - 1 is the smallest unmarked element, so we mark it and its two adjacent elements: [2,3,5,1,3,2].
// - 2 is the smallest unmarked element, since there are two of them, we choose the left-most one, so we mark the one at index 0 and its right adjacent element: [2,3,5,1,3,2].
// - 2 is the only remaining unmarked element, so we mark it: [2,3,5,1,3,2].
// Our score is 1 + 2 + 2 = 5.


class Info{
    public: 
    int index;
    int data;
    Info(int i, int d) {
        index = i;
        data = d;
    }
};
class Comp{
    public: 
    bool operator()(Info* a, Info* b) {
        if(a->data == b->data) {
            return a->index > b->index;
        }
        else {
            return a->data > b->data;
        }

    }
};

    long long findScore(vector<int>& nums) {
        priority_queue<Info*,vector<Info*>,Comp> minHeap;

        for(int i=0; i<nums.size(); i++) {
            Info* temp = new Info(i,nums[i]);
            minHeap.push(temp);
        }    
        
        unordered_map<int,bool> mp;
        long long ans = 0;
        int n = nums.size();

        while(n--){
            Info* temp = minHeap.top();
            minHeap.pop();

            int val = temp->data;
            int ind = temp->index;
            if(mp.find(ind) == mp.end()) {
                ans += val;
                mp[ind] = true;
                mp[ind-1] = true;
                mp[ind+1] = true;
            }
        }
        return ans;
    }

int main() {
    vector<int> nums = {2,1,3,4,5,2};
    long long ans = findScore(nums);

    cout<<"Answer is "<<ans<<endl;

}