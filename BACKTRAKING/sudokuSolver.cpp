#include<iostream>
#include<vector>
using namespace std;


// T.C O(9^m*n)   S.C O(m*n)

// Write a program to solve a Sudoku puzzle by filling the empty cells.

// A sudoku solution must satisfy all of the following rules:

// Each of the digits 1-9 must occur exactly once in each row.
// Each of the digits 1-9 must occur exactly once in each column.
// Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
// The '.' character indicates empty cells.


// Input: board = [["5","3",".",".","7",".",".",".","."],
//                 ["6",".",".","1","9","5",".",".","."],
//                 [".","9","8",".",".",".",".","6","."],
//                 ["8",".",".",".","6",".",".",".","3"],
//                 ["4",".",".","8",".","3",".",".","1"],
//                 ["7",".",".",".","2",".",".",".","6"],
//                 [".","6",".",".",".",".","2","8","."],
//                 [".",".",".","4","1","9",".",".","5"],
//                 [".",".",".",".","8",".",".","7","9"]]



//        Output: [["5","3","4","6","7","8","9","1","2"],
//                 ["6","7","2","1","9","5","3","4","8"],
//                 ["1","9","8","3","4","2","5","6","7"],
//                 ["8","5","9","7","6","1","4","2","3"],
//                 ["4","2","6","8","5","3","7","9","1"],
//                 ["7","1","3","9","2","4","8","5","6"],
//                 ["9","6","1","5","3","7","2","8","4"],
//                 ["2","8","7","4","1","9","6","3","5"],
//                 ["3","4","5","2","8","6","1","7","9"]]
// Explanation: The input board is shown above and the only valid solution is shown below:


    bool isSafe(int row, int col, vector<vector<int>>& board, int value) {
        int n = board.size();

        for(int i=0; i<n; i++) {
            //row check
            if(board[row][i] == value)
                return false;
            
            //col check
            if(board[i][col] == value) 
                return false;

            //3*3 box check

            ///// Very Very important formula for sudoku solver ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
            if(board[3*(row/3)+(i/3)][3*(col/3)+(i%3)] == value) 
                return false;
        }

        return true;
    }

    bool solve(vector<vector<int>>& board) {
        int n = board.size();

        for(int i=0; i<n; i++) {
            for(int j=0; j<n; j++) {
                //check for empty cell
                if(board[i][j] == 0) {
                    //try to fill with values ranging from 1 to 9
                    for(int val = 1; val<=9; val++) {
                        //check for safety
                        if(isSafe(i,j, board, val)) {
                            //insert
                            board[i][j] = val;
                            //recursion sambal lega
                            bool remainingBoardSolution = solve(board);
                            if(remainingBoardSolution == true) {
                                return true;
                            }
                            else {
                                //backtrack
                                board[i][j] = 0;
                            }
                        }
                    }
                    //if 1 se 9 tak koi bhi value se solution
                    //nahi nikla ,current cell pr, 
                    //that means piche kahin pr galti h , 
                    //go back by returning false
                return false;
                }
            }
        }
        //all cells filled 
        return true;
    }
    void solveSudoku(vector<vector<int>>& board) {
        solve(board);
    }

int main() {

    // "0" -> represents empty cell
    vector<vector<int>> arr =  {{4,5,0,0,0,0,0,0,0},
                                {0,0,2,0,7,0,6,3,0},
                                {0,0,0,0,0,0,0,2,8},
                                {0,0,0,9,5,0,0,0,0},
                                {0,8,6,0,0,0,2,0,0},
                                {0,2,0,6,0,0,7,5,0},
                                {0,0,0,0,0,0,4,7,6},
                                {0,7,0,0,4,5,0,0,0},
                                {0,0,8,0,0,9,0,0,0}};

                    solveSudoku(arr);


                    cout<<endl<<endl;
                    cout<<"Solution for Sudoku is "<<endl;

                     for(int i=0;i<9;i++) {
                        for(int j=0;j<9;j++) {
                            if(arr[i][j] != 0) {
                                cout<<arr[i][j]<<" ";
                            }
                            else {
                                cout<<"No solution exists for given clues in sudoku ";
                                break;
                            }
                        }
                        
                        cout<<endl;
                    }                  

    
}