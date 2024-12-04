#include<iostream>
#include<vector>
#include<queue>
#include<unordered_map>
using namespace std;

// You are given a 0-indexed array nums consisting of positive integers. You can choose two indices i and j, such that i != j, and the sum of digits of the number nums[i] is equal to that of nums[j].

// Return the maximum value of nums[i] + nums[j] that you can obtain over all possible indices i and j that satisfy the conditions.

 

// Example 1:

// Input: nums = [18,43,36,13,7]
// Output: 54
// Explanation: The pairs (i, j) that satisfy the conditions are:
// - (0, 2), both numbers have a sum of digits equal to 9, and their sum is 18 + 36 = 54.
// - (1, 4), both numbers have a sum of digits equal to 7, and their sum is 43 + 7 = 50.
// So the maximum sum that we can obtain is 54.
// Example 2:

// Input: nums = [10,12,19,14]
// Output: -1
// Explanation: There are no two numbers that satisfy the conditions, so we return -1.

    int getDigitSum(int num) {
        int sum = 0;
        while (num>0) {
            sum += (num % 10);
            num /= 10;
        }
        return sum;
    }
    int maximumSum(vector<int>& nums) {

        int n = nums.size();

        unordered_map<int,priority_queue<int>> digitCount;

        for(int i=0; i<nums.size(); i++) {
            int digit = getDigitSum(nums[i]);
            digitCount[digit].push(nums[i]);
        }

        int maxi = -1;
        for(auto val: digitCount) {
            if(val.second.size() > 1) {
                int x = val.second.top();
                val.second.pop();
                x += val.second.top();
                val.second.pop();
                maxi = max(maxi,x);
            }
        }

        return maxi;
    }

int main() {

    vector<int> nums = {18,43,36,13,7};

    cout<<"Answer is "<<maximumSum(nums)<<endl;

}