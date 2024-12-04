
#include <iostream>
using namespace std;

int main() {

    int n, m;
    cout << "Enter the Rows of Matrix : " << endl;
    cin >> n;
    cout << endl;
    cout << "Enter the Coloumns of Matrix : " << endl;
    cin >> m;
    int arr[n][m];
    cout << "Enter the elements of Matrix " << endl;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
        cout << endl;
    }

    /// Printing 2D Array
    cout << "Printing Row wise" << endl
         << endl
         << endl;

    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = 0; j < m; j++) {
            cout << arr[i][j] << " ";
            sum += arr[i][j];
        }
        cout << "Sum is ";
        cout << sum << endl;
    }
    cout << endl;

    cout << "Printing Coloumn wise" << endl
         << endl
         << endl;

    for (int i = 0; i < m; i++) {
        int sum = 0;
        for (int j = 0; j < n; j++) {
            cout << arr[j][i] << " ";
            sum += arr[j][i];
        }
        cout << "Sum is ";
        cout << sum << endl;
    }

    cout << endl;
}