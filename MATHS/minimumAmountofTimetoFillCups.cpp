#include<iostream>
#include<vector>
#include<priority_queue>
using namespace std;


// You have a water dispenser that can dispense cold, warm, and hot water. Every second, you can either fill up 2 cups with different types of water, or 1 cup of any type of water.

// You are given a 0-indexed integer array amount of length 3 where amount[0], amount[1], and amount[2] denote the number of cold, warm, and hot water cups you need to fill respectively. Return the minimum number of seconds needed to fill up all the cups.

 

// Example 1:

// Input: amount = [1,4,2]
// Output: 4
// Explanation: One way to fill up the cups is:
// Second 1: Fill up a cold cup and a warm cup.
// Second 2: Fill up a warm cup and a hot cup.
// Second 3: Fill up a warm cup and a hot cup.
// Second 4: Fill up a warm cup.
// It can be proven that 4 is the minimum number of seconds needed.
// Example 2:

// Input: amount = [5,4,4]
// Output: 7
// Explanation: One way to fill up the cups is:
// Second 1: Fill up a cold cup, and a hot cup.
// Second 2: Fill up a cold cup, and a warm cup.
// Second 3: Fill up a cold cup, and a warm cup.
// Second 4: Fill up a warm cup, and a hot cup.
// Second 5: Fill up a cold cup, and a hot cup.
// Second 6: Fill up a cold cup, and a warm cup.
// Second 7: Fill up a hot cup.
// Example 3:

// Input: amount = [5,0,0]
// Output: 5
// Explanation: Every second, we fill up a cold cup.
 
    int fillCups(vector<int>& amount) {
        
        //using Heaap
        // priority_queue<int> maxHeap;

        // for(auto val: amount) {
        //     maxHeap.push(val);
        // }
        // int count = 0;
        // while(maxHeap.top() != 0) {
        //     int a = maxHeap.top();
        //     maxHeap.pop();
        //     int b = maxHeap.top();
        //     maxHeap.pop();
        //     a--;
        //     b--;
        //     maxHeap.push(a);
        //     maxHeap.push(b);
        //     count++;
        // }
        // return count;

        int maxi = max(amount[0],max(amount[1],amount[2]));

        int sum = amount[0] + amount[1] + amount[2];

        if(maxi >= sum - maxi) {
            return maxi;
        }
        return (sum+1)/2;
        
    }

int main() {

    vector<int> nums = {1,4,2};

    cout<<"answer is "<<fillCups(nums)<<endl;

}