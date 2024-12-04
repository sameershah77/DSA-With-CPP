#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

// Given an integer columnNumber, return its corresponding column title as it appears in an Excel sheet.

// For example:

// A -> 1
// B -> 2
// C -> 3
// ...
// Z -> 26
// AA -> 27
// AB -> 28 
// ...
 

// Example 1:

// Input: columnNumber = 1
// Output: "A"

// Example 2:

// Input: columnNumber = 28
// Output: "AB"

// Example 3:

// Input: columnNumber = 701
// Output: "ZY"

    string convertToTitle(int col) {
        string ans ="";
        while(col>0) {
            int rem = (col-1)%26;
            ans += char(rem) + 'A';
            col = (col-1)/26;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
int main() {

    int n;
    cout<<"Enter a number :- ";
    cin>>n;

    string ans = convertToTitle(n);
    cout<<ans<<endl;

}