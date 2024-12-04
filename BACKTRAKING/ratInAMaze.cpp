#include<iostream>
#include<vector>
#include<string.h>
using namespace std;

// T.C O(4^m*n)   S.C O(m*n)

bool isSafe(vector<vector<int>> &arr,int row,int col,int i,int j,vector<vector<bool>>&visited){
    if( ((i>=0 && i<row) && (j>=0 && j<col)) && (visited[i][j]==false) && (arr[i][j]==1) ) {
        return true;
    }
    else {
        return false;
    }
}


void ratInMaze(vector<vector<int>> &arr,int row,int col,int i,int j,vector<vector<bool>>&visited,vector<string> &path,string output){
    
    if(i==row-1 && j==col-1) {
        path.push_back(output);
       
        return;
    }

    //down position  i+1,j
    if(isSafe(arr,row,col,i+1,j,visited)) {
        visited[i+1][j]=true;
        ratInMaze(arr,row,col,i+1,j,visited,path,output+" D ");
        //backtrack
        visited[i+1][j]=false;
    }

    //left position  i,j-1
        if(isSafe(arr,row,col,i,j-1,visited)) {
        visited[i][j-1]=true;
        ratInMaze(arr,row,col,i,j-1,visited,path,output+" L ");
        //backtrack
        visited[i][j-1]=false;
    }

    //right position  i,j+1
        if(isSafe(arr,row,col,i,j+1,visited)) {
        visited[i][j+1]=true;
        ratInMaze(arr,row,col,i,j+1,visited,path,output + " R ");
        //backtrack
        visited[i][j+1]=false;
    }

    //up position  i-1,j
        if(isSafe(arr,row,col,i-1,j,visited)) {
        visited[i-1][j]=true;
        ratInMaze(arr,row,col,i-1,j,visited,path,output + " U ");
        //backtrack
        visited[i-1][j]=false;
    }
}

int main() {

    vector<vector<int>> arr = {{1,0,0},
                               {1,1,1},
                               {1,1,1}};
    int row = arr.size();
    int col = arr[0].size();

   
  vector<vector<bool>> visited(row,vector<bool>(col,false));
  //src ki value k true mark kredete h 
  visited[0][0] = true;
    vector<string> path;
    string output = "";

    if(arr[0][0]==0) {
        cout<<"No path exists "<<endl;
        return 0;
    }

    // i & j are source position of maze
    int i=0;
    int j=0;

  
    ratInMaze(arr,row,col,i,j,visited,path,output);

    cout<<"Possible directions are "<<endl;
    for(auto i: path) {
    cout << i <<endl;;
  }

    if(path.size() == 0 ){
    cout << "No Path Exists " << endl;
    } else {
        cout<<"Total paths are "<<path.size()<<endl;
    }
 

    cout<<endl;
}