#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;


// Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.

// Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.

 

// Example 1:

// Input: hand = [1,2,3,6,2,3,4,7,8], groupSize = 3
// Output: true
// Explanation: Alice's hand can be rearranged as [1,2,3],[2,3,4],[6,7,8]
// Example 2:

// Input: hand = [1,2,3,4,5], groupSize = 4
// Output: false
// Explanation: Alice's hand can not be rearranged into groups of 4.

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int, int> countMap;
        for (int card : hand) {
            countMap[card]++;
        }
        
        sort(hand.begin(), hand.end());
        
        for (int i = 0; i < hand.size(); i++) {
            if (countMap[hand[i]] == 0) {
                continue;
            }
            
            for (int j = 0; j < groupSize; j++) {
                int currCard = hand[i] + j;
                
                if (countMap[currCard] == 0) {
                    return false;
                }
                
                countMap[currCard]--;
            }
        }
        
        return true;
    }
int main() {

    vector<int> arr = {1,2,3,6,2,3,4,7,8}; 
    int groupSize = 3;

    if(isNStraightHand(arr,groupSize))  {
        cout<<"She can arrenge the cards"<<endl;
    }
    else {
        cout<<"She can't arrenge the cards"<<endl;
    }

}