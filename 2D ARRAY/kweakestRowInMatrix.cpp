#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;


// You are given an m x n binary matrix mat of 1's (representing soldiers) and 0's (representing civilians). The soldiers are positioned in front of the civilians. That is, all the 1's will appear to the left of all the 0's in each row.

// A row i is weaker than a row j if one of the following is true:

// The number of soldiers in row i is less than the number of soldiers in row j.
// Both rows have the same number of soldiers and i < j.
// Return the indices of the k weakest rows in the matrix ordered from weakest to strongest.

 

// Example 1:

// Input: mat = 
// [[1,1,0,0,0],
//  [1,1,1,1,0],
//  [1,0,0,0,0],
//  [1,1,0,0,0],
//  [1,1,1,1,1]], 
// k = 3
// Output: [2,0,3]
// Explanation: 
// The number of soldiers in each row is: 
// - Row 0: 2 
// - Row 1: 4 
// - Row 2: 1 
// - Row 3: 2 
// - Row 4: 5 
// The rows ordered from weakest to strongest are [2,0,3,1,4].
// Example 2:

// Input: mat = 
// [[1,0,0,0],
//  [1,1,1,1],
//  [1,0,0,0],
//  [1,0,0,0]], 
// k = 2
// Output: [0,2]
// Explanation: 
// The number of soldiers in each row is: 
// - Row 0: 1 
// - Row 1: 4 
// - Row 2: 1 
// - Row 3: 1 
// The rows ordered from weakest to strongest are [0,2,3,1].
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int row = mat.size();
        int col = mat[0].size();
        vector<int> arr(row,-1);
        for(int i=0; i<row; i++) {
                int count = 0;
            for(int j=0; j<col; j++) {
                if(mat[i][j] == 1) {
                    count++;
                }
            }
            arr[i] =  count;
        }
        vector<int> ans;
        while(k > 0) {
            int min = INT_MAX;
            int index = 0;
            for(int i=0; i<arr.size(); i++) {
                if(arr[i] < min) {
                    min = arr[i];
                    index = i;
                }
            }
            ans.push_back(index);
            arr[index] = INT_MAX;
            k--;
        }
        return ans;
    }
int main() {
    vector<vector<int>> arr = {{1,1,0,0,0},
                               {1,1,1,1,0},
                               {1,0,0,0,0},
                               {1,1,0,0,0},
                               {1,1,1,1,1}};
    
    int k = 3;
    cout<<"Original matrix is "<<endl;
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr[0].size(); j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    vector<int> ans = kWeakestRows(arr,k);


    cout<<"The weakest rows are "<<endl;

    for(auto val:ans) {
        cout<<val<<" ";
    }
    cout<<endl;
}