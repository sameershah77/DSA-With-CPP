#include<iostream>
#include<queue>
#include<vector>
using namespace std;

// The pair sum of a pair (a,b) is equal to a + b. The maximum pair sum is the largest pair sum in a list of pairs.

// For example, if we have pairs (1,5), (2,3), and (4,4), the maximum pair sum would be max(1+5, 2+3, 4+4) = max(6, 5, 8) = 8.
// Given an array nums of even length n, pair up the elements of nums into n / 2 pairs such that:

// Each element of nums is in exactly one pair, and
// The maximum pair sum is minimized.
// Return the minimized maximum pair sum after optimally pairing up the elements.

 

// Example 1:

// Input: nums = [3,5,2,3]
// Output: 7
// Explanation: The elements can be paired up into pairs (3,3) and (5,2).
// The maximum pair sum is max(3+3, 5+2) = max(6, 7) = 7.
// Example 2:

// Input: nums = [3,5,4,2,4,6]
// Output: 8
// Explanation: The elements can be paired up into pairs (3,5), (4,4), and (6,2).
// The maximum pair sum is max(3+5, 4+4, 6+2) = max(8, 8, 8) = 8.

    //solution 1 : T.C = O(NLOGN)  S.C. = O(N)

    // int minPairSum(vector<int>& nums) {

    //     priority_queue<int,vector<int>,greater<int>> minHeap;
    //     for(auto val: nums) {
    //         minHeap.push(val);
    //     }

    //     vector<int> pairSum;
    //     int n = nums.size();
    //     int i = 0;
    //     while(i != n/2) {
    //         pairSum.push_back(minHeap.top());
    //         minHeap.pop();
    //         i++;
    //     }
    //     i = pairSum.size()-1;
    //     while(i >= 0) {
    //         pairSum[i] += minHeap.top();
    //         minHeap.pop();
    //         i--;
    //     }
    //     int maxi = INT_MIN;
    //     for(auto val: pairSum) {
    //         maxi = max(maxi,val);
    //     }
    //     return maxi;

    // }

    //solution 1 : T.C = O(NLOGN)  S.C. = O(1)

    int minPairSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        int i=0;
        int j=nums.size()-1;

        int ans = INT_MIN;

        while(i<j) {
            int p = nums[i] + nums[j];
            ans = max(ans,p);
            i++;
            j--;
        }
        return ans;
    }
int main() {
    vector<int> nums = {3,5,4,2,4,6};
    cout<<"Answer is "<<minPairSum(nums)<<endl;
}