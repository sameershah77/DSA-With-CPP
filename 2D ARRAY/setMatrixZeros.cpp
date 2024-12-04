#include<iostream>
#include<vector>
using namespace std;

// Given an m x n integer matrix matrix, if an element is 0, set its entire row and column to 0's.

// Example 1:

// Input: matrix = [[1,1,1],[1,0,1],[1,1,1]]
// Output: [[1,0,1],[0,0,0],[1,0,1]]


// Example 2:

// Input: matrix = [[0,1,2,0],[3,4,5,2],[1,3,1,5]]
// Output: [[0,0,0,0],[0,4,5,0],[0,3,1,0]]



    void setZeroes(vector<vector<int>>& matrix) {
        int row=matrix.size();
        int col=matrix[0].size();

        vector<int> rowArray(row,0);
        vector<int> colArray(col,0);

        for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(matrix[i][j]==0) {
                    rowArray[i]=1;
                    colArray[j]=1;
                }
            }
        }

          for(int i=0;i<row;i++) {
            for(int j=0;j<col;j++) {
                if(rowArray[i]==1 ||colArray[j]==1) {
                    matrix[i][j]=0;                
                }
            }
        }




    }

int main () {
    vector<vector<int>> matrix = {{1,1,1},{1,1,1},{1,0,1}};
        int row=matrix.size();
        int col=matrix[0].size();

        cout<<"Your original Matrix is looks like :- "<<endl;

    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }


    setZeroes(matrix);


    cout<<"Your new Matrix is looks like :- "<<endl;

    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }



}