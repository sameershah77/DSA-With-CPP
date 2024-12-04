#include<iostream>
#include<vector>
using namespace std;

// On an 8 x 8 chessboard, there is exactly one white rook 'R' and some number of white bishops 'B', black pawns 'p', and empty squares '.'.

// When the rook moves, it chooses one of four cardinal directions (north, east, south, or west), then moves in that direction until it chooses to stop, reaches the edge of the board, captures a black pawn, or is blocked by a white bishop. A rook is considered attacking a pawn if the rook can capture the pawn on the rook's turn. The number of available captures for the white rook is the number of pawns that the rook is attacking.

// Return the number of available captures for the white rook.

 

// Example 1:


// Input: board = [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","R",".",".",".","p"],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
// Output: 3
// Explanation: In this example, the rook is attacking all the pawns.
// Example 2:


// Input: board = [[".",".",".",".",".",".",".","."],[".","p","p","p","p","p",".","."],[".","p","p","B","p","p",".","."],[".","p","B","R","B","p",".","."],[".","p","p","B","p","p",".","."],[".","p","p","p","p","p",".","."],[".",".",".",".",".",".",".","."],[".",".",".",".",".",".",".","."]]
// Output: 0
// Explanation: The bishops are blocking the rook from attacking any of the pawns.
// Example 3:


// Input: board = [[".",".",".",".",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".","p",".",".",".","."],["p","p",".","R",".","p","B","."],[".",".",".",".",".",".",".","."],[".",".",".","B",".",".",".","."],[".",".",".","p",".",".",".","."],[".",".",".",".",".",".",".","."]]
// Output: 3
// Explanation: The rook is attacking the pawns at positions b5, d6, and f5.
 

// Constraints:

// board.length == 8
// board[i].length == 8
// board[i][j] is either 'R', '.', 'B', or 'p'
// There is exactly one cell with board[i][j] == 'R'


    int numRookCaptures(vector<vector<string>>& board) {

        int rookPosX = 0;
        int rookPosY = 0;

        for(int i=0; i<8; i++) {
            for(int j=0; j<8; j++) {
                if(board[i][j] == "R") {
                    rookPosX = i;
                    rookPosY = j;
                    break;
                }
            }
        }

        int count = 0;
        int i = rookPosX;
        int j = rookPosY;
        //go north
        while(i >= 0) {
            if(board[i][j] == "B") break;
            if(board[i][j] == "p") {
                count++;
                break;
            }
            i--;
        }    

        //go south
        i = rookPosX;
        j = rookPosY;
        while(i < 8) {
            if(board[i][j] == "B") break;
            if(board[i][j] == "p") {
                count++;
                break;
            }
            i++;
        }

        //go west
        i = rookPosX;
        j = rookPosY;
        while(j >= 0) {
            if(board[i][j] == "B") break;
            if(board[i][j] == "p") {
                count++;
                break;
            }
            j--;
        }
        
        // go east
        i = rookPosX;
        j = rookPosY;
        while(j < 8) {
            if(board[i][j] == "B") break;
            if(board[i][j] == "p") {
                count++;
                break;
            }
            j++;
        }

        return count;
    }
int main() {
    vector<vector<string>> board = {{".",".",".",".",".",".",".","."},
                                    {".",".",".","p",".",".",".","."},
                                    {".",".",".","p",".",".",".","."},
                                    {"p","p",".","R",".","p","B","."},
                                    {".",".",".",".",".",".",".","."},
                                    {".",".",".","B",".",".",".","."},
                                    {".",".",".","p",".",".",".","."},
                                    {".",".",".",".",".",".",".","."}};

    cout<<"Answer is "<<numRookCaptures(board)<<endl;
}