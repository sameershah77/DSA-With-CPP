#include<iostream>
using namespace std;


// You are standing at position 0 on an infinite number line. There is a destination at position target.

// You can make some number of moves numMoves so that:

// On each move, you can either go left or right.
// During the ith move (starting from i == 1 to i == numMoves), you take i steps in the chosen direction.
// Given the integer target, return the minimum number of moves required (i.e., the minimum numMoves) to reach the destination.

 

// Example 1:

// Input: target = 2
// Output: 3
// Explanation:
// On the 1st move, we step from 0 to 1 (1 step).
// On the 2nd move, we step from 1 to -1 (2 steps).
// On the 3rd move, we step from -1 to 2 (3 steps).
// Example 2:

// Input: target = 3
// Output: 2
// Explanation:
// On the 1st move, we step from 0 to 1 (1 step).
// On the 2nd move, we step from 1 to 3 (2 steps).


    int reachNumber(int target) {
        //Egde Cases
        target = abs(target);
        
        int step = 0; // Number of moves
        int sum = 0;
        
        while(true){
            step++; // increment step at each iteration
            sum = sum + step;
            //if at certain point after adding step with sum,
            // sum == target, we found our result!
            if(sum == target){
                return step;
            }
            //if sum becomes greater than target and difference of sum and target is even, return step
            else if(sum>target && (sum-target)%2==0){
                return step;
            }
        }
    }


int main() {

    int target = 2;

    int ans = reachNumber(target);

    cout<<"Answer is "<<ans<<endl;

}