#include<iostream>
#include<vector>
using namespace std;


// You are given a 0-indexed integer array arr, and an m x n integer matrix mat. arr and mat both contain all the integers in the range [1, m * n].

// Go through each index i in arr starting from index 0 and paint the cell in mat containing the integer arr[i].

// Return the smallest index i at which either a row or a column will be completely painted in mat.

// Example 1:

// image explanation for example 1
// Input: arr = [1,3,4,2], mat = [[1,4],[2,3]]
// Output: 2
// Explanation: The moves are shown in order, and both the first row and second column of the matrix become fully painted at arr[2].
// Example 2:

// image explanation for example 2
// Input: arr = [2,8,7,4,1,3,5,6,9], mat = [[3,2,5],[1,4,6],[8,7,9]]
// Output: 3
// Explanation: The second column becomes fully painted at arr[3].
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int row = mat.size();
        int col = mat[0].size();

        vector<vector<int>> newMat(row*col);


        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                newMat[mat[i][j]-1] = {i,j};
            }
        }

        vector<int> paintRow(row,0);
        vector<int> paintCol(col,0);
        for(int i = 0; i < row*col; i++){
            paintRow[newMat[arr[i]-1][0]]++;
            paintCol[newMat[arr[i]-1][1]]++;

            if(paintRow[newMat[arr[i]-1][0]] == col)
                return i;
            if(paintCol[newMat[arr[i]-1][1]] == row)
                return i;
        }
        return -1;

    }

int main() {

    vector<int> arr = {1,3,4,2}; 
    vector<vector<int>> mat = {{1,4},{2,3}};

    cout<<"Answer is "<<firstCompleteIndex(arr,mat)<<endl;

}