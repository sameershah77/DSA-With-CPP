#include<iostream>
#include<vector>
using namespace std;


// Given a positive integer n, generate an n x n matrix filled with elements from 1 to n2 in spiral order.

 

// Example 1:


// Input: n = 3
// Output: [[1,2,3],[8,9,4],[7,6,5]]
// Example 2:

// Input: n = 1
// Output: [[1]]
    vector<vector<int>> generateMatrix(int n) {
        vector<int> answer;
        for(int i=1; i<=n*n; i++) {
            answer.push_back(i);
        }
        vector<vector<int>> matrix(n,vector<int>(n,-1));

        int row = n;
        int col = n;
        
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
                matrix[startingRow][index] = answer[count];
                count++;
            }
            startingRow++;
            //print last coloumn
              for(int index = startingRow;index <= endingRow && count < totalElement;index++) {
                matrix[index][endingCol] = answer[count];
                count++;
            }
            endingCol--;


        //print last row
            for(int index = endingCol;index >= startingCol && count < totalElement;index-- ){
                matrix[endingRow][index]= answer[count];
                count++;
            }
            endingRow --;

              //print first coloumn
            for(int index = endingRow;index >= startingRow && count < totalElement;index-- ){
                matrix[index][startingCol]= answer[count];
                count++;
            }
            startingCol ++;
        }
    return matrix;
    }

int main () {
    int n ;
    cout<<"Enter number of row and col in n :- ";
    cin>>n;

    cout<<"Your spiral matrix is :- "<<endl;

    vector<vector<int>> matrix = generateMatrix(n);

    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;

}