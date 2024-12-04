#include<iostream>
#include<vector>
using namespace std;
// Write an efficient algorithm that searches for a value target in an m x n integer matrix matrix. This matrix has the following properties:

// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.


// Example 1:


// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 5
// Output: true
// Example 2:

// Input: matrix = [[1,4,7,11,15],[2,5,8,12,19],[3,6,9,16,22],[10,13,14,17,24],[18,21,23,26,30]], target = 20
// Output: false


    bool searchMatrix(vector<vector<int>>& matrix, int target) {
                
        int row = matrix.size();
        int col = matrix[0].size();

        int start = 0;
        int end = col-1;
        
        while(start < row && end >=0) {
            int element = matrix[start][end];
            
            if(element == target) {
                return true;
            }
            if(element > target) {
                end--;
            }
            else {
                start++;
            }
        }
        return false;       
    }
int main() {

      vector<vector<int>> matrix = {{1,4,7,11,15},
                                    {2,5,8,12,19},
                                    {3,6,9,16,22},
                                    {10,13,14,17,24},
                                    {18,21,23,26,30}}; 
    int target = 5;

    if(searchMatrix(matrix,target)) {
        cout<<"Element Found"<<endl;
    }
    else {
        cout<<"Element Not Found"<<endl;
    }
}