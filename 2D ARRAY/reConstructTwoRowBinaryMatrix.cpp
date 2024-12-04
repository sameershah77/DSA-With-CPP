#include<iostream>
#include<vector>
using namespace std;

// Given the following details of a matrix with n columns and 2 rows :

// The matrix is a binary matrix, which means each element in the matrix can be 0 or 1.
// The sum of elements of the 0-th(upper) row is given as upper.
// The sum of elements of the 1-st(lower) row is given as lower.
// The sum of elements in the i-th column(0-indexed) is colsum[i], where colsum is given as an integer array with length n.
// Your task is to reconstruct the matrix with upper, lower and colsum.

// Return it as a 2-D integer array.

// If there are more than one valid solution, any of them will be accepted.

// If no valid solution exists, return an empty 2-D array.

 

// Example 1:

// Input: upper = 2, lower = 1, colsum = [1,1,1]
// Output: [[1,1,0],[0,0,1]]
// Explanation: [[1,0,1],[0,1,0]], and [[0,1,1],[1,0,0]] are also correct answers.
// Example 2:

// Input: upper = 2, lower = 3, colsum = [2,2,1,1]
// Output: []
// Example 3:

// Input: upper = 5, lower = 5, colsum = [2,1,2,0,1,0,1,2,0,1]
// Output: [[1,1,1,0,1,0,0,1,0,0],[1,0,1,0,0,0,1,1,0,1]]









    // T.C = O(N)
    vector<vector<int>> reconstructMatrix(int upper, int lower, vector<int>& colsum) {
        int row = 2;
        int col = colsum.size();
        
        int sum = 0;
        int nonZero = 0;

        for(auto val:colsum) {
            sum += val;
            if(val != 0) {
                nonZero++;
            }
        }

        if((lower + upper) != sum || upper > nonZero || lower > nonZero) {
            vector<vector<int>> arr;
            return arr;
        }

        vector<vector<int>> ans(row,vector<int>(col,0));

        for(int i=0; i<col; i++) {
            if(colsum[i] == 2) {
                ans[0][i] = 1;
                colsum[i]--;
                upper--;
            }
        }


        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++) {
                if(ans[i][j] == 0 && colsum[j] > 0) {
                    if(i==0 && upper > 0) {
                        ans[i][j] = 1;
                        upper--;
                        colsum[j]--;
                    }
                    if(i==1 && lower > 0) {
                        ans[i][j] = 1;
                        lower--;
                        colsum[j]--;
                    }
                }
            }
        }
        return ans;

    }

    int main() {
        int upper = 5; 
        int lower = 5;
        vector<int> colsum = {2,1,2,0,1,0,1,2,0,1};

        vector<vector<int>> ans = reconstructMatrix(upper,lower,colsum);

        cout<<"Answer is "<<endl;
        for(auto val: ans) {
            for(auto i: val) {
                cout<<i<<" ";
            }
            cout<<endl;
        }
    }