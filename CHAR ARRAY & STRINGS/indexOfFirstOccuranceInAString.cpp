#include<iostream>
#include<string.h>
using namespace std;

// Given two strings needle and haystack, return the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.



// Example 1:

// Input: haystack = "sadbutsad", needle = "sad"
// Output: 0
// Explanation: "sad" occurs at index 0 and 6.
// The first occurrence is at index 0, so we return 0.


// Example 2:

// Input: haystack = "leetcode", needle = "leeto"
// Output: -1
// Explanation: "leeto" did not occur in "leetcode", so we return -1.

    int strStr(string haystack, string needle) {

        int n = haystack.find(needle);
        if(n>=0) {
            return n;
        }    
       
        return -1;
    }

int main() {

    string haystack;
    string needle;

    cout<<"Enter haystack: ";
    cin>>haystack;

    cout<<"Enter needle: ";
    cin>>needle;

    int index = strStr(haystack,needle);

    if(index>=0) 
        cout<<"String found at "<<index<<endl;
    else 
        cout<<"Not found "<<endl;
}