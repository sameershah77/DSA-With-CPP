#include<iostream>
#include<vector>
using namespace std;

// Given two n x n binary matrices mat and target, return true if it is possible to make mat equal to target by rotating mat in 90-degree increments, or false otherwise.

 

// Example 1:


// Input: mat = [[0,1],[1,0]], target = [[1,0],[0,1]]
// Output: true
// Explanation: We can rotate mat 90 degrees clockwise to make mat equal target.
// Example 2:


// Input: mat = [[0,1],[1,1]], target = [[1,0],[0,1]]
// Output: false
// Explanation: It is impossible to make mat equal to target by rotating mat.
// Example 3:


// Input: mat = [[0,0,0],[0,1,0],[1,1,1]], target = [[1,1,1],[0,1,0],[0,0,0]]
// Output: true
// Explanation: We can rotate mat 90 degrees clockwise two times to make mat equal target.
void rotate(vector<vector<int>> &arr,int row,int col){

    int size = arr[0].size();
        int i=0;
        int j=size-1;

        for(int i=0;i<row;i++) {
            for(int j=i;j<col;j++) {
                int temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
        }
        for(int i=0; i<size; i++) {
            for(int j=0; j<size/2; j++) {
                 int temp = arr[i][size-1-j];
                arr[i][size-1-j] = arr[i][j];
                arr[i][j] =temp;
            
            }
        }
}
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        if(mat == target) {
            return true;
        }
        int degree = 3;
        while(degree != 0) {
            rotate(mat,mat.size(),mat[0].size());
            if(mat == target) {
                return true;
            }
            degree--;
        }
        return false;
    }
int main() {
    vector<vector<int>> mat {{0,1},{1,0}};
    vector<vector<int>> target {{1,0},{0,1}};

    findRotation(mat,target)?cout<<"Yes !! We can "<<endl:cout<<"No !! We can't "<<endl;

}