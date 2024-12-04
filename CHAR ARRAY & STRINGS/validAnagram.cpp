#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

// Given two strings s and t, return true if t is an anagram of s, and false otherwise.

// An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.


    bool isAnagram(string s, string t) {
        // Method 1 using sorting
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // if(s==t) {
        //     return true;
        // }
        // else {
        //     return false;
        // }
        // return false;
        // Method 2
        // 256 becouse total number of ascii values is 256
        int freqTable[256] = {0};

        for(int i=0;i<s.size();i++) {
            freqTable[s[i]]++;
        }
        for(int i=0;i<t.size();i++) {
            freqTable[t[i]]--;
        }
        for(int i=0;i<256;i++) {
            if(freqTable[i] != 0) {
                return false;
            } 
        }
        return true;
    }
int main() {
    string s;
    string t;

    cout<<"Enter string 1 : "<<endl;
    cin>>s;
    cout<<"Enter string 2 : "<<endl;
    cin>>t;

    bool ans = isAnagram(s,t);
    if(ans){
        cout<<"Both the strings are anagram of each other "<<endl;
    }
    else {
        cout<<"Strings are not anagram of each other "<<endl;
    }




}