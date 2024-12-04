#include<iostream>
#include<vector>
using namespace std;


    bool isSafe(vector<vector<int>> &arr,int row,int col,int i,int j){
        if( ((i>=0 && i<row) && (j>=0 && j<col)) && (arr[i][j]==false) ) 
            return true;        
        else 
            return false;
    }
    void totalWays(vector<vector<int>> &arr,int row,int col,int i,int j,int& count) {
        if(i==row-1 && j==col-1) {
            count++;
            return;
        }
        // Right direction
        if(isSafe(arr,row,col,i,j+1)) {
            arr[i][j+1]=true;
            totalWays(arr,row,col,i,j+1,count);
            arr[i][j+1]=false;
        }
        //Down direction
        if(isSafe(arr,row,col,i+1,j)) {
            arr[i+1][j]=true;
            totalWays(arr,row,col,i+1,j,count);
            arr[i+1][j]=false;
        }
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>> arr (m,vector<int>(n,false));
        int count = 0;
        int row = m;
        int col = n;
        // i & j will be the source position of robot
        int i=0;
        int j=0;
        totalWays(arr,row,col,i,j,count);
        return count;      
    }
int main () {
    int m;
    cout<<"Enter number of row : ";
    cin>>m;
    int n;
    cout<<"Enter number of coloumn : ";
    cin>>n;

    int paths = uniquePaths(m,n);

    cout<<"The number of paths are "<<paths<<endl;


}