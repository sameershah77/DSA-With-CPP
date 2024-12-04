#include<iostream>
#include<limits.h>
#include<vector>
using namespace std;

// Given a square matrix mat, return the sum of the matrix diagonals.

// Only include the sum of all the elements on the primary diagonal and all the elements on the secondary diagonal that are not part of the primary diagonal.

 

// Example 1:


// Input: mat = [[1,2,3],
//               [4,5,6],
//               [7,8,9]]
// Output: 25
// Explanation: Diagonals sum: 1 + 5 + 9 + 3 + 7 = 25
// Notice that element mat[1][1] = 5 is counted only once.
// Example 2:

// Input: mat = [[1,1,1,1],
//               [1,1,1,1],
//               [1,1,1,1],
//               [1,1,1,1]]
// Output: 8
// Example 3:

// Input: mat = [[5]]
// Output: 5
    int diagonalSum(vector<vector<int>>& mat) {
        int sum = 0;
        int i = 0;
        int j = 0;

        int n = mat.size();
        
        while(i < n && j < n){
            sum+= mat[i][j];
            i++;
            j++;
        }
        i = 0;
        j = n-1;
        while(i < n && j >= 0){
            if(n%2 == 0){
                //even size
                sum+= mat[i][j];

            }
            else {
                //odd size ->discard center of matrix
                if(i != n/2) {
                    sum+= mat[i][j];
                }

            }
            i++;
            j--;
            
        }
        return sum;
    }
int main() {
    vector<vector<int>> arr = {{4,5,6},
                               {1,3,8},
                               {3,2,9}};
    
    cout<<"Original matrix is "<<endl;
    for(int i=0; i<arr.size(); i++) {
        for(int j=0; j<arr[0].size(); j++) {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl;

    int sum = diagonalSum(arr);
    
    cout<<"Sum of the matrix is "<<sum<<endl;

    cout<<endl;
}