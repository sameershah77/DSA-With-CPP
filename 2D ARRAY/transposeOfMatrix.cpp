#include<iostream>
using namespace std;

int main()
{

    int n, m;
    cout << "Enter the Rows and Coloumns of Matrix : " << endl;
    cin >> n;
    cout << endl;
    cin >> m;
    int arr[n][m];
    cout << "Enter the elements of Matrix " << endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> arr[i][j];
        }
        cout << endl;
    }

    /// Printing 2D Array
    cout<<"Your Original matrix is "<<endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout<<"Your Transpose matrix is "<<endl;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[j][i] << " ";
        }
        cout << endl;
    }

    

}