#include<iostream>
#include<vector>
using namespace std;

// You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:

// A stone '#'
// A stationary obstacle '*'
// Empty '.'
// The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions.

// It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box.

// Return an n x m matrix representing the box after the rotation described above.

 

// Example 1:



// Input: box = [["#",".","#"]]
// Output: [["."],
//          ["#"],
//          ["#"]]
// Example 2:



// Input: box = [["#",".","*","."],
//               ["#","#","*","."]]
// Output: [["#","."],
//          ["#","#"],
//          ["*","*"],
//          [".","."]]
// Example 3:



// Input: box = [["#","#","*",".","*","."],
//               ["#","#","#","*",".","."],
//               ["#","#","#",".","#","."]]
// Output: [[".","#","#"],
//          [".","#","#"],
//          ["#","#","*"],
//          ["#","*","."],
//          ["#",".","*"],
//          ["#",".","."]]


    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
     for(int i=0;i<box.size();i++){
         int j = box[i].size()-1;
         int mx = j;
         while(j >= 0) {
             if(box[i][j] == '#'){
                 if(j < mx){
                 box[i][j]  = '.'; 
                 box[i][mx] = '#';
                 mx = mx-1;
                }
                 else
                     mx--;
             }    
             else if(box[i][j] == '*' && j > 0)
                 mx = j-1;
             j--;
         }
     }
     vector<vector<char>> ans(box[0].size(),vector<char>(box.size()));
     for(int i=0;i<box[0].size();i++){
         for(int j=0;j<box.size();j++){
             ans[i][j] = box[box.size()-1-j][i];
         }
     }
     return ans;   
    }
int main() {
    vector<int> box = {{"#",".","#"}};

    box = rotateTheBox(box);

    cout<<"Answer is "<<endl;


    for(auto val: box) {
        for(auto i: val){
            cout<<i<<" ";
        }
        cout<<endl;
    }

}