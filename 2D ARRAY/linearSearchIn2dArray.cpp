#include <iostream>
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

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    cout << "Enter element to be search : ";
    int search;
    cin >> search;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {

            if (arr[i][j] == search)
            {
                cout << "Element Found at "
                     << "(" << i + 1 << "," << j + 1 << ")" << endl;
            }
            else {
                cout<<"Element is not present"<<endl;
            }
        }
    }
}