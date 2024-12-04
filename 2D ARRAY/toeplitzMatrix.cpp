#include<iostream>
#include<vector>
using namespace std;
// Given an m x n matrix, return true if the matrix is Toeplitz. Otherwise, return false.

// A matrix is Toeplitz if every diagonal from top-left to bottom-right has the same elements.

 

// Example 1:


// Input: matrix = [[1,2,3,4],[5,1,2,3],[9,5,1,2]]
// Output: true
// Explanation:
// In the above grid, the diagonals are:
// "[9]", "[5, 5]", "[1, 1, 1]", "[2, 2, 2]", "[3, 3]", "[4]".
// In each diagonal all elements are the same, so the answer is True.
// Example 2:


// Input: matrix = [[1,2],[2,2]]
// Output: false
// Explanation:
// The diagonal "[1, 2]" has different elements.

    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();

        for(int i=0; i<row-1; i++) {
            for(int j=0; j<col-1; j++) {
                if(matrix[i][j] != matrix[i+1][j+1]) {
                    return false;
                }
            }
        }
        return true;
    }
int main() {
    vector<vector<int>> arr = {{1,2,3,4},{5,1,2,3},{9,5,1,2}};

    if(isToeplitzMatrix(arr)) {
        cout<<"Given matrix is Toeplitz"<<endl; 
    }
    else {
        cout<<"Given matrix is Toeplitz"<<endl;
    }
}