#include<iostream>
#include<vector>
using namespace std;

// An integer has sequential digits if and only if each digit in the number is one more than the previous digit.

// Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.

// Example 1:

// Input: low = 100, high = 300
// Output: [123,234]
// Example 2:

// Input: low = 1000, high = 13000
// Output: [1234,2345,3456,4567,5678,6789,12345]

    vector<int> sequentialDigits(int low, int high) {
        vector<int> ans;

        string temp = "123456789";

        for(int i=0; i<9; i++) {
            for(int j=i+1; j<=9; j++) {
                int digit = stoi(temp.substr(i,j-i));
                if(low <= digit && digit <= high) {
                    ans.push_back(digit);
                }
            }
        }
        sort(ans.begin(), ans.end());
        return ans;
    }

int main() {

    int low = 100;
    int high = 400;

    vector<int> ans = sequentialDigits(low,high);

    cout<<"Answer is "<<endl;

    for(auto val: ans) {
        cout<<val<<" ";
    }

    cout<<endl;

}