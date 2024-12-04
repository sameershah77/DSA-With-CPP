#include<iostream>
#include<string.h>
#include<vector>
using namespace std;

// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)

// P   A   H   N
// A P L S I I G
// Y   I   R
// And then read line by line: "PAHNAPLSIIGYIR"

// Write the code that will take a string and make this conversion given a number of rows:

// string convert(string s, int numRows);
 

// Example 1:

// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"

// Example 2:

// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
// P     I    N
// A   L S  I G
// Y A   H R
// P     I

// Example 3:

// Input: s = "A", numRows = 1
// Output: "A"

    string convert(string s, int numRows) {
        int i=0;
        int row = 0;
        string ans = "";
        bool direction = true;
        vector<string> zigzag(numRows);
        if(numRows==1) {
            return s; 
        }

        while(true) {
            if(direction==true) {
                while(row < numRows && i < s.size()) {
                    zigzag[row].push_back(s[i]);
                    row++;
                    i++;
                }
                row = numRows - 2;
            }
            else {
                while(row >=0 && i < s.size()) {
                    zigzag[row].push_back(s[i]);
                    row--;
                    i++;
                }
                row=1;
            }

            if(i>=s.size()) {
                break;
            }

            direction = !direction;
            
        }
        for(int i=0;i<zigzag.size();i++) {
            ans += zigzag[i];
        }

        return ans;
    }
int main() {

    string s;
    cout<<"Enter string : ";
    cin>>s;

    int numRows;
    cout<<"Enter no. of rows : ";
    cin>>numRows;

    string ans  = convert(s,numRows);

    cout<<ans<<endl;

}