#include<iostream>
#include<vector>
using namespace std;


// Given an integer array sorted in non-decreasing order, there is exactly one integer in the array that occurs more than 25% of the time, return that integer.

 

// Example 1:

// Input: arr = [1,2,2,6,6,6,6,7,10]
// Output: 6
// Example 2:

// Input: arr = [1,1]
// Output: 1
 
    int findSpecialInteger(vector<int>& arr) {
        int count = 1;
        if(arr.size() == 1) {
            return arr[0];
        }

        int prev = arr[0];
        
        for(int i=1; i<arr.size(); i++) {
            int curr = arr[i];
            if(prev == curr) {
                count++;
                cout<<count<<endl;
                if(((double)count/arr.size())*100 > 25) {
                    return curr;
                } 
            }
            else {
                count = 1;
                prev = curr;
            }
        }
        return 0;
    }
int main() {
    vector<int> arr = {1,2,2,6,6,6,6,7,10};

    cout<<"Answer is "<<findSpecialInteger(arr)<<endl;

}