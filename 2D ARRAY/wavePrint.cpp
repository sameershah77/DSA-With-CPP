#include<iostream>
#include<vector>
using namespace std;

vector<int> wavePrint(vector<vector<int> > & matrix) {
    vector<int> arr;

    int row = matrix.size();
    int col = matrix[0].size();

    for(int startCol=0;startCol<col;startCol ++ ) {
        if(startCol%2==0) {
            for(int startRow = 0; startRow<row;startRow ++) {
                arr.push_back(matrix[startRow][startCol]);
            }
        }
        else {
            for(int startRow = row-1;startRow >=0; startRow--) {
                arr.push_back(matrix[startRow][startCol]);
            }
        }
    }
    return arr;
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

    cout<<"Your Wave print is :- "<<endl;

    vector <int> arr = wavePrint(matrix);

    for(int i=0;i<arr.size();i++) {
        cout<<arr[i]<<" -> ";
    }
    cout<<endl;

}