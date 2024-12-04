#include<iostream>
#include<stack>
#include<string.h>
using namespace std;
// Given a string s, determine if it is valid.

// A string s is valid if, starting with an empty string t = "", you can transform t into s after performing the following operation any number of times:

// Insert string "abc" into any position in t. More formally, t becomes tleft + "abc" + tright, where t == tleft + tright. Note that tleft and tright may be empty.
// Return true if s is a valid string, otherwise, return false.

 

// Example 1:

// Input: s = "aabcbc"
// Output: true
// Explanation:
// "" -> "abc" -> "aabcbc"
// Thus, "aabcbc" is valid.
// Example 2:

// Input: s = "abcabcababcc"
// Output: true
// Explanation:
// "" -> "abc" -> "abcabc" -> "abcabcabc" -> "abcabcababcc"
// Thus, "abcabcababcc" is valid.
// Example 3:

// Input: s = "abccba"
// Output: false
// Explanation: It is impossible to get "abccba" using the operation.


    bool isValid(string s) {
        if(s[0] != 'a') return false;

        stack<char> st;
        for(auto ch:s) {
            if(ch == 'a') {
                st.push(ch);
            }
            else if(ch == 'b') {
                if(!st.empty() && st.top() == 'a') {
                    st.push(ch);
                }
                else {
                    return false;
                }
            }
            else {
                if(!st.empty() && st.top() == 'b') {
                    st.pop();
                    if(!st.empty() && st.top() == 'a') {
                        st.pop();
                    }
                    else {
                        return false;
                    }
                }
                else {
                    return false;
                }
            }
        }

        return st.empty()?true:false;
    }

int main() {
    string a = "aabcbc";

    if(isValid(a)) {
        cout<<a<<" is Valid"<<endl;
    }
    else {
        cout<<a<<" is Invalid"<<endl;
    }
    string b = "abcabcababcc";

    
    if(isValid(b)) {
        cout<<b<<" is Valid"<<endl;
    }
    else {
        cout<<b<<" is Invalid"<<endl;
    }
    string c = "abccba";

    
    if(isValid(c)) {
        cout<<c<<" is Valid"<<endl;
    }
    else {
        cout<<c<<" is Invalid"<<endl;
    }
}