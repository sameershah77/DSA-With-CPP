#include <iostream>
#include<limits.h>
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

    int min = INT_MAX;
    int max = INT_MIN;
    
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j]>max) {
                max = arr[i][j];

            }

           
        }
    }
    cout<<"Maximum number is :- "<<max<<endl;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if(arr[i][j]<min) {
                min = arr[i][j];

            }

           
        }
    }

    cout<<"Minimum number is :- "<<min<<endl;
}