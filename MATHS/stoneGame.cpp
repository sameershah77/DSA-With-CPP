#include<iostream>
#include<vector>
using namespace std;
// Alice and Bob play a game with piles of stones. There are an even number of piles arranged in a row, and each pile has a positive integer number of stones piles[i].

// The objective of the game is to end with the most stones. The total number of stones across all the piles is odd, so there are no ties.

// Alice and Bob take turns, with Alice starting first. Each turn, a player takes the entire pile of stones either from the beginning or from the end of the row. This continues until there are no more piles left, at which point the person with the most stones wins.

// Assuming Alice and Bob play optimally, return true if Alice wins the game, or false if Bob wins.

 

// Example 1:

// Input: piles = [5,3,4,5]
// Output: true
// Explanation: 
// Alice starts first, and can only take the first 5 or the last 5.
// Say she takes the first 5, so that the row becomes [3, 4, 5].
// If Bob takes 3, then the board is [4, 5], and Alice takes 5 to win with 10 points.
// If Bob takes the last 5, then the board is [3, 4], and Alice takes 4 to win with 9 points.
// This demonstrated that taking the first 5 was a winning move for Alice, so we return true.
// Example 2:

// Input: piles = [3,7,2,3]
// Output: true

    bool stoneGame(vector<int>& piles) {
        
        int n = piles.size();
        vector<int> ans;

        int i = 0;
        int j = n-1;

        while(i != j) {
            if(piles[i] < piles[j]) {
                ans.push_back(piles[j]);
                j--;
            }
            else {
                ans.push_back(piles[i]);
                i++;
            }
            
        }

        int alice = 0;
        int bob = 0;

        for(i=0; i<n; i++) {
            if(i%2 == 0) {
                alice += ans[i];
            }
            else {
                bob += ans[i];
            }
        }

        return alice > bob ? true : false;
    }
int main() {

    vector<int> nums = {5,3,4,5};

    if(stoneGame(nums)) {
        cout<<"Alice wins"<<endl;
    }
    else {
        cout<<"Bob wins"<<endl;
    }
    
}