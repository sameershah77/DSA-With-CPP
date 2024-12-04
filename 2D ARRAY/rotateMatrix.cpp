#include<iostream>
#include<vector>
using namespace std;

void rotate(vector<vector<int>> &arr,int row,int col){

    int size = arr[0].size();
                    int i=0;
                int j=size-1;

        for(int i=0;i<row;i++) {
            for(int j=0;j<i;j++) {
                int temp = arr[i][j];
                arr[i][j] = arr[j][i];
                arr[j][i] = temp;
            }
        }
        for(int i=0; i<size; i++) {
            for(int j=0; j<size/2; j++) {
                 int temp = arr[i][size-1-j];
                arr[i][size-1-j] = arr[i][j];
                arr[i][j] =temp;
            
            }
        }
}
int main() {
    int row;
    int col;
    cout<<"Enter the row number :- ";
    cin>>row;
    cout<<"Enter the coloumn value :- ;";
    cin>>col;
    vector<vector<int>> arr (row,vector<int>(col));

    cout<<"Inter Elements in array :- "<<endl;
     for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cin>>arr[i][j];
        }cout<<endl;  
    }

        cout<<"Your original matrix is "<<endl;
      for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cout<<arr[i][j]<<" ";
        }cout<<endl; 
    }

    rotate(arr,row,col);


     cout<<"Your rotated matrix is "<<endl;
      for(int i=0;i<row;i++) {
        for(int j=0;j<col;j++) {
            cout<<arr[i][j]<<" ";
        }cout<<endl; 
    }

}