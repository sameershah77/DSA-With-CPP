#include<iostream>
#include<vector>
using namespace std;

// You are given an m x n integer matrix matrix with the following two properties:

// Each row is sorted in non-decreasing order.
// The first integer of each row is greater than the last integer of the previous row.
// Given an integer target, return true if target is in matrix or false otherwise.

// You must write a solution in O(log(m * n)) time complexity.

 

// Example 1:


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
// Output: true
// Example 2:


// Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
// Output: false
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int row = matrix.size();
        int col = matrix[0].size();

        int totalElement = row*col;

        int start = 0;
        int end = totalElement-1;

        int mid = start + (end-start)/2;

        while(start <= end) {
            int rowIndex = mid/col;
            int colIndex = mid%col;

            if(target == matrix[rowIndex][colIndex]) {
                return true;
            }
            if(target > matrix[rowIndex][colIndex]) {
                start = mid+1;
            }
            else {
                end = mid-1;
            }
            mid = start + (end-start)/2;
        }       
        return false;
    }
int main() {

    vector<vector<int>> matrix = {{1,3,5,7},
                                {10,11,16,20},
                                {23,30,34,60}}; 
    int target = 3;

    if(searchMatrix(matrix,target)) {
        cout<<"Element Found"<<endl;
    }
    else {
        cout<<"Element Not Found"<<endl;
    }
}