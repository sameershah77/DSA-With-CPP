#include<iostream>
#include<vector>
#include<math.h>
using namespace std;

// Given an integer array nums, return the sum of divisors of the integers in that array that have exactly four divisors. If there is no such integer in the array, return 0.

 

// Example 1:

// Input: nums = [21,4,7]
// Output: 32
// Explanation: 
// 21 has 4 divisors: 1, 3, 7, 21
// 4 has 3 divisors: 1, 2, 4
// 7 has 2 divisors: 1, 7
// The answer is the sum of divisors of 21 only.
// Example 2:

// Input: nums = [21,21]
// Output: 64
// Example 3:

// Input: nums = [1,2,3,4,5]
// Output: 0

int sumFourDivisors(vector<int>& nums) {

        int totalSum = 0;

        for(auto val: nums) {
            int count = 0;
            int sum = 0;
            for(int j=1; j<=sqrt(val); j++) {
                if(val%j == 0) {
                    if(val/j != j) {
                        count += 2;
                        sum += j;
                        sum += val/j;
                    }
                    else {
                        count++;
                        sum += j;
                    }
                }
            }
            if(count == 4) totalSum += sum;
        }
        return totalSum;
    }


int main() {

    vector<int> nums = {21,4,7};
    cout<<"Answer is "<<sumFourDivisors(nums)<<endl;
}
    