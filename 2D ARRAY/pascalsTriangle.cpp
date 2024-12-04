#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

// Given an integer numRows, return the first numRows of Pascal's triangle.

// In Pascal's triangle, each number is the sum of the two numbers directly above it as shown:


 

// Example 1:

// Input: numRows = 5
// Output: [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]]

// Example 2:

// Input: numRows = 1
// Output: [[1]]


    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>ans;
    
        for(int i=0;i < numRows; i++){
            vector<int>row(i+1,1);
            
            for(int j=1;j<i;j++){
                row[j] = ans[i-1][j] + ans[i-1][j-1];
                }
            ans.push_back(row);
        }
        return ans;
    }
int main() {
    int n=5;
    vector<vector<int>> arr = generate(n);


    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<arr[i][j];
        }
        cout<<endl;
    }

    // it prints [[1],[1,1],[1,2,1],[1,3,3,1],[1,4,6,4,1]] for n=5

}
