#include<iostream>
#include<vector>
using namespace std;

// Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.

// As the answer can be very large, return it modulo 109 + 7.

 

// Example 1:

// Input: arr = [1,1,2,2,3,3,4,4,5,5], target = 8
// Output: 20
// Explanation: 
// Enumerating by the values (arr[i], arr[j], arr[k]):
// (1, 2, 5) occurs 8 times;
// (1, 3, 4) occurs 8 times;
// (2, 2, 4) occurs 2 times;
// (2, 3, 3) occurs 2 times.
// Example 2:

// Input: arr = [1,1,2,2,2,2], target = 5
// Output: 12
// Explanation: 
// arr[i] = 1, arr[j] = arr[k] = 2 occurs 12 times:
// We choose one 1 from [1,1] in 2 ways,
// and two 2s from [2,2,2,2] in 6 ways.
// Example 3:

// Input: arr = [2,1,3], target = 6
// Output: 1
// Explanation: (1, 2, 3) occured one time in the array so we return 1.

    int threeSumMulti(vector<int>& A, int target) {
        int n = A.size();
        sort(A.begin(), A.end());

        int ans = 0; 
        int mod = 1e9+7;

        for (int i=0; i<n-2; ++i) {
            int lo = i+1, hi = n-1;

            while (lo < hi) {

                if (A[i] + A[lo] + A[hi] == target) {

                    int cntlo=1, cnthi=1;

                    while (lo < hi && A[lo] == A[lo+1]) {
                        cntlo++; 
                        lo++;
                    }
                    while (lo < hi && A[hi] == A[hi-1]) {
                        cnthi++;
                        hi--;
                    }
					// A[lo]==A[hi]
                    if (lo == hi) {
                        ans =(ans+cntlo*(cntlo-1)/2)%mod;
                    }
                    else { // A[lo]!=A[hi]
                        ans = (ans+cntlo*cnthi)%mod;
                    }

                    lo++; hi--; 

                } else if (A[i] + A[lo] + A[hi] > target) {
                    hi--;
                } else {
                    lo++;
                }
            }
            
        }
        return ans;
    }

int main() {

    vector<int> arr = {1,1,2,2,3,3,4,4,5,5};
    int target = 8;

    cout<<"Answer is "<<endl;
    vector<vector<int>> ans = threeSumMulti(arr,target);

    for(auto val: ans) {
        for(auto i: val) {
            cout<<i<<" ";
        }
        cout<<endl;
    }

    cout<<endl;


}