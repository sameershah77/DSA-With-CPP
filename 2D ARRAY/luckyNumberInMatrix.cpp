#include<iostream>
#include<vector>
#include<map>
#include<climits>
using namespace std;

// Given an m x n matrix of distinct numbers, return all lucky numbers in the matrix in any order.

// A lucky number is an element of the matrix such that it is the minimum element in its row and maximum in its column.

 

// Example 1:

// Input: matrix = [[3,7,8],[9,11,13],[15,16,17]]
// Output: [15]
// Explanation: 15 is the only lucky number since it is the minimum in its row and the maximum in its column.
// Example 2:

// Input: matrix = [[1,10,4,2],[9,3,8,7],[15,16,17,12]]
// Output: [12]
// Explanation: 12 is the only lucky number since it is the minimum in its row and the maximum in its column.
// Example 3:

// Input: matrix = [[7,8],[1,2]]
// Output: [7]
// Explanation: 7 is the only lucky number since it is the minimum in its row and the maximum in its column.

    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> ans;

        map<pair<int,int>,bool> mp;
        int row = matrix.size();1
        int col = matrix[0].size();
        for(int i=0; i<row; i++) {
            int mini = INT_MAX;
            int I = 0;
            int J = 0;
            for(int j=0; j<col; j++) {
                if(matrix[i][j] < mini) {
                    mini = matrix[i][j];
                    I = i;
                    J = j;
                }
            }
            mp[{I,J}] = true;
        }

        for(int i=0; i<col; i++) {
            int maxi = INT_MIN;
                int I = 0;
                int J = 0;
            
            for(int j=0; j<row; j++) {
                if(matrix[j][i] > maxi) {
                    maxi = matrix[j][i];
                    I = j;
                    J = i;
                }
            }

            if(mp[{I,J}] == true) {
                ans.push_back(matrix[I][J]);
            }
        }
        return ans;
    }

    int main() {
        vector<vector<int>> matrix = {{3,7,8},{9,11,13},{15,16,17}};

        vector<int> ans = luckyNumbers(matrix);

        cout<<"Answer is "<<endl;


        for(auto val: ans) {
            cout<<val<<" ";
        }
        cout<<endl;

    }