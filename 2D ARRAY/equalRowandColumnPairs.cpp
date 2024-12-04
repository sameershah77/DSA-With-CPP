#include<iostream>
using namespace std;

// Given a 0-indexed n x n integer matrix grid, return the number of pairs (ri, cj) such that row ri and column cj are equal.

// A row and column pair is considered equal if they contain the same elements in the same order (i.e., an equal array).

 

// Example 1:


// Input: grid = [[3,2,1],[1,7,6],[2,7,7]]
// Output: 1
// Explanation: There is 1 equal row and column pair:
// - (Row 2, Column 1): [2,7,7]
// Example 2:


// Input: grid = [[3,1,2,2],[1,4,4,5],[2,4,2,2],[2,4,2,2]]
// Output: 3
// Explanation: There are 3 equal row and column pairs:
// - (Row 0, Column 0): [3,1,2,2]
// - (Row 2, Column 2): [2,4,2,2]
// - (Row 3, Column 2): [2,4,2,2]


    void rotate(vector<vector<int>> &matrix, int n) {
        int row = n;
        int col = n;

        for (int i=0; i<row; i++ ) {
            for(int j=0; j<=i; j++) {
                int temp = 0;
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }

        for(int i=0; i<n; i++) {
            for(int j=0; j<n/2; j++ ) {
                int temp = 0;
                temp=matrix[i][j];
                matrix[i][j]=matrix[i][n-1-j];
                matrix[i][n-1-j]=temp;
            }
        } 
    }
    int equalPairs(vector<vector<int>>& grid) {

        int count = 0;
        int n = grid.size();

        vector<vector<int>> matrix = grid;
        rotate(matrix,n);
        for(int i=0; i<n; i++) {
            reverse(matrix[i].begin(),matrix[i].end());
        }
        for(auto row1: grid) {
            for(auto row2 : matrix) {
                if(row1 == row2) count++;
            }
            cout<<endl;
        }
        return count;
    }

int main() {

    vector<vcetor<int>> grid = {{3,2,1},{1,7,6},{2,7,7}};

    cout<<"answer is "<<equalPairs(grid)<<endl;

}