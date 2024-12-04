#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
//T.C. N^3  

// Given a string s, return the longest 
// palindromic
 
// substring
//  in s.

 

// Example 1:

// Input: s = "babad"
// Output: "bab"
// Explanation: "aba" is also a valid answer.
// Example 2:

// Input: s = "cbbd"
// Output: "bb"
 

bool isPalindrome(string &s, int start, int end) {
    while(start < end) {
        if(s[start] != s[end]) {
            return false;
        }
        start++;
        end--;
    }
    return true;
}
    string longestPalindrome(string s) {
        string ans = "";

        for(int i=0; i<s.size(); i++) {
            for(int j=i; j<s.size(); j++) {
                if(isPalindrome(s,i,j)) {
                    string t = s.substr(i,j-i+1);
                    ans = t.size() > ans.size() ? t : ans;
                }
            }
        }
        return ans;
    }
int main() {
    string s;
    cout<<"ENter a string : ";
    cin>>s;

    string ans = longestPalindrome(s);

    cout<<"Logest palindromic substring in your string is "<<endl;
    cout<<ans;
}