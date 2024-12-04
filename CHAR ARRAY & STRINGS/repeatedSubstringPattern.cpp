#include<iostream>
using namespace std;


// Given a string s, check if it can be constructed by taking a substring of it and appending multiple copies of the substring together.

 

// Example 1:

// Input: s = "abab"
// Output: true
// Explanation: It is the substring "ab" twice.
// Example 2:

// Input: s = "aba"
// Output: false
// Example 3:

// Input: s = "abcabcabcabc"
// Output: true
// Explanation: It is the substring "abc" four times or the substring "abcabc" twice.


    bool repeatedSubstringPattern(string s) {
        string temp= s+s;
        return temp.substr(1,temp.size()-2).find(s) != -1?true:false;
    }
    
int main() {


    cout<<repeatedSubstringPattern("abcabcabcabc");
}