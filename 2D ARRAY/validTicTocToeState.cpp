#include<iostream>
#include<vector>
#include<string.h>
using namespace std;



// Given a Tic-Tac-Toe board as a string array board, return true if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.

// The board is a 3 x 3 array that consists of characters ' ', 'X', and 'O'. The ' ' character represents an empty square.

// Here are the rules of Tic-Tac-Toe:

// Players take turns placing characters into empty squares ' '.
// The first player always places 'X' characters, while the second player always places 'O' characters.
// 'X' and 'O' characters are always placed into empty squares, never filled ones.
// The game ends when there are three of the same (non-empty) character filling any row, column, or diagonal.
// The game also ends if all squares are non-empty.
// No more moves can be played if the game is over.
 

// Example 1:


// Input: board = ["O  ","   ","   "]
// Output: false
// Explanation: The first player always plays "X".
// Example 2:


// Input: board = ["XOX"," X ","   "]
// Output: false
// Explanation: Players take turns making moves.
// Example 3:


// Input: board = ["XOX","O O","XOX"]
// Output: true


    bool check_x_win(vector<string>& grid) {
        bool res = false;
        res |= grid[0][0] == 'X' && grid[0][1] == 'X' && grid[0][2] == 'X';
        res |= grid[1][0] == 'X' && grid[1][1] == 'X' && grid[1][2] == 'X';
        res |= grid[2][0] == 'X' && grid[2][1] == 'X' && grid[2][2] == 'X';
        
        res |= grid[0][0] == 'X' && grid[1][0] == 'X' && grid[2][0] == 'X';
        res |= grid[0][1] == 'X' && grid[1][1] == 'X' && grid[2][1] == 'X';
        res |= grid[0][2] == 'X' && grid[1][2] == 'X' && grid[2][2] == 'X';
        
        res |= grid[0][0] == 'X' && grid[1][1] == 'X' && grid[2][2] == 'X';
        res |= grid[0][2] == 'X' && grid[1][1] == 'X' && grid[2][0] == 'X';
        
        return res;
    }
    
    bool check_o_win(vector<string>& grid) {
        bool res = false;
        res |= grid[0][0] == 'O' && grid[0][1] == 'O' && grid[0][2] == 'O';
        res |= grid[1][0] == 'O' && grid[1][1] == 'O' && grid[1][2] == 'O';
        res |= grid[2][0] == 'O' && grid[2][1] == 'O' && grid[2][2] == 'O';
        
        res |= grid[0][0] == 'O' && grid[1][0] == 'O' && grid[2][0] == 'O';
        res |= grid[0][1] == 'O' && grid[1][1] == 'O' && grid[2][1] == 'O';
        res |= grid[0][2] == 'O' && grid[1][2] == 'O' && grid[2][2] == 'O';
        
        res |= grid[0][0] == 'O' && grid[1][1] == 'O' && grid[2][2] == 'O';
        res |= grid[0][2] == 'O' && grid[1][1] == 'O' && grid[2][0] == 'O';
        
        return res;
    }

    void countData(string row, int& xCount, int& oCount) {
        for(auto val: row) {
            if(val == 'X') {
                xCount++;
            }
            if(val == 'O') {
                oCount++;
            }
        }
    }
    bool validTicTacToe(vector<string>& board) {
        
        string row1 = board[0];
        string row2 = board[1];
        string row3 = board[2];

        int xCount = 0;
        int oCount = 0;
        countData(row1,xCount,oCount);
        countData(row2,xCount,oCount);
        countData(row3,xCount,oCount);

        if(oCount > xCount || xCount - oCount >= 2) return false;
        if(xCount >= 3 && xCount == oCount && check_x_win(board)) return false;
        if(oCount >= 3 && xCount > oCount && check_o_win(board)) return false;

        return true;
    } 


int main() {

    vector<string> board = {"XOX","O O","XOX"};

    if(validTicTacToe(board)) {
        cout<<"We can win"<<endl;
    }
    else {
        cout<<"We can't win"<<endl;

    }

}