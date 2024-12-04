#include<iostream>
#include<vector>
#include<climits>
#include<math.h>
using namespace std;


// Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.

// Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.

// Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.

// Return the minimum integer k such that she can eat all the bananas within h hours.

 

// Example 1:

// Input: piles = [3,6,7,11], h = 8
// Output: 4
// Example 2:

// Input: piles = [30,11,23,4,20], h = 5
// Output: 30
// Example 3:

// Input: piles = [30,11,23,4,20], h = 6
// Output: 23
    int calculateTotalBananas(vector<int>& arr, int& banana) {
        int sum = 0;
        for(auto val: arr) {
            sum += ceil((double)val/(double)banana);
        }
        return sum;
    }
    
    int minEatingSpeed(vector<int>& piles, int h) {

        int start = 1;

        int end = INT_MIN;
        for(auto val: piles) {
            end = max(end,val);
        }
        
        int mid = start + (end - start)/2;

        while(start <= end) {
            
            if(calculateTotalBananas(piles,mid) <= h) {
                end = mid - 1;
            }
            else {
                start = mid + 1;
            }
            mid = start + (end - start)/2;
        }  
        return start;
    }
int main() {
    vector<int> piles = {3,6,7,11}; 
    int h = 8;

    cout<<"Koko can eats all piles of bananas , if she eat "<<minEatingSpeed(piles,h)<<" banana's per hours"<<endl;
}