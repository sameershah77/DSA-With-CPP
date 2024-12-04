#include<iostream>
#include<vector>
using namespace std;

// Given an integer num, find the closest two integers in absolute difference whose product equals num + 1 or num + 2.

// Return the two integers in any order.

 

// Example 1:

// Input: num = 8
// Output: [3,3]
// Explanation: For num + 1 = 9, the closest divisors are 3 & 3, for num + 2 = 10, the closest divisors are 2 & 5, hence 3 & 3 is chosen.
// Example 2:

// Input: num = 123
// Output: [5,25]
// Example 3:

// Input: num = 999
// Output: [40,25]

    vector<int> helper(int num) {
        int x;
        int y;
        for(int i=1; i<=sqrt(num); i++) {
            if(num%i == 0) {
                x = i;
                y = num/i;
            }
        }
        return {x,y};
    }
    vector<int> closestDivisors(int num) {
        vector<int> first = helper(num+1);
        vector<int> second = helper(num+2);
        return first[1] - first[0] < second[1] - second[0] ? first : second;
    }
int main() {
    int num = 82;
    cout<<"Answer is "<<closestDivisors(num);
}