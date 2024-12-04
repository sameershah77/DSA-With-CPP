#include<iostream>
#include<string.h>
using namespace std;

// Given two strings s and t, return true if they are equal when both are typed into empty text editors. '#' means a backspace character.

// Note that after backspacing an empty text, the text will continue empty.

 

// Example 1:

// Input: s = "ab#c", t = "ad#c"
// Output: true
// Explanation: Both s and t become "ac".
// Example 2:

// Input: s = "ab##", t = "c#d#"
// Output: true
// Explanation: Both s and t become "".
// Example 3:

// Input: s = "a#c", t = "b"
// Output: false
// Explanation: s becomes "c" while t becomes "b".

    bool backspaceCompare(string s, string t) {
        string s1 = "";
        string s2 = "";

        int hash = 0;

        for(int i=s.size()-1; i>=0; i--) {
            if(s[i] == '#') {
                hash++;
            }
            if(s[i] != '#' && hash == 0) {
                s1 += s[i];
            }
            else if(s[i] != '#' && hash > 0) {
                hash--;
            }
        }
        hash = 0;
        for(int i=t.size()-1; i>=0; i--) {
            if(t[i] == '#') {
                hash++;
            }
            if(t[i] != '#' && hash == 0) {
                s2 += t[i];
            }
            else if(t[i] != '#' && hash > 0) {
                hash--;
            }
        }
        return s1 == s2;
    }
int main() {

    string s = "ab#c";
    string t = "ad#c";

    if(backspaceCompare(s,t)) {
        cout<<"Answer is True"<<endl;
    }
    else {
        cout<<"Answer is False"<<endl;
    }

}