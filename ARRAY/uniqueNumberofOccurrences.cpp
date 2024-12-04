#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Given an array of integers arr, return true if the number of occurrences of each value in the array is unique or false otherwise.

 

// Example 1:

// Input: arr = [1,2,2,1,1,3]
// Output: true
// Explanation: The value 1 has 3 occurrences, 2 has 2 and 3 has 1. No two values have the same number of occurrences.
// Example 2:

// Input: arr = [1,2]
// Output: false
// Example 3:

// Input: arr = [-3,0,1,-3,1,1,1,-3,10,0]
// Output: true

    bool uniqueOccurrences(vector<int>& arr) {

        vector<int> freq(2001,0);
        
        for(auto val: arr) {
            freq[1000+val]++;
        }        
        arr.clear();

        for(auto val: freq) {
            if(val != 0) {
                arr.push_back(val);
            }
        }

        sort(arr.begin(),arr.end());
        
        for(int i=1; i<arr.size(); i++) {
            if(arr[i] == arr[i-1]) {
                return false;
            }
        }
        return true;
    }

int main() {

    vector<int> arr = {1,2,2,1,1,3};

    if(uniqueOccurrences(arr)) {
        cout<<"Occurance is unique "<<endl;
    }
    else {
        cout<<"Occurance is not unique "<<endl;
    }

}