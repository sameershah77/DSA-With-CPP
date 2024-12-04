#include <iostream>
#include <vector>
#include <limits>
using namespace std;
vector<int> intersection(vector<int> ans, vector<int> arr1, vector<int> arr2, int n, int m)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (arr1[i] == arr2[j])
            {
                arr2[j] = -1;
                ans.push_back(arr1[i]);
            }
        }
    }
    return ans;
}

int main()
{
    int n;
    int m;
    cout << "Enter the size of Firts Array :-";
    cin >> n;
    cout << "Enter the size of Second Array :-";
    cin >> m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    cout << "Enter the elements of Firts Array :- " << endl;
    for (int i = 0; i < arr1.size(); i++)
    {
        cin >> arr1[i];
    }
    cout << "Enter the elements of Second Array :- " << endl;
    for (int i = 0; i < arr2.size(); i++)
    {
        cin >> arr2[i];
    }
    vector<int> ans(n);
    vector<int> result(n);
    result = intersection(ans, arr1, arr2, n, m);
    cout << "Intersection is :- ";
    for (int i = 0; i < result.size(); i++)
    {
        cout << result[i] << " ";
    }
    cout << endl;
}
