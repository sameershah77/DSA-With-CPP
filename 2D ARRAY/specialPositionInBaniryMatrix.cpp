#include<iostream>
#include<vector>
using namespace std;

// Given an m x n binary matrix mat, return the number of special positions in mat.

// A position (i, j) is called special if mat[i][j] == 1 and all other elements in row i and column j are 0 (rows and columns are 0-indexed).

 

// Example 1:


// Input: mat = [[1,0,0],[0,0,1],[1,0,0]]
// Output: 1
// Explanation: (1, 2) is a special position because mat[1][2] == 1 and all other elements in row 1 and column 2 are 0.
// Example 2:


// Input: mat = [[1,0,0],[0,1,0],[0,0,1]]
// Output: 3
// Explanation: (0, 0), (1, 1) and (2, 2) are special positions.

    int numSpecial(vector<vector<int>>& mat) {
        vector<int> rows(mat.size());
        vector<int> cols(mat[0].size());

        for (int i = 0; i < rows.size(); ++i) {
            for (int j = 0; j < cols.size(); ++j) {
                if (mat[i][j] == 1)
                    ++rows[i], ++cols[j];
            }        
        }

        int count = 0;
        for (int i = 0; i < rows.size(); ++i) {
            for (int j = 0; j < cols.size(); ++j) {
                if (mat[i][j] == 1 && rows[i] == 1 && cols[j] == 1)
                    count++;            
            }
            
        }

        return count;
    }
int main() {
    vector<vector<int>> arr = {{1,0,0},{0,1,0},{0,0,1}};
    int ans = numSpecial(arr);
    cout<<"Special position in binary matrix is "<<ans<<endl;
}