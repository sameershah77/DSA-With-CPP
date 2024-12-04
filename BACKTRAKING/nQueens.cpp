#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
// T.C O(N^N)   S.C O(N*N)

// this is optimal function using map , it takes O(1) time and space 
unordered_map<int,bool> rowCheck;
unordered_map<int,bool> upperLeftDiagonalCheck;
unordered_map<int,bool> bottomLeftDiagonalCheck;


// bool isSafe(int row ,int col,vector<vector<char>> &board,int n) {

//     if(rowCheck[row]==true) {
//         return false;
//     }
//     if(upperLeftDiagonalCheck[n-1+col-row]==true) {
//         return false;
//     }
//     if(bottomLeftDiagonalCheck[row+col]==true) {
//         return false;
//     }

//     return true;
//  }

void printSolution(vector<vector<char>> &board,int n,int count) {
    cout<<endl<<endl<<"Solution no. "<<count<<endl;
    cout<<"________________"<<endl;
 

        for(int i=0;i<n;i++) {
            
            
            for(int j=0;j<n;j++) {
                cout<<board[i][j]<<"  ";
            }
            cout<<endl;
        }

        cout<<"________________"<<endl;
}


bool isSafe(int row ,int col,vector<vector<char>> &board,int n) {
    int i=row;
    int j=col;

    while(j>=0) {
        if(board[i][j]=='Q') {
            return false;
        }
        j--;
    }
    i=row;
    j=col;
    while(i>=0 && j>=0) {
        if(board[i][j]=='Q') {
            return false;
        }
        i--;
        j--;
    }
    i=row;
    j=col;
    while(i<n && j>=0) {
        if(board[i][j]=='Q') {
            return false;
        }
        i++;
        j--;
    }
    return true;
}


void solve(vector<vector<char>> &board,int col,int n,int &count) {

    //base case
    if(col>=n) {
        count++;
        printSolution(board,n,count);
        
        return;
    }

    for(int row=0; row <n;row++) {
        if(isSafe(row,col,board,n)) {
            board[row][col]='Q';

            rowCheck[row]=true;
            upperLeftDiagonalCheck[n-1+col-row]=true;
            bottomLeftDiagonalCheck[row+col]=true;

            solve(board,col+1,n,count);
            board[row][col]='-';

            rowCheck[row]=false;
            upperLeftDiagonalCheck[n-1+col-row]=false;
            bottomLeftDiagonalCheck[row+col]=false;

        }
    }
}

int main() {

    int n;
    cout<<"Enter the value of N :- ";
    cin>>n;
    int count =0;
    vector<vector<char>> board (n,vector<char>(n,'-'));

    int col=0;
    solve(board,col,n,count);

    cout<<"Total numbers of solutions are "<<count<<endl;
    
    
}


