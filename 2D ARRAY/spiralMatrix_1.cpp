#include<iostream>
#include<vector>
using namespace std;


// Given an m x n matrix, return all elements of the matrix in spiral order.

 

// Example 1:


// Input: matrix = [[1,2,3],[4,5,6],[7,8,9]]
// Output: [1,2,3,6,9,8,7,4,5]
// Example 2:


// Input: matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
   vector<int> spiralOrder(vector<vector<int>>& matrix) {
            vector<int> answer;

        int row = matrix.size();
        int col = matrix[0].size();
        
        int count = 0;
        int totalElement = row*col;

        //Index Initialising
        int startingRow = 0;
        int startingCol = 0;
        int endingRow = row - 1;
        int endingCol = col - 1;

        while(count < totalElement) {
            //print first row
            for(int index = startingCol;index <= endingCol && count < totalElement;index++) {
                answer.push_back(matrix[startingRow][index]);
                count++;
            }
            startingRow++;
            //print last coloumn
            for(int index = startingRow;index <= endingRow && count < totalElement;index++) {
                answer.push_back(matrix[index][endingCol]);
                count++;
            }
            endingCol--;

        //print last row
            for(int index = endingCol;index >= startingCol && count < totalElement;index-- ){
                answer.push_back(matrix[endingRow][index]);
                count++;
            }
            endingRow --;

              //print first coloumn
            for(int index = endingRow;index >= startingRow && count < totalElement;index-- ){
                answer.push_back(matrix[index][startingCol]);
                count++;
            }
            startingCol ++;
        }
        return answer;
    }

int main () {
    int row ;
    cout<<"Enter number of row :- ";
    cin>>row;
    cout<<"Enter number of colomn :- ";
    int col;
    cin>>col;
    cout<<"Insert the Elements in your "<<row<<" * "<<col<<" Matrix :- "<<endl;
    vector<vector<int>> matrix(row ,vector<int>(col));
    for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cin>>matrix[i][j];
        }
        cout<<endl;
    }

    cout<<"Your Matrix is looks like :- "<<endl;

      for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<"Your spiral print is :- "<<endl;

    vector <int> arr = spiralOrder(matrix);



    for(int i=0;i<arr.size();i++) {
        cout<<arr[i];
        if(i<arr.size()-1) {
            cout<<" -> ";
        }
    }
    cout<<endl;

}